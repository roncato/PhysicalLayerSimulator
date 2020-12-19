// PhysicalLayerWrapper.h

#pragma once

using namespace System;

#include "RadioWrapper.h"
#include "StatisticsWrapper.h"
#include "ChannelWrapper.h"

namespace PhysicalLayerNative
{
	class PhysicalLayer;
}

namespace PhysicalLayer 
{
	public ref class PhysicalLayer
	{
	private:
		PhysicalLayerNative::PhysicalLayer* _physicalLayer;
		Radio^ _radio1;
		Radio^ _radio2;
		Statistics^ _stats1;
		Statistics^ _stats2;
		Channel^ _channel1;
		Channel^ _channel2;
	public:

		static const int FRAMESIZE = FRAME_SIZE;
		static const int PAYLOAD_SIZE = FRAME_PAYLOAD_SIZE;

		// Constructor
		PhysicalLayer();

		// Destructor
		~PhysicalLayer();

		void Initialize();
		void Step();

		// Model Paramters
		property ModelParameters* Parameters
		{
			ModelParameters* get();
		}

		// Map
		property const ModelMap* Map
		{
			const ModelMap* get();
		}

		property PhysicalLayer::Radio^ Radio1
		{
			Radio^ get();
		}

		property PhysicalLayer::Radio^ Radio2
		{
			Radio^ get();
		}

		property PhysicalLayer::Statistics^ Statistics1
		{
			Statistics^ get();
		}

		property Statistics^ Statistics2
		{
			Statistics^ get();
		}

		property Channel^ Channel1
		{
			Channel^ get();
		}

		property Channel^ Channel2
		{
			Channel^ get();
		}

		property double Time
		{
			double get();
		}

		property unsigned int Ticks
		{
			unsigned int get();
		}
		
	};
}
