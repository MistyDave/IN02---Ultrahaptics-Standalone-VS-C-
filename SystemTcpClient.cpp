//#include "stdafx.h"
#include <string>
#include "SystemTcpClient.h"



SystemTcpClient::SystemTcpClient()
{
	serverError = "";
	finishCleaningAndDie = false;
	clientThread = gcnew Thread(gcnew ThreadStart(this, &SystemTcpClient::clientThreadMethod));
	clientThread->Start();
}

SystemTcpClient::~SystemTcpClient()
{
	finishCleaningAndDie = true;

	clientThread->Interrupt();
	clientThread->Join();


}

void SystemTcpClient::clientThreadMethod()
{
	Int32 port = 13000;
	this->client = gcnew TcpClient();

	client->ReceiveTimeout = 3000;
	client->SendTimeout = 3000;

	while (!finishCleaningAndDie)
	{
		try
		{
			if (!client->Connected)
			{
				client = gcnew TcpClient();
				client->ReceiveTimeout = 3000;
				client->SendTimeout = 3000;
				client->Connect(gcnew IPEndPoint(IPAddress::Parse("127.0.0.1"), port)); //local host
			}
			else
			{
				
				NetworkStream^ stream = client->GetStream();

				// Translate the passed message into ASCII and store it as a Byte array.
				array<Byte>^data = Text::Encoding::ASCII->GetBytes("TILT\n");

				// Send the message to the connected TcpServer. 
				stream->Write(data, 0, data->Length);


				// Buffer to store the response bytes.
				data = gcnew array<Byte>(256);

				// String to store the response ASCII representation.
				String^ responseData = String::Empty;

				// Read the first batch of the TcpServer response bytes.
				Int32 bytes = stream->Read(data, 0, data->Length);
				responseData = Text::Encoding::ASCII->GetString(data, 0, bytes);


				String^ delimStr = "=";
				array<String^>^ resp = responseData->Split(delimStr->ToCharArray());

				if (resp->Length >= 2)
				{
					if (resp[0]->Contains("TILT"))
					{
						try
						{
							glassAngle = Convert::ToDouble(resp[1]);
						}
						catch (FormatException^ e)
						{
							Console::WriteLine("FormatException: {0}", e);
						}
						catch (OverflowException^ e)
						{
							Console::WriteLine("OverflowException: {0}", e);
						}
						
					}
				}

				//Console::WriteLine("Received: {0}", responseData);

				
				/*
				//Hack to test update thread
				glassAngle = glassAngle - 1;
				if (glassAngle == -100)
					glassAngle = 0;
				*/
			}

			serverError = "";
		}
		catch (System::IO::IOException^ e)
		{

		}
		catch (ArgumentNullException^ e)
		{
			Console::WriteLine("ArgumentNullException: {0}", e);
		}
		catch (SocketException^ e)
		{
			serverError = "Error: Socket Exception";
			Console::WriteLine("SocketException: {0}", e);
		}

		try
		{
			Thread::Sleep(500);
		}
		catch (ThreadInterruptedException^ ex)
		{

		}
	}

	// Close everything.
	client->Close();

}

