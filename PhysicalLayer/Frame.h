#ifndef _FRAME_H_
#define _FRAME_H_

#include "PhysicalLayerModel_ext.h"

#define FRAME_OVERHEAD 8
#define FRAME_PAYLOAD_SIZE (FRAME_SIZE - FRAME_OVERHEAD)

class Frame
{
public:
	uint16_T SourceAddress;
	uint16_T DestinationAddress;
	uint8_T Type;
	uint8_T Length;
	uint8_T Payload[FRAME_PAYLOAD_SIZE];
	uint16_T CRC;
	char* ToString();
};

enum FrameType
{
	Data,
	Ack
};

#endif