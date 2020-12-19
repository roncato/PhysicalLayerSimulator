#include "Crc.h"

Crc::Crc()
{
	Initialize();
}

void Crc::Initialize(void)
{
	uint16_T remainder;

	/*
	* Compute the remainder of each possible dividend.
	*/
	for (int dividend = 0; dividend < 256; ++dividend)
	{
		/*
		* Start with the dividend followed by zeros.
		*/
		remainder = dividend << (WIDTH - 8);

		/*
		* Perform modulo-2 division, a bit at a time.
		*/
		for (uint8_T bit = 8; bit > 0; --bit)
		{
			/*
			* Try to divide the current data bit.
			*/
			if (remainder & TOPBIT)
			{
				remainder = (remainder << 1) ^ POLYNOMIAL;
			}
			else
			{
				remainder = (remainder << 1);
			}
		}

		/*
		* Store the result into the table.
		*/
		_crcTable[dividend] = remainder;
	}
}

uint16_T
Crc::Calculate(uint8_T const message[], int offset, int length)
{
	uint8_T data;
	uint16_T remainder = 0;


	/*
	* Divide the message by the polynomial, a byte at a time.
	*/
	for (int byte = 0; byte < length; ++byte)
	{
		data = message[offset + byte] ^ (remainder >> (WIDTH - 8));
		remainder = _crcTable[data] ^ (remainder << 8);
	}

	/*
	* The final remainder is the CRC.
	*/
	return (remainder);

}   /* crcFast() */