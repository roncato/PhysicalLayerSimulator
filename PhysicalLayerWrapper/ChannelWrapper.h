#pragma once

using namespace System;

#include "Channel.h";

namespace PhysicalLayer
{
	public ref class Channel
	{
	internal:
		property PhysicalLayerNative::Channel* NativeChannel
		{
			PhysicalLayerNative::Channel* get()
			{
				return _channel;
			}
			void set(PhysicalLayerNative::Channel* value)
			{
				_channel = value;
			}
		}
		Channel(PhysicalLayerNative::Channel* channel);
	private:
		PhysicalLayerNative::Channel* _channel;
	public:
		property double InterferanceFrequency
		{
			double get();
			void set(double value);
		}
		property double InterferanceAmplitude
		{
			double get();
			void set(double value);
		}
		property double InterferancePhase
		{
			double get();
			void set(double value);
		}
		property unsigned int AWGNSeed
		{
			unsigned int get();
			void set(unsigned int value);
		}
		property double SNR
		{
			double get();
			void set(double value);
		}
		property double InputSignalPower
		{
			double get();
			void set(double value);
		}
	};
}