#ifndef _PHYSICAL_LAYER_MODEL_EXT_
#define _PHYSICAL_LAYER_MODEL_EXT_

#include "PhysicalLayerModel.h"

#define FRAME_SYMBOLS_SIZE 264
#define SYSTEM_DELAY 8
#define NET_FRAME_SYMBOLS_SIZE (FRAME_SYMBOLS_SIZE - SYSTEM_DELAY)
#define FRAME_SIZE NET_FRAME_SYMBOLS_SIZE / 2
#define SIGNAL_SIZE FRAME_SYMBOLS_SIZE * 8

// Default Types
typedef struct P_PhysicalLayerModel_T_ ModelParameters;

typedef rtwCAPI_ModelMappingStaticInfo ModelMap;

#endif