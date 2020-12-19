#include "stdafx.h"

#include "StatisticsWrapper.h"

PhysicalLayer::Statistics::Statistics(PhysicalLayerNative::Statistics* stats)
{
	_stats = stats;
}

double PhysicalLayer::Statistics::ErrorRatio::get()
{
	return _stats->GetErrorRate();
}

double PhysicalLayer::Statistics::Errors::get()
{
	return _stats->GetErrors();
}

double PhysicalLayer::Statistics::Symbols::get()
{
	return _stats->GetSymbols();
}

String^ PhysicalLayer::Statistics::ToString()
{
	return String::Format("Error Rate:{0}, Errors:{1}, Symbols:{2}", ErrorRatio, Errors, Symbols);
}