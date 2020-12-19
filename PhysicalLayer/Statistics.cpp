#include "Statistics.h"

PhysicalLayerNative::Statistics::Statistics(B_Statistics_PhysicalLayerMo_T* block, DW_Statistics_PhysicalLayerM_T* state)
{
	_block = block;
	_state = state;
	_compute = false;
}

PhysicalLayerNative::Statistics::~Statistics()
{
}

void PhysicalLayerNative::Statistics::WriteTx(uint8_T symbols[FRAME_SYMBOLS_SIZE])
{
	for (int i = 0; i < FRAME_SYMBOLS_SIZE; i++)
	{
		_tx[i] = symbols[i];
	}
	_compute = true;
}

void PhysicalLayerNative::Statistics::WriteRx(uint8_T symbols[FRAME_SYMBOLS_SIZE])
{
	for (int i = 0; i < FRAME_SYMBOLS_SIZE; i++)
	{
		_rx[i] = symbols[i];
	}
}

void PhysicalLayerNative::Statistics::Step()
{
	if (_compute)
	{
		PhysicalLayerModel_Statistics(_tx, _rx, _block, _state);
		_state->symbols -= SYSTEM_DELAY;
		_compute = false;
	}
}

real_T PhysicalLayerNative::Statistics::GetErrorRate()
{
	return _block->ErrorRateCalculation[0U];
}

real_T PhysicalLayerNative::Statistics::GetErrors()
{
	return _block->ErrorRateCalculation[1U];
}

real_T PhysicalLayerNative::Statistics::GetSymbols()
{
	return _block->ErrorRateCalculation[2U];
}

char* PhysicalLayerNative::Statistics::ToString()
{
	char* buffer = new char[100];
	sprintf(buffer, "ErrorRate:%f, Errors:%f, Symbols:%f", GetErrorRate(), GetErrors(), GetSymbols());
	return buffer;
}