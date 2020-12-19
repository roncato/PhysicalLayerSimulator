#ifndef _STATISTICS_H_
#define _STATISTICS_H_

#include "PhysicalLayerModel_ext.h"
#include <stdio.h>

namespace PhysicalLayerNative
{
	class Statistics
	{
	private:

		uint8_T _tx[FRAME_SYMBOLS_SIZE];
		uint8_T _rx[FRAME_SYMBOLS_SIZE];

		B_Statistics_PhysicalLayerMo_T* _block;
		DW_Statistics_PhysicalLayerM_T* _state;
		bool _compute;

	public:

		Statistics(B_Statistics_PhysicalLayerMo_T* block, DW_Statistics_PhysicalLayerM_T* state);
		~Statistics();

		// Writes Transmitted Symbols
		void WriteTx(uint8_T symbols[FRAME_SYMBOLS_SIZE]);

		// Writes Received Symbols
		void WriteRx(uint8_T symbols[FRAME_SYMBOLS_SIZE]);

		// Calculate Statistics
		void Step();

		real_T GetErrorRate();
		real_T GetErrors();
		real_T GetSymbols();

		char* Statistics::ToString();

	};

}

#endif