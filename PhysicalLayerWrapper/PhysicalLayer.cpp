#include "stdafx.h"

#include "PhysicalLayerWrapper.h"
#include "PhysicalLayer.h" 

PhysicalLayer::PhysicalLayer::PhysicalLayer()
{
	_physicalLayer = new PhysicalLayerNative::PhysicalLayer();
}

PhysicalLayer::PhysicalLayer::~PhysicalLayer()
{
}

void PhysicalLayer::PhysicalLayer::Initialize()
{
	_physicalLayer->Initialize();
	_radio1 = gcnew Radio(_physicalLayer->GetRadio1());
	_radio2 = gcnew Radio(_physicalLayer->GetRadio2());
	_stats1 = gcnew Statistics(_physicalLayer->GetStatistics1());
	_stats2 = gcnew Statistics(_physicalLayer->GetStatistics2());
	_channel1 = gcnew Channel(_physicalLayer->GetChannel1());
	_channel2 = gcnew Channel(_physicalLayer->GetChannel2());
}

void PhysicalLayer::PhysicalLayer::Step()
{
	_physicalLayer->Step();
}

ModelParameters* PhysicalLayer::PhysicalLayer::Parameters::get()
{
	return _physicalLayer->Parameters;
}

const ModelMap* PhysicalLayer::PhysicalLayer::Map::get()
{
	return _physicalLayer->GetModelMap();
}

PhysicalLayer::Radio^ PhysicalLayer::PhysicalLayer::Radio1::get()
{
	return _radio1;
}

PhysicalLayer::Radio^ PhysicalLayer::PhysicalLayer::Radio2::get()
{
	return _radio2;
}

PhysicalLayer::Statistics^ PhysicalLayer::PhysicalLayer::Statistics1::get()
{
	return _stats1;
}

PhysicalLayer::Statistics^ PhysicalLayer::PhysicalLayer::Statistics2::get()
{
	return _stats2;
}

PhysicalLayer::Channel^ PhysicalLayer::PhysicalLayer::Channel1::get()
{
	return _channel1;
}

PhysicalLayer::Channel^ PhysicalLayer::PhysicalLayer::Channel2::get()
{
	return _channel2;
}

double PhysicalLayer::PhysicalLayer::Time::get()
{
	return _physicalLayer->GetTime();
}

unsigned int PhysicalLayer::PhysicalLayer::Ticks::get()
{
	return _physicalLayer->GetTicks();
}