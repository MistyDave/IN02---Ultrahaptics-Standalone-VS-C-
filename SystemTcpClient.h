


using namespace System;
using namespace System::IO::Ports;
using namespace System::Threading;
using namespace System::Net;
using namespace System::Net::Sockets;

#pragma once

ref class SystemTcpClient
{

private:
	TcpClient^ client;
	Thread^ clientThread;
	bool finishCleaningAndDie;

protected:
	void clientThreadMethod();

public:
	volatile double glassAngle;
	String^ serverError;
	SystemTcpClient();
	~SystemTcpClient();
};


