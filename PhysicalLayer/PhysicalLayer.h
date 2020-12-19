#ifndef _PHYSICAL_LAYER_H_
#define _PHYSICAL_LAYER_H_

#include "PhysicalLayerModel_ext.h"
#include "Radio.h"
#include "Channel.h"
#include "Statistics.h"

namespace PhysicalLayerNative
{
	class PhysicalLayer
	{
	private:

		RT_MODEL_PhysicalLayerModel_T* _model;
		Radio* _radio1;
		Radio* _radio2;
		Statistics* _stats1;
		Statistics* _stats2;
		Channel* _channel1;
		Channel* _channel2;

		// Creates Channel 1
		Channel* PhysicalLayer::CreateChannel1();

		// Creates Transmitter 1
		Transmitter* PhysicalLayer::CreateTransmitter1(Channel* channel);

		// Creates Receiver 1
		Receiver* PhysicalLayer::CreateReceiver1(Radio* Radio);

		// Creates Statistics 1
		Statistics* CreateStatistics1();

		// Creates Channel 2
		Channel* PhysicalLayer::CreateChannel2();

		// Creates Transmitter 2
		Transmitter* PhysicalLayer::CreateTransmitter2(Channel* channel);

		// Creates Receiver 2
		Receiver* PhysicalLayer::CreateReceiver2(Radio* Radio);

		// Creates Statistics 2
		Statistics* CreateStatistics2();

		// Create Radio
		Radio* CreateRadio();

	public:

		// Constructor
		PhysicalLayer();

		// Destructor
		~PhysicalLayer();

		void Initialize();
		void Dispose();
		void Step();

		// Model Paramters
		ModelParameters* Parameters;

		// Map
		const ModelMap* GetModelMap();

		// Gets Radio 1
		Radio* GetRadio1();

		// Gets Radio 2
		Radio* GetRadio2();

		// Gets Statistics 1
		Statistics* GetStatistics1();

		// Gets Statistics 2
		Statistics* GetStatistics2();

		// Gets Channel 1
		Channel* GetChannel1();

		// Gets Channel 2
		Channel* GetChannel2();

		// Gets Time
		time_T GetTime();

		// Gets Ticks
		uint32_T GetTicks();
		
		void SetSampleTime(time_T time);
		time_T GetSampleTime();

	};

}

#endif