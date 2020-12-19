#include "stdafx.h"
#include "CppUnitTest.h"
#include "PhysicalLayer.h"
#include <time.h>
#include <math.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace PhysicalLayerNative;

namespace PhysicalLayerTest
{		
	TEST_CLASS(NativeTests)
	{
	public:
		
		TEST_METHOD(PhysicalLayerShouldInitializeCorrectly)
		{
			PhysicalLayer* p = new PhysicalLayer();
			p->Initialize();
		}

		TEST_METHOD(PhysicalLayerShouldSend100FramesAtEveryStep)
		{
			PhysicalLayer* p = new PhysicalLayer();
			p->Initialize();
			uchar_T frame[FRAME_PAYLOAD_SIZE];
			for (int i = 0; i < 100; i++)
			{
				FillRandomPayload(frame, FRAME_PAYLOAD_SIZE);
				p->GetRadio1()->Send(0, frame, 0, FRAME_PAYLOAD_SIZE);
				p->Step();
			}
		}

		TEST_METHOD(PhysicalLayerShouldSendAndReceiveDataFramesAtEveryStep)
		{
			PhysicalLayer* p = new PhysicalLayer();
			p->Initialize();
			const int framesSent = 100;
			int payloadLength = FRAME_PAYLOAD_SIZE;
			SendAndReceive(p, true, framesSent, payloadLength);
		}

		TEST_METHOD(RadioShouldFragmentPayload)
		{
			PhysicalLayer* p = new PhysicalLayer();
			p->Initialize();
			const int framesSent = 50;
			int payloadLength = 1.5 * FRAME_PAYLOAD_SIZE;
			SendAndReceive(p, true, framesSent, payloadLength);
		}

		TEST_METHOD(PhysicalLayerShouldSendAndReceiveAtCarrierFrequency10to6)
		{
			PhysicalLayer* p = new PhysicalLayer();
			p->Initialize();
			p->GetRadio1()->GetTransmitter()->SetCarrierFrequency(10e6);
			p->GetRadio2()->GetReceiver()->SetCarrierFrequency(10e6);
			const int framesSent = 100;
			int payloadLength = FRAME_PAYLOAD_SIZE;
			SendAndReceive(p, true, framesSent, payloadLength);
		}

		TEST_METHOD(PhysicalLayerShouldSendAndReceiveAt2Power)
		{
			PhysicalLayer* p = new PhysicalLayer();
			real_T power = 2.0;
			p->Initialize();
			p->GetRadio1()->GetTransmitter()->SetPower(power);
			p->GetRadio2()->GetReceiver()->SetPower(power);
			const int framesSent = 100;
			int payloadLength = FRAME_PAYLOAD_SIZE;
			SendAndReceive(p, true, framesSent, payloadLength);
		}

		TEST_METHOD(IntereranceCauseErrors)
		{
			PhysicalLayer* p = new PhysicalLayer();
			p->Initialize();
			p->GetChannel1()->SetInterferenceFrequency(2 * p->GetRadio1()->GetTransmitter()->GetCarrierFrequency());
			p->GetRadio1()->GetTransmitter()->SetPower(0.7);
			p->GetRadio2()->GetReceiver()->SetPower(p->GetRadio1()->GetTransmitter()->GetPower());
			const int framesSent = 100;
			int payloadLength = FRAME_PAYLOAD_SIZE;
			SendAndReceive(p, false, framesSent, payloadLength);
		}

		TEST_METHOD(PowerShouldCauseErrors)
		{
			PhysicalLayer* p = new PhysicalLayer();
			p->Initialize();
			p->GetRadio1()->GetTransmitter()->SetPower(2.0);
			const int framesSent = 100;
			int payloadLength = FRAME_PAYLOAD_SIZE;
			SendAndReceive(p, false, framesSent, payloadLength);
		}

		TEST_METHOD(DifferentModulationTypesCauseErrors)
		{
			PhysicalLayer* p = new PhysicalLayer();
			p->Initialize();
			p->GetRadio1()->GetTransmitter()->SetModulationType(ModulationType::QAM);
			p->GetRadio2()->GetReceiver()->SetModulationType(ModulationType::PSK);
			const int framesSent = 100;
			int payloadLength = FRAME_PAYLOAD_SIZE;
			SendAndReceive(p, false, framesSent, payloadLength);
		}

		void SendAndReceive(PhysicalLayer* p, bool assertPositive, const int framesSent, size_t payloadLength)
		{
			uint8_T* payload = new uint8_T[payloadLength];
			size_t bufferIndex = 0;
			uint8_T* sendData = new uint8_T[framesSent * payloadLength];
			uint8_T* receiveData = new uint8_T[framesSent * payloadLength];

			for (int i = 0; i < framesSent; i++)
			{
				FillRandomPayload(payload, payloadLength);
				for (int j = 0; j < FRAME_PAYLOAD_SIZE; j++)
				{
					sendData[bufferIndex++] = payload[j];
				}
				p->GetRadio1()->Send(p->GetRadio2()->GetLocalAddress(), payload, 0, payloadLength);
			}
			// Steps
			size_t stepsNumber = framesSent * ceil(double(payloadLength) / FRAME_PAYLOAD_SIZE);
			for (size_t i = 0; i < stepsNumber; i++)
			{
				p->Step();
			}

			bufferIndex = 0;
			for (int i = 0; i < framesSent; i++)
			{
				uchar_T receiveFrame[FRAME_PAYLOAD_SIZE];
				if (p->GetRadio2()->Available() > 0)
				{
					int receiveBytes = p->GetRadio2()->Available();
					if (receiveBytes > FRAME_PAYLOAD_SIZE)
					{
						receiveBytes = FRAME_PAYLOAD_SIZE;
					}
					receiveBytes = p->GetRadio2()->Read(receiveFrame, 0, receiveBytes);
					for (int j = 0; j < receiveBytes; j++)
					{
						receiveData[bufferIndex++] = receiveFrame[j];
					}
				}
			}
			PrintStatistics(p);
			if (assertPositive)
			{
				Assert::IsTrue(0 == p->GetStatistics1()->GetErrors());
			}
			else
			{
				Assert::IsFalse(0 == p->GetStatistics1()->GetErrors());
			}
		}

		void PrintStatistics(PhysicalLayer* p)
		{
			std::cout << "Finished processing. Statistics 1:" + *p->GetStatistics1()->ToString() << std::endl;
			std::cout << "Finished processing. Statistics 2:" + *p->GetStatistics2()->ToString() << std::endl;	
		}

		void FillRandomPayload(uint8_T* payload, size_t length)
		{
			for (int i = 0; i < length; i++)
			{
				payload[i] = uint8_T((rand() % 255) & 0x000000FF);
			}
		}
	
	};
}