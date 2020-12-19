#ifndef _RADIO_H_
#define _RADIO_H_

#include "PhysicalLayerModel_ext.h"
#include "CircularBuffer.h"
#include "Transmitter.h"
#include "Receiver.h"
#include "Frame.h"
#include <iostream>
#include <fstream>
#include "Crc.h"

namespace PhysicalLayerNative
{
	class Radio
	{
		friend class Receiver;
	private:

		const int RECEIVE_BUFFER_SIZE = 65536;
		const int SEND_BUFFER_SIZE = 65536;

		CircularBuffer* _receiveBuffer;
		CircularBuffer* _sendBuffer;

		Transmitter* _transmitter;
		Receiver* _receiver;

		void Receive(Frame frame);
		void ConvertToNibbles(uint8_T* serializedFrame, uint8_T data[FRAME_SYMBOLS_SIZE]);
		void Process();
		int MakeFrames(uint8_T**, uint16_T address, uint8_T*, int, int);
		void ExtractData(uint8_T*, Frame frame);

		std::ofstream _sendLogFileStream;
		std::ofstream _receiveLogFileStream;

		unsigned short _address;
		Crc* _crc;

	public:

		Radio();
		~Radio();

		virtual void Step();

		// Send Frame
		void Send(unsigned short address, uint8_T* buffer, int offset, int length);

		// Receive data
		int Read(uint8_T* buffer, int offset, int length);

		void SetTransmitter(Transmitter* transmitter);
		Transmitter* GetTransmitter();

		void SetReceiver(Receiver* receiver);
		Receiver* GetReceiver();

		// Sets Send Log File
		void SetSendLogFile(char* fileName);

		// Sets Receive Log File
		void SetReceiveLogFile(char* fileName);

		// Data received
		int Available();

		// Data to send
		int Buffered();

		void SetLocalAddress(unsigned short);
		unsigned short GetLocalAddress();

	};

}

#endif