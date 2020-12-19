#include "CircularBuffer.h"
#include "Windows.h"

CircularBuffer::CircularBuffer(int size)
{
	_size = size;
	_arr = new uint8_T[_size];
	_writePosition = 0;
	_readPosition = 0;
}

CircularBuffer::~CircularBuffer()
{
	delete _arr;
}

void CircularBuffer::Write(uint8_T* data, int offset, int length)
{
	for (int i = 0; i < length; i++)
	{
		_arr[_writePosition] = data[offset + i];
		_writePosition++;
		if (_writePosition >= _size)
		{
			_writePosition = 0;
		}
	}
}

int CircularBuffer::Read(uint8_T* data, int offset, int length)
{
	int reads = 0;
	int tries = 0;
	while (true)
	{
		if (Available() > 0)
		{
			for (int i = 0; (i < length); i++)
			{
				data[offset + i] = _arr[_readPosition++];
				if (_readPosition >= _size)
				{
					_readPosition = 0;
				}
				reads++;
				if (_readPosition == _writePosition)
				{
					break;
				}
			}
			break;
		}
		tries++;
		if (tries == TRIES_THRESHOLD)
		{
			Sleep(SLEEP_TIME);
			tries = 0;
		}
	}
	return reads;
}

int CircularBuffer::Available()
{
	int aval = _writePosition - _readPosition;
	if (aval < 0)
	{
		aval += _size;
	}
	return aval;
}