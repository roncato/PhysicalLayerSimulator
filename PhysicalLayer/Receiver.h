#ifndef _RECEIVER_H_
#define _RECEIVER_H_

#include "PhysicalLayerModel_ext.h"
#include "Statistics.h"
#include "Frame.h"
#include "ModulationType.h"

namespace PhysicalLayerNative
{
	class Radio;
	class Receiver
	{
	private:

		const int DEFAULT_DELAY = 8;

		Radio* _radio;
		B_Receiver_PhysicalLayerModel_T *_block;
		DW_Receiver_PhysicalLayerMode_T *_state;
		P_Receiver_PhysicalLayerModel_T *_params;
		Statistics* _stats;
		int _delay;

		void Receiver::FillFrame(uint8_T symbols[FRAME_SYMBOLS_SIZE], Frame* frame);

	public:

		Receiver(Radio* radio,
			B_Receiver_PhysicalLayerModel_T *block,
			DW_Receiver_PhysicalLayerMode_T *state,
			P_Receiver_PhysicalLayerModel_T *params);

		void Receive(real_T signal[SIGNAL_SIZE]);

		void SetStatistics(Statistics* stats);
		Statistics* GetStatistics();

		void SetDelay(int delay);
		int GetDelay();

		void SetCarrierFrequency(real_T frequency);
		real_T GetCarrierFrequency();

		void SetPower(real_T power);
		real_T GetPower();

		void SetModulationType(ModulationType type);
		ModulationType GetModulationType();

		void SetBandwith(real_T width);
		real_T GetBandwith();

	};

}

#endif