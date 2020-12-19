#include "Channel.h"

PhysicalLayerNative::Channel::Channel(
	B_Channel_PhysicalLayerModel_T *block,
	DW_Channel_PhysicalLayerMode_T *state,
	P_Channel_PhysicalLayerModel_T *params)
{
	_block = block;
	_state = state;
	_params = params;	
}

PhysicalLayerNative::Channel::~Channel()
{
	_receivers.clear();
}

void PhysicalLayerNative::Channel::AddReceiver(Receiver* receiver)
{
	_receivers.push_back(receiver);
}

void PhysicalLayerNative::Channel::Transmit(real_T signal[SIGNAL_SIZE])
{
	PhysicalLayerModel_Channel(signal, _block, _state, _params);
	for (size_t i = 0; i < _receivers.size(); i++)
	{
		_receivers[i]->Receive(_block->DynamicAWGN);
	}
}

void PhysicalLayerNative::Channel::SetInterferenceAmplitude(real_T a)
{
	_params->InterfererTone_Amplitude = a;
}

real_T PhysicalLayerNative::Channel::GetInterferenceAmplitude()
{
	return _params->InterfererTone_Amplitude;
}

void PhysicalLayerNative::Channel::SetInterferenceFrequency(real_T f)
{
	_params->InterfererTone_Frequency = f;
}

real_T PhysicalLayerNative::Channel::GetInterferenceFrequency()
{
	return _params->InterfererTone_Frequency;
}

void PhysicalLayerNative::Channel::SetInterferencePhase(real_T p)
{
	_params->InterfererTone_Phase = p;
}

real_T PhysicalLayerNative::Channel::GetInterferencePhase()
{
	return _params->InterfererTone_Phase;
}

void PhysicalLayerNative::Channel::SetAWGNSeed(uint32_T seed)
{
	_params->DynamicAWGN_Seed = seed;
}

uint32_T PhysicalLayerNative::Channel::GetAWGNSeed()
{
	return _params->DynamicAWGN_Seed;
}

void PhysicalLayerNative::Channel::SetSNR(real_T snr)
{
	_params->DynamicAWGN_SNR = snr;
	RefreshChannel();
}

real_T PhysicalLayerNative::Channel::GetSNR()
{
	return _params->DynamicAWGN_SNR;
}

void PhysicalLayerNative::Channel::SetInputSignalPower(real_T spow)
{
	_params->DynamicAWGN_SPOW = spow;
	RefreshChannel();
}

real_T PhysicalLayerNative::Channel::GetInputSignalPower()
{
	return _params->DynamicAWGN_SPOW;
}

void PhysicalLayerNative::Channel::SetBandwith(real_T width)
{
	_params->Bandwidth = width;
}

real_T PhysicalLayerNative::Channel::GetBandwith()
{
	return _params->Bandwidth;
}

void PhysicalLayerNative::Channel::RefreshChannel()
{
	real_T ten = _params->DynamicAWGN_SNR / 10.0;
	ten = rt_powd_snf(10.0, ten);
	ten = _params->DynamicAWGN_SPOW / ten;
	_state->STDDEV = sqrt(ten);
}