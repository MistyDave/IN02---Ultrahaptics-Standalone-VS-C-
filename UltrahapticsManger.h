#include "ultrahaptics\Ultrahaptics.hpp"
#include <vector>
#include <math.h>
#include "SystemTcpClient.h"

using namespace Ultrahaptics;
using namespace System::Collections::Generic;
using namespace System::Threading;

#pragma once

public interface class IUltrahapticsListener
{
	void hapticsChange();
};


ref class UltrahapticsManger
{
private:
	List<IUltrahapticsListener^>^ hapticsListenerList;
	bool finishCleaningAndDie;
	Ultrahaptics::Emitter* emitter;
	SystemTcpClient^ client;



public:
	UltrahapticsManger();
	~UltrahapticsManger();

	//Ultrahaptics Listener Methods
	void addListener(IUltrahapticsListener^ hapList);
	void removeListener(IUltrahapticsListener^ hapList);
	void clearListeners();
	void fireUpdateEvent();
	
	//
	Thread^ ultrahapticsControlThread;
	void controlThread();

	//Public Parameters (exposed for ease of programming)
	bool emitterEnabled;
	double glassAngle; //txtGlassAngle
	double height_PivotToUltrahaptics; //txtPivotToUltrahapics
	double height_PivotToModelBottom; //txtPivotToModel
	double baseDistanceFromGlass; //txtUltrahapticsToGlass
	double modelDistanceFromGlass; //txtModelToGlass
	double modelWidth; //txtModelWidth
	double modelLength; //txtModelLength
	float frequency; //txtFreq
	float intensity; //txtIntensity
	String^ serverError;
};

