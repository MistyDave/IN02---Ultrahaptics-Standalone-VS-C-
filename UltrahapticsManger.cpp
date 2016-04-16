#include "UltrahapticsManger.h"



UltrahapticsManger::UltrahapticsManger()
{
	hapticsListenerList = gcnew List<IUltrahapticsListener^>();

	emitter = new Ultrahaptics::Emitter();

	emitterEnabled = false;

	finishCleaningAndDie = false;
	glassAngle = 0;
	height_PivotToUltrahaptics = 200;
	height_PivotToModelBottom = 100;
	baseDistanceFromGlass = 10;
	modelDistanceFromGlass = 60;
	modelWidth = 50;
	modelLength = 50;

	frequency = 200.0f * Ultrahaptics::Units::hertz;
	intensity = 1.0f;

	client = gcnew SystemTcpClient();

	ultrahapticsControlThread = gcnew Thread(gcnew ThreadStart(this, &UltrahapticsManger::controlThread));
	ultrahapticsControlThread->Start();
}

UltrahapticsManger::~UltrahapticsManger()
{
	hapticsListenerList->Clear();
	delete client;

	finishCleaningAndDie = true;
	ultrahapticsControlThread->Interrupt();
	ultrahapticsControlThread->Join();

	emitter->stop();
}

void UltrahapticsManger::addListener(IUltrahapticsListener^ hapList)
{
	hapticsListenerList->Add(hapList);
}

void UltrahapticsManger::removeListener(IUltrahapticsListener^ hapList)
{
	hapticsListenerList->Remove(hapList);
}

void UltrahapticsManger::clearListeners()
{
	hapticsListenerList->Clear();
}

void UltrahapticsManger::fireUpdateEvent()
{
	for each(IUltrahapticsListener ^ listener in hapticsListenerList)
	{
		//Fire the change event for this listner
		listener->hapticsChange();
	}
}



void UltrahapticsManger::controlThread()
{
	//Initialize the emitter here.
	emitter->initialize();

	while (!this->finishCleaningAndDie)
	{
		glassAngle = client->glassAngle;
		serverError = client->serverError;

		fireUpdateEvent();

		if (emitterEnabled)
		{
			double xStart = -this->modelLength / 2 * Ultrahaptics::Units::mm;
			double xStop = this->modelLength / 2 * Ultrahaptics::Units::mm;
			double yStart = (this->modelDistanceFromGlass - this->baseDistanceFromGlass)  * Ultrahaptics::Units::mm;
			double yStop = (yStart + this->modelWidth)  * Ultrahaptics::Units::mm;
			double zStart = (this->height_PivotToUltrahaptics - this->height_PivotToModelBottom)  * Ultrahaptics::Units::mm;

			std::vector<Ultrahaptics::ControlPoint> points;

			//Create a list of those points
			points.push_back(Ultrahaptics::ControlPoint(Ultrahaptics::Vector3(xStart, yStart, zStart), intensity, frequency));
			points.push_back(Ultrahaptics::ControlPoint(Ultrahaptics::Vector3(xStop, yStart, zStart), intensity, frequency));
			points.push_back(Ultrahaptics::ControlPoint(Ultrahaptics::Vector3(xStart, yStop, zStart), intensity, frequency));
			points.push_back(Ultrahaptics::ControlPoint(Ultrahaptics::Vector3(xStop, yStop, zStart), intensity, frequency));
			emitter->update(points.data(), points.size());
		}
		else
		{
			emitter->stop();
		}

		try
		{
			Thread::Sleep(500);
		}
		catch (ThreadInterruptedException^ ex)
		{

		}
	}

	emitter->stop();
}
