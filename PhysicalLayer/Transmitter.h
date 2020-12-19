#ifndef _TRANSMITTER_H_
#define _TRANSMITTER_H_

#include "PhysicalLayerModel_ext.h"
#include "Statistics.h"
#include "ModulationType.h"

namespace PhysicalLayerNative
{
	class Channel;
	class Transmitter
	{

	private:

		Channel* _channel;
		B_Transmitter_PhysicalLayerMo_T* _block;
		DW_Transmitter_PhysicalLayerM_T* _state;
		P_Transmitter_PhysicalLayerMo_T* _params;
		Statistics* _stats;
		void PadSymbols(uint8_T data[NET_FRAME_SYMBOLS_SIZE], uint8_T symbols[FRAME_SYMBOLS_SIZE]);

	public:

		Transmitter(Channel* channel,
			B_Transmitter_PhysicalLayerMo_T* block,
			DW_Transmitter_PhysicalLayerM_T* state,
			P_Transmitter_PhysicalLayerMo_T* params);

		~Transmitter();
		void Transmit(uint8_T[NET_FRAME_SYMBOLS_SIZE]);

		void SetStatistics(Statistics* stats);
		Statistics* GetStatistics();

		void SetDelay(int delay);
		int GetDelay();

		void SetCarrierFrequency(real_T frequency);
		real_T GetCarrierFrequency();

		void SetPower(real_T);
		real_T GetPower();

		void SetModulationType(ModulationType type);
		ModulationType GetModulationType();

		void SetBandwith(real_T width);
		real_T GetBandwith();

	};

}

#endif