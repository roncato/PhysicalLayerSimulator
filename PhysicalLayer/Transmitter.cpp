#include "Transmitter.h"
#include "Channel.h"

PhysicalLayerNative::Transmitter::Transmitter(Channel* channel,
	B_Transmitter_PhysicalLayerMo_T* block,
	DW_Transmitter_PhysicalLayerM_T* state,
	P_Transmitter_PhysicalLayerMo_T* params)
{
	_channel = channel;
	_block = block;
	_state = state;
	_params = params;
	_stats = NULL;
}

void PhysicalLayerNative::Transmitter::Transmit(uint8_T data[NET_FRAME_SYMBOLS_SIZE])
{
	uint8_T symbols[FRAME_SYMBOLS_SIZE];
	PadSymbols(data, symbols);
	if (_stats != NULL)
	{
		_stats->WriteTx(symbols);
	}
	PhysicalLayerModel_Transmitter(symbols, _block, _state, _params);
	_channel->Transmit(_block->ComplextoRealImag);
}

void PhysicalLayerNative::Transmitter::SetStatistics(Statistics* stats)
{
	_stats = stats;
}

PhysicalLayerNative::Statistics* PhysicalLayerNative::Transmitter::GetStatistics()
{
	return _stats;
}

void PhysicalLayerNative::Transmitter::PadSymbols(uint8_T data[NET_FRAME_SYMBOLS_SIZE], uint8_T symbols[FRAME_SYMBOLS_SIZE])
{
	for (size_t i = 0; i < FRAME_SYMBOLS_SIZE; i++)
	{
		symbols[i] = 0;
	}
	for (size_t i = 0; i < NET_FRAME_SYMBOLS_SIZE; i++)
	{
		symbols[i] = data[i];
	}
}

void PhysicalLayerNative::Transmitter::SetCarrierFrequency(real_T frequency)
{
	_params->UpfrequencyOscillator_Frequency = frequency;
}

real_T PhysicalLayerNative::Transmitter::GetCarrierFrequency()
{
	return _params->UpfrequencyOscillator_Frequency;
}

void PhysicalLayerNative::Transmitter::SetPower(real_T power)
{
	_params->TransmissionPower = power;
}

real_T PhysicalLayerNative::Transmitter::GetPower()
{
	return _params->TransmissionPower;
}

void PhysicalLayerNative::Transmitter::SetModulationType(ModulationType type)
{
	_params->ModulationType_Value = type;
}

PhysicalLayerNative::ModulationType PhysicalLayerNative::Transmitter::GetModulationType()
{
	return (ModulationType)_params->ModulationType_Value;
}

void PhysicalLayerNative::Transmitter::SetBandwith(real_T width)
{
	_params->Bandwidth = width;
}

real_T PhysicalLayerNative::Transmitter::GetBandwith()
{
	return _params->Bandwidth;
}