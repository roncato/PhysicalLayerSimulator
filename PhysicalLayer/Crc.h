#ifndef _CRC_H_
#define _CRC_H_

#include "PhysicalLayerModel_ext.h"

#define WIDTH  (8 * sizeof(uint16_T))
#define TOPBIT (1 << (WIDTH - 1))
#define POLYNOMIAL 0x8005

class Crc
{
private:
	uint16_T _crcTable[256];
	void Initialize();
public:
	Crc();
	uint16_T Crc::Calculate(uint8_T const message[], int, int);
};

#endif