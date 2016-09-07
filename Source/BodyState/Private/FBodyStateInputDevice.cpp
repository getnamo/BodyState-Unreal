#include "BodyStatePrivatePCH.h"
#include "IHeadMountedDisplay.h"
#include "SlateBasics.h"
#include "BodyStateInputInterface.h"
#include "FBodyStateInputDevice.h"
#include "BodyStateHMDSnapshot.h"
#include "BodyStateDevice.h"

#define MAX_HMD_SNAPSHOT_COUNT 10

//Define each FKey const in a .cpp so we can compile
//const FKey EKeysLeap::LeapLeftPinch("LeapLeftPinch");



//Function call Utility
void FBodyStateInputDevice::CallFunctionOnDelegates(TFunction< void(UObject*)> InFunction)
{
	for (UBodyStateDevice* Device : Devices)
	{
		if (Device->InputCallbackDelegate != nullptr) 
		{
			InFunction(Device->InputCallbackDelegate);
		}
	}
}

//UE v4.6 IM event wrappers
bool FBodyStateInputDevice::EmitKeyUpEventForKey(FKey Key, int32 User, bool Repeat)
{
	FKeyEvent KeyEvent(Key, FSlateApplication::Get().GetModifierKeys(), User, Repeat, 0, 0);
	return FSlateApplication::Get().ProcessKeyUpEvent(KeyEvent);
}

bool FBodyStateInputDevice::EmitKeyDownEventForKey(FKey Key, int32 User, bool Repeat)
{
	FKeyEvent KeyEvent(Key, FSlateApplication::Get().GetModifierKeys(), User, Repeat, 0, 0);
	return FSlateApplication::Get().ProcessKeyDownEvent(KeyEvent);
}

bool FBodyStateInputDevice::EmitAnalogInputEventForKey(FKey Key, float Value, int32 User, bool Repeat)
{
	FAnalogInputEvent AnalogInputEvent(Key, FSlateApplication::Get().GetModifierKeys(), User, Repeat, 0, 0, Value);
	return FSlateApplication::Get().ProcessAnalogInputEvent(AnalogInputEvent);
}

FBodyStateInputDevice::FBodyStateInputDevice(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler) : MessageHandler(InMessageHandler) 
{
	//HMDSamples = new HMDSnapshotSamples(ControllerData.LeapController); 	//store a reference for our timing circuits
}

FBodyStateInputDevice::~FBodyStateInputDevice()
{
}

void FBodyStateInputDevice::SetMessageHandler(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler)
{
	MessageHandler = InMessageHandler;
}

bool FBodyStateInputDevice::Exec(UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Ar)
{
	// Nothing necessary to do (boilerplate code to complete the interface)
	return false;
}


void FBodyStateInputDevice::SetChannelValue(int32 ControllerId, FForceFeedbackChannelType ChannelType, float Value)
{
	// Nothing necessary to do (boilerplate code to complete the interface)
}


void FBodyStateInputDevice::SetChannelValues(int32 ControllerId, const FForceFeedbackValues &values)
{
	// Nothing necessary to do (boilerplate code to complete the interface)
}

/*void FBodyStateInputDevice::AddEventDelegate(UObject* EventDelegate)
{
	if (EventDelegate->GetClass()->ImplementsInterface(UBodyStateInputInterface::StaticClass()))
		EventDelegates.Add(EventDelegate);

	UE_LOG(BodyStateLog, Log, TEXT("AddEventDelegate (%d)."), EventDelegates.Num());
}

void FBodyStateInputDevice::RemoveEventDelegate(UObject* EventDelegate)
{
	EventDelegates.Remove(EventDelegate);

	UE_LOG(BodyStateLog, Log, TEXT("RemoveEventDelegate (%d)."), EventDelegates.Num());
}*/

/************************************************************************/
/* Key Tick flow functions                                              */
/************************************************************************/
void FBodyStateInputDevice::Tick(float DeltaTime)
{
	//Tick - store delta time for BS refence

}

//Main loop event emitter
void FBodyStateInputDevice::SendControllerEvents()
{
	//HMDSamples->AddCurrentHMDSample();
	DispatchInput();
}

//End key tick flow functions

/************************************************************************/
/* Key Input functions                                                  */
/************************************************************************/
void FBodyStateInputDevice::DispatchInput()
{
	//TODO expand this
}

void FBodyStateInputDevice::DispatchEstimators()
{

}

void FBodyStateInputDevice::DispatchRecognizers()
{

}
