#pragma once

using namespace System;

#include "ModulationType.h"

namespace PhysicalLayer
{
	public enum class ModulationType
	{
		QAM = PhysicalLayerNative::ModulationType::QAM,
		PSK = PhysicalLayerNative::ModulationType::PSK
	};
}