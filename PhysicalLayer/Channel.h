#ifndef _CHANNEL_H_
#define _CHANNEL_H_

#include "PhysicalLayerModel_ext.h"
#include "Receiver.h"
#include "PhysicalLayerModel_Channel.h"
#include <vector>

namespace PhysicalLayerNative
{
	class Channel
	{
	private:

		std::vector<Receiver*> _receivers;
		B_Channel_PhysicalLayerModel_T *_block;
		DW_Channel_PhysicalLayerMode_T *_state;
		P_Channel_PhysicalLayerModel_T *_params;
		void RefreshChannel();

	public:

		Channel(B_Channel_PhysicalLayerModel_T *block,
			DW_Channel_PhysicalLayerMode_T *state,
			P_Channel_PhysicalLayerModel_T *params);

		~Channel();
		void Transmit(real_T ComplextoRealImag[SIGNAL_SIZE]);
		void AddReceiver(Receiver* receiver);

		void SetInterferenceAmplitude(real_T);
		real_T GetInterferenceAmplitude();

		void SetInterferenceFrequency(real_T);
		real_T GetInterferenceFrequency();

		void SetInterferencePhase(real_T);
		real_T GetInterferencePhase();

		void SetAWGNSeed(uint32_T);
		uint32_T GetAWGNSeed();

		void SetSNR(real_T);
		real_T GetSNR();

		void SetInputSignalPower(real_T);
		real_T GetInputSignalPower();

		void SetBandwith(real_T width);
		real_T GetBandwith();

	};
}

#endif