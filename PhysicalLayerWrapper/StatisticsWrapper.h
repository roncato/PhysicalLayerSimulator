#pragma once

using namespace System;

#include "Statistics.h";

namespace PhysicalLayer 
{
	public ref class Statistics
	{
	internal:
		property PhysicalLayerNative::Statistics* NativeStatistics
		{
			PhysicalLayerNative::Statistics* get()
			{
				return _stats;
			}
			void set(PhysicalLayerNative::Statistics* value)
			{
				_stats = value;
			}
		}
		Statistics(PhysicalLayerNative::Statistics* stats);
	private:
		PhysicalLayerNative::Statistics* _stats;
	public:
		property double ErrorRatio
		{
			double get();			
		}
		property double Errors
		{
			double get();
		}
		property double Symbols
		{
			double get();
		}
		virtual String^ PhysicalLayer::Statistics::ToString() override;
	};
}