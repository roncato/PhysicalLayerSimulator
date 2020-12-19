#include "Stdafx.h"

#include "ChannelWrapper.h"

PhysicalLayer::Channel::Channel(PhysicalLayerNative::Channel* channel)
{
	_channel = channel;
}

double PhysicalLayer::Channel::InterferanceFrequency::get()
{
	return _channel->GetInterferenceFrequency();
}

void PhysicalLayer::Channel::InterferanceFrequency::set(double value)
{
	_channel->SetInterferenceFrequency(value);
}

double PhysicalLayer::Channel::InterferanceAmplitude::get()
{
	return _channel->GetInterferenceAmplitude();
}

void PhysicalLayer::Channel::InterferanceAmplitude::set(double value)
{
	_channel->SetInterferenceAmplitude(value);
}

double PhysicalLayer::Channel::InterferancePhase::get()
{
	return _channel->GetInterferencePhase();
}

void PhysicalLayer::Channel::InterferancePhase::set(double value)
{
	_channel->SetInterferencePhase(value);
}

unsigned int PhysicalLayer::Channel::AWGNSeed::get()
{
	return _channel->GetAWGNSeed();
}

void PhysicalLayer::Channel::AWGNSeed::set(unsigned int value)
{
	_channel->SetAWGNSeed(value);
}

double PhysicalLayer::Channel::SNR::get()
{
	return _channel->GetSNR();
}

void PhysicalLayer::Channel::SNR::set(double value)
{
	_channel->SetSNR(value);
}

double PhysicalLayer::Channel::InputSignalPower::get()
{
	return _channel->GetInputSignalPower();
}

void PhysicalLayer::Channel::InputSignalPower::set(double value)
{
	_channel->SetInputSignalPower(value);
}