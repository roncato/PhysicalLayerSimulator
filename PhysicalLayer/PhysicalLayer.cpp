#include "PhysicalLayer.h"
#include <Windows.h>

PhysicalLayerNative::PhysicalLayer::PhysicalLayer()
{
	_model = PhysicalLayerModel();
}

PhysicalLayerNative::PhysicalLayer::~PhysicalLayer()
{
	Dispose();
}

void PhysicalLayerNative::PhysicalLayer::Initialize()
{

	// Initializer Logs
	rt_StartDataLogging(rtmGetRTWLogInfo(_model),
		rtmGetTFinal(_model),
		rtmGetStepSize(_model),
		&rtmGetErrorStatus(_model));

	// Initialize Model
	PhysicalLayerModel_initialize(_model);

	// Build Objects
	_channel1 = CreateChannel1();
	_channel2 = CreateChannel2();
	_stats1 = CreateStatistics1();
	_stats2 = CreateStatistics2();
	_radio1 = CreateRadio();
	_radio2 = CreateRadio();

	Transmitter* transmitter1 = CreateTransmitter1(_channel1);
	transmitter1->SetStatistics(_stats1);
	Receiver* receiver1 = CreateReceiver1(_radio1);
	receiver1->SetStatistics(_stats2);
	_radio1->SetReceiver(receiver1);
	_radio1->SetTransmitter(transmitter1);

	Transmitter* transmitter2 = CreateTransmitter2(_channel2);
	transmitter2->SetStatistics(_stats2);
	Receiver* receiver2 = CreateReceiver2(_radio2);
	receiver2->SetStatistics(_stats1);
	_radio2->SetReceiver(receiver2);
	_radio2->SetTransmitter(transmitter2);

	_channel1->AddReceiver(receiver2);
	_channel2->AddReceiver(receiver1);

}

void PhysicalLayerNative::PhysicalLayer::Step()
{

	_radio1->Step();
	_radio2->Step();
	_stats1->Step();
	_stats2->Step();

	if (!(++_model->Timing.clockTick0)) {
		++_model->Timing.clockTickH0;
	}

	_model->Timing.taskTime0 = _model->Timing.clockTick0 * _model->Timing.stepSize0 +
		_model->Timing.clockTickH0 * _model->Timing.stepSize0 * 4294967296.0;

}

void PhysicalLayerNative::PhysicalLayer::Dispose()
{
	if (_model != NULL)
	{
		PhysicalLayerModel_terminate(_model);
		delete _model;
		_model = NULL;
	}
}

const ModelMap* PhysicalLayerNative::PhysicalLayer::GetModelMap()
{
	return (ModelMap*) PhysicalLayerModel_GetCAPIStaticMap();
}

PhysicalLayerNative::Radio* PhysicalLayerNative::PhysicalLayer::GetRadio1()
{
	return _radio1;
}

PhysicalLayerNative::Radio* PhysicalLayerNative::PhysicalLayer::GetRadio2()
{
	return _radio2;
}

PhysicalLayerNative::Statistics* PhysicalLayerNative::PhysicalLayer::GetStatistics1()
{
	return _stats1;
}

PhysicalLayerNative::Statistics* PhysicalLayerNative::PhysicalLayer::GetStatistics2()
{
	return _stats2;
}

PhysicalLayerNative::Channel* PhysicalLayerNative::PhysicalLayer::GetChannel1()
{
	return _channel1;
}

PhysicalLayerNative::Channel* PhysicalLayerNative::PhysicalLayer::GetChannel2()
{
	return _channel2;
}

// Creators
PhysicalLayerNative::Channel* PhysicalLayerNative::PhysicalLayer::CreateChannel1()
{
	return new Channel(&_model->ModelData.blockIO->Channel1,
						&_model->ModelData.dwork->Channel1,
						&_model->ModelData.defaultParam->Channel1);
}

PhysicalLayerNative::Transmitter* PhysicalLayerNative::PhysicalLayer::CreateTransmitter1(Channel* channel)
{
	return new Transmitter(channel,
							&_model->ModelData.blockIO->Transmitter,
							&_model->ModelData.dwork->Transmitter,
							&_model->ModelData.defaultParam->Transmitter);
}

PhysicalLayerNative::Receiver* PhysicalLayerNative::PhysicalLayer::CreateReceiver1(Radio* radio)
{
	return new Receiver(radio,
						&_model->ModelData.blockIO->Receiver,
						&_model->ModelData.dwork->Receiver,
						&_model->ModelData.defaultParam->Receiver);
}

PhysicalLayerNative::Statistics* PhysicalLayerNative::PhysicalLayer::CreateStatistics1()
{
	return new Statistics(&_model->ModelData.blockIO->Statistics1,
						&_model->ModelData.dwork->Statistics1);
}

PhysicalLayerNative::Channel* PhysicalLayerNative::PhysicalLayer::CreateChannel2()
{
	return new Channel(&_model->ModelData.blockIO->Channel2,
		&_model->ModelData.dwork->Channel2,
		&_model->ModelData.defaultParam->Channel2);
}

PhysicalLayerNative::Transmitter* PhysicalLayerNative::PhysicalLayer::CreateTransmitter2(Channel* channel)
{
	return new Transmitter(channel,
		&_model->ModelData.blockIO->Transmitter_fe4q0,
		&_model->ModelData.dwork->Transmitter_fe4q0,
		&_model->ModelData.defaultParam->Transmitter_fe4q0);
}

PhysicalLayerNative::Receiver* PhysicalLayerNative::PhysicalLayer::CreateReceiver2(Radio* radio)
{
	return new Receiver(radio,
		&_model->ModelData.blockIO->Receiver_ewxak,
		&_model->ModelData.dwork->Receiver_ewxak,
		&_model->ModelData.defaultParam->Receiver_ewxak);
}

PhysicalLayerNative::Statistics* PhysicalLayerNative::PhysicalLayer::CreateStatistics2()
{
	return new Statistics(&_model->ModelData.blockIO->Statistics2,
		&_model->ModelData.dwork->Statistics2);
}

PhysicalLayerNative::Radio* PhysicalLayerNative::PhysicalLayer::CreateRadio()
{
	return new Radio();
}

time_T PhysicalLayerNative::PhysicalLayer::GetTime()
{
	return _model->Timing.taskTime0;
}

uint32_T PhysicalLayerNative::PhysicalLayer::GetTicks()
{
	return _model->Timing.clockTick0;
}

void PhysicalLayerNative::PhysicalLayer::SetSampleTime(time_T time)
{
	_model->Timing.stepSize0 = time * FRAME_SYMBOLS_SIZE;
	_model->Timing.stepSize = _model->Timing.stepSize0;
}

time_T PhysicalLayerNative::PhysicalLayer::GetSampleTime()
{
	return _model->Timing.stepSize0 / FRAME_SYMBOLS_SIZE;
}