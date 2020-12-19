#pragma once

using namespace System;
using namespace System::Threading;
using namespace System::Runtime::InteropServices;

#include "Radio.h";
#include "ModulationTypeWrapper.h"

namespace PhysicalLayer {

	public ref class Radio
	{
	internal:
		property PhysicalLayerNative::Radio* NativeRadio
		{
			PhysicalLayerNative::Radio* get()
			{
				return _radio;
			}
			void set(PhysicalLayerNative::Radio* value)
			{
				_radio = value;
			}
		}
		Radio(PhysicalLayerNative::Radio* radio);
	private:
		PhysicalLayerNative::Radio* _radio;
		Radio();
		~Radio();
		Object^ _sendLock;
		Object^ _readLock;

	public:
		// Sends Frame
		void Send(unsigned short, array<unsigned char>^ buffer, int offset, int length);

		// Receives data
		int Read(array<unsigned char>^ buffer, int offset, int length);

		void SetSendLogFile(String^ fileName);
		void SetReceiveLogFile(String^ fileName);

		property int Buffered
		{
			int get();
		}
		
		property int Available
		{
			int get();
		}

		// Get or Sets Receiver Power
		property unsigned short LocalAddress
		{
			unsigned short get();
			void set(unsigned short value);
		}

		// Get or Sets Transmitter Carrier Frequency
		property double TransmitterCarrierFrequency
		{
			double get();
			void set(double value);
		}

		// Get or Sets Transmitter Power
		property double TransmitterPower
		{
			double get();
			void set(double value);
		}

		// Get or Sets Receiver Carrier Frequency
		property double ReceiverCarrierFrequency
		{
			double get();
			void set(double value);
		}

		// Get or Sets Receiver Power
		property double ReceiverPower
		{
			double get();
			void set(double value);
		}

		// Gets or Sets Transmitter Modulation Type
		property ModulationType TransmitterModulationType
		{
			ModulationType get();
			void set(ModulationType value);
		}

		// Gets or Sets Receiver Modulation Type
		property ModulationType ReceiverModulationType
		{
			ModulationType get();
			void set(ModulationType value);
		}

	};
}