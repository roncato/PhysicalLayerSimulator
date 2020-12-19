#include "Receiver.h"
#include "Radio.h"

PhysicalLayerNative::Receiver::Receiver(Radio* radio,
					B_Receiver_PhysicalLayerModel_T *block,
					DW_Receiver_PhysicalLayerMode_T *state,
					P_Receiver_PhysicalLayerModel_T *params)
{
	_radio = radio;
	_block = block;
	_state = state;
	_params = params;
	_stats = NULL;
	_delay = DEFAULT_DELAY;
}

void PhysicalLayerNative::Receiver::Receive(real_T signal[SIGNAL_SIZE])
{
	PhysicalLayerModel_Receiver(signal, _block, _state, _params);
	Frame frame;
	FillFrame(_block->MultiportSwitch, &frame);
	if (_stats != NULL)
	{
		_stats->WriteRx(_block->MultiportSwitch);
	}
	_radio->Receive(frame);
}

void PhysicalLayerNative::Receiver::FillFrame(uint8_T symbols[FRAME_SYMBOLS_SIZE], Frame* frame)
{
	size_t offset = 0;
	int32_T nibble1;
	int32_T nibble2;
	uchar_T byte;
	size_t index = 0;
	size_t dataDelay = _delay / 2;
	size_t currDelayed = 0;
	uint8_T* rawFrame = (uint8_T*)frame;
	for (int i = 0; i < FRAME_SIZE + dataDelay; i++)
	{
		if (currDelayed >= dataDelay)
		{
			nibble1 = symbols[offset] & 0x0F;
			nibble2 = symbols[offset + 1] & 0x0F;
			byte = nibble1 | (nibble2 << 4);
			rawFrame[index] = byte;
			index++;
		}
		else
		{
			currDelayed++;
		}
		offset += 2;
	}
}

void PhysicalLayerNative::Receiver::SetStatistics(Statistics* stats)
{
	_stats = stats;
}

PhysicalLayerNative::Statistics* PhysicalLayerNative::Receiver::GetStatistics()
{
	return _stats;
}

void PhysicalLayerNative::Receiver::SetDelay(int delay)
{
	_delay = delay;
}

int PhysicalLayerNative::Receiver::GetDelay()
{
	return _delay;
}

void PhysicalLayerNative::Receiver::SetCarrierFrequency(real_T frequency)
{
	_params->DownfrequencyOscillator_Frequen = frequency;
}

real_T PhysicalLayerNative::Receiver::GetCarrierFrequency()
{
	return _params->DownfrequencyOscillator_Frequen;
}

void PhysicalLayerNative::Receiver::SetPower(real_T power)
{
	_params->ReceiverPower = power;
}

real_T PhysicalLayerNative::Receiver::GetPower()
{
	return _params->ReceiverPower;
}

void PhysicalLayerNative::Receiver::SetModulationType(ModulationType type)
{
	_params->ModulationType_Value = type;
}

PhysicalLayerNative::ModulationType PhysicalLayerNative::Receiver::GetModulationType()
{
	return (ModulationType)_params->ModulationType_Value;
}

void PhysicalLayerNative::Receiver::SetBandwith(real_T width)
{
	_params->Bandwidth = width;
}

real_T PhysicalLayerNative::Receiver::GetBandwith()
{
	return _params->Bandwidth;
}