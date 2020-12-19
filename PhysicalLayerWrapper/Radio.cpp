#include "stdafx.h"

#include "RadioWrapper.h"

PhysicalLayer::Radio::Radio()
{
	_sendLock = gcnew Object();
	_readLock = gcnew Object();
}

PhysicalLayer::Radio::~Radio()
{
}

PhysicalLayer::Radio::Radio(PhysicalLayerNative::Radio* radio)
{
	_sendLock = gcnew Object();
	_readLock = gcnew Object();
	_radio = radio;
	TransmitterModulationType = ModulationType::QAM;
	ReceiverModulationType = ModulationType::QAM;
}

void PhysicalLayer::Radio::Send(unsigned short remoteAddress, array<unsigned char>^ buffer, int offset, int length)
{
	uchar_T* buff = new uchar_T[length];
	for (size_t i = 0; i < length; i++)
	{
		buff[i] = buffer[i + offset];
	}
	try
	{
		Monitor::Enter(_sendLock);
		_radio->Send(remoteAddress, buff, 0, length);
	}
	finally
	{
		Monitor::Exit(_sendLock);
	}
}

int PhysicalLayer::Radio::Read(array<unsigned char>^ buffer, int offset, int length)
{
	uint8_T* buff = new uint8_T[length];
	try
	{
		Monitor::Enter(_readLock);
		size_t bytesRead = _radio->Read(buff, 0, length);
		for (size_t i = 0; i < bytesRead; i++)
		{
			buffer[i + offset] = buff[i];
		}
		return bytesRead;
	}
	finally
	{
		Monitor::Exit(_readLock);
	}
}

void PhysicalLayer::Radio::SetSendLogFile(String^ fileName)
{
	char* cString = (char*)(void*)Marshal::StringToHGlobalAnsi(fileName);
	_radio->SetSendLogFile(cString);
}

void PhysicalLayer::Radio::SetReceiveLogFile(String^ fileName)
{
	char* cString = (char*)(void*)Marshal::StringToHGlobalAnsi(fileName);
	_radio->SetReceiveLogFile(cString);
}

int PhysicalLayer::Radio::Available::get()
{
	return _radio->Available();
}

int PhysicalLayer::Radio::Buffered::get()
{
	return _radio->Buffered();
}

double PhysicalLayer::Radio::TransmitterCarrierFrequency::get()
{
	return _radio->GetTransmitter()->GetCarrierFrequency();
}

void PhysicalLayer::Radio::TransmitterCarrierFrequency::set(double value)
{
	_radio->GetTransmitter()->SetCarrierFrequency(value);
}

double PhysicalLayer::Radio::TransmitterPower::get()
{
	return _radio->GetTransmitter()->GetPower();
}

void PhysicalLayer::Radio::TransmitterPower::set(double value)
{
	_radio->GetTransmitter()->SetPower(value);
}

double PhysicalLayer::Radio::ReceiverCarrierFrequency::get()
{
	return _radio->GetTransmitter()->GetCarrierFrequency();
}

void PhysicalLayer::Radio::ReceiverCarrierFrequency::set(double value)
{
	_radio->GetTransmitter()->SetCarrierFrequency(value);
}

double PhysicalLayer::Radio::ReceiverPower::get()
{
	return _radio->GetTransmitter()->GetPower();
}

void PhysicalLayer::Radio::ReceiverPower::set(double value)
{
	_radio->GetTransmitter()->SetPower(value);
}

unsigned short PhysicalLayer::Radio::LocalAddress::get()
{
	return _radio->GetLocalAddress();
}

void PhysicalLayer::Radio::LocalAddress::set(unsigned short value)
{
	_radio->SetLocalAddress(value);
}

PhysicalLayer::ModulationType PhysicalLayer::Radio::TransmitterModulationType::get()
{
	return (ModulationType)_radio->GetTransmitter()->GetModulationType();
}

void PhysicalLayer::Radio::TransmitterModulationType::set(ModulationType value)
{
	_radio->GetTransmitter()->SetModulationType((PhysicalLayerNative::ModulationType)value);
}

PhysicalLayer::ModulationType PhysicalLayer::Radio::ReceiverModulationType::get()
{
	return (ModulationType)_radio->GetReceiver()->GetModulationType();
}

void PhysicalLayer::Radio::ReceiverModulationType::set(ModulationType value)
{
	_radio->GetReceiver()->SetModulationType((PhysicalLayerNative::ModulationType)value);
}