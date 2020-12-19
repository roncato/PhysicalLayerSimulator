#ifndef _CIRCULARBUFFER_H_
#define _CIRCULARBUFFER_H_

#include "PhysicalLayerModel_ext.h"
#include <iostream>
#include <fstream>

class CircularBuffer
{
private:

	int const SLEEP_TIME = 1;
	int const TRIES_THRESHOLD = 100;

	uint8_T* _arr;
	int _size;
	int _position;
	int _writePosition;
	int _readPosition;

public:

	CircularBuffer(int size);
	~CircularBuffer();

	// Writes to buffer
	void Write(uint8_T* data, int offset, int length);

	// Reads from buffer
	int Read(uint8_T* data, int offset, int length);

	// Returns available data in buffer
	int Available();

};

#endif