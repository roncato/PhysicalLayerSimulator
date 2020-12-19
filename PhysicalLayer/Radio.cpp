#include "Radio.h"
#include "Channel.h"

PhysicalLayerNative::Radio::Radio()
{
	_transmitter = NULL;
	_receiver = NULL;
	_receiveBuffer = new CircularBuffer(RECEIVE_BUFFER_SIZE);
	_sendBuffer = new CircularBuffer(SEND_BUFFER_SIZE);
	_address = 0;
	_crc = new Crc();
}

PhysicalLayerNative::Radio::~Radio()
{
	if (_sendLogFileStream.is_open())
	{
		_sendLogFileStream.close();
	}
	if (_receiveLogFileStream.is_open())
	{
		_receiveLogFileStream.close();
	}
	delete _receiveBuffer;
	delete _sendBuffer;
	delete _crc;
}

void PhysicalLayerNative::Radio::Step()
{
	Process();
}

void PhysicalLayerNative::Radio::Process()
{
	uint8_T serializeFrame[FRAME_SIZE];
	uint8_T data[FRAME_SYMBOLS_SIZE];
	if (_sendBuffer->Available() >= FRAME_SIZE)
	{
		_sendBuffer->Read(serializeFrame, 0, FRAME_SIZE);
		ConvertToNibbles(serializeFrame, data);
		_transmitter->Transmit(data);
	}
}

void PhysicalLayerNative::Radio::ConvertToNibbles(uint8_T* serializeFrame, uint8_T data[FRAME_SYMBOLS_SIZE])
{
	size_t offset = 0;
	for (size_t i = 0; i < FRAME_SIZE + (SYSTEM_DELAY / 2); i++)
	{
		if (i < FRAME_SIZE)
		{
			uint8_T byte = serializeFrame[i];
			uint8_T nibble1 = byte & 0x0F;
			uint8_T nibble2 = (byte >> 4) & 0x0F;
			data[offset] = nibble1;
			data[offset + 1] = nibble2;
		}
		else
		{
			data[offset] = 0;
			data[offset + 1] = 0;
		}
		offset += 2;
	}
}

void PhysicalLayerNative::Radio::Send(uint16_T address, uint8_T* buffer, int offset, int length)
{
	uint8_T* data;
	int len = MakeFrames(&data, address, buffer, offset, length);
	_sendBuffer->Write(data, 0, len);
	if (_sendLogFileStream.is_open())
	{
		for (int i = 0; i < length; i++)
		{
			_sendLogFileStream << (int32_T)buffer[offset + i] << std::endl;
		}
	}
}

int PhysicalLayerNative::Radio::Read(uint8_T* buffer, int offset, int length)
{
	return _receiveBuffer->Read(buffer, offset, length);
}

void PhysicalLayerNative::Radio::Receive(Frame frame)
{
	if (frame.DestinationAddress == _address)
	{
		// Checks CRC and
		if (frame.CRC == _crc->Calculate((uint8_T*)&frame, 0, frame.Length + 6))
		{
			uint8_T* data = new uint8_T[frame.Length];
			ExtractData(data, frame);
			_receiveBuffer->Write(data, 0, frame.Length);
			if (_receiveLogFileStream.is_open())
			{
				for (int i = 0; i < frame.Length; i++)
				{
					_receiveLogFileStream << (int32_T)frame.Payload[i] << std::endl;
				}
			}
			delete data;
		}
		else
		{
			if (_receiveLogFileStream.is_open())
			{
				_receiveLogFileStream << "Frame dropped." << std::endl;
			}
		}
	}
}

void PhysicalLayerNative::Radio::SetTransmitter(Transmitter* transmitter)
{
	_transmitter = transmitter;
}

PhysicalLayerNative::Transmitter* PhysicalLayerNative::Radio::GetTransmitter()
{
	return _transmitter;
}

void PhysicalLayerNative::Radio::SetReceiver(Receiver* receiver)
{
	_receiver = receiver;
}

PhysicalLayerNative::Receiver* PhysicalLayerNative::Radio::GetReceiver()
{
	return _receiver;
}

void PhysicalLayerNative::Radio::SetSendLogFile(char* fileName)
{
	if (_sendLogFileStream.is_open())
	{
		_sendLogFileStream.close();
	}
	if (fileName != NULL)
	{
		_sendLogFileStream.open(fileName);
	}
}

void PhysicalLayerNative::Radio::SetReceiveLogFile(char* fileName)
{
	if (_receiveLogFileStream.is_open())
	{
		_receiveLogFileStream.close();
	}
	if (fileName != NULL)
	{
		_receiveLogFileStream.open(fileName);
	}
}

int PhysicalLayerNative::Radio::Available()
{
	return _receiveBuffer->Available();
}

int PhysicalLayerNative::Radio::Buffered()
{
	return _sendBuffer->Available();
}

int PhysicalLayerNative::Radio::MakeFrames(uint8_T** dataAddress, unsigned short address, uint8_T* buffer, int offset, int length)
{
	size_t payloads = ceil(double(length) / FRAME_PAYLOAD_SIZE);
	size_t buffSize = payloads * FRAME_SIZE;
	uint8_T* data = new uint8_T[buffSize];
	*dataAddress = data;
	size_t bufferOffset = 0;

	for (size_t i = 0; i < length; i += FRAME_SIZE)
	{
		uint16_T payloadLength = 0;
		bufferOffset = FRAME_PAYLOAD_SIZE * ceil(double(i) / FRAME_SIZE);
		int remaining = length - bufferOffset;
		if (remaining < FRAME_PAYLOAD_SIZE)
		{
			payloadLength = remaining;
		}
		else
		{
			payloadLength = FRAME_PAYLOAD_SIZE;
		}

		// Local Address
		data[i + 0] = _address & 0xFF;
		data[i + 1] = (_address >> 8) & 0xFF;

		// Remote Address
		data[i + 2] = address & 0x0F;
		data[i + 3] = (address >> 8) & 0xFF;

		data[i + 4] = (uint8_T)FrameType::Data;
		data[i + 5] = payloadLength;

		for (uint8_T j = 0; j < FRAME_PAYLOAD_SIZE; j++)
		{
			if (j < payloadLength)
			{
				data[i + j + 6] = buffer[offset + bufferOffset + j];
			}
			else
			{
				data[i + j + 6] = 0;
			}
		}
		uint16_T crc = _crc->Calculate(data, i, payloadLength + 6);
		data[i + FRAME_SIZE - sizeof(uint16_T)] = crc & 0xFF;
		data[i + FRAME_SIZE - sizeof(uint16_T) + 1] = (crc >> 8) & 0xFF;
	}

	return buffSize;
}

void PhysicalLayerNative::Radio::ExtractData(uint8_T* data, Frame frame)
{
	for (uint8_T i = 0; i < frame.Length; i++)
	{
		data[i] = frame.Payload[i];
	}
}

void PhysicalLayerNative::Radio::SetLocalAddress(unsigned short address)
{
	_address = address;
}

unsigned short PhysicalLayerNative::Radio::GetLocalAddress()
{
	return _address;
}