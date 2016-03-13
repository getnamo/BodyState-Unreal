#pragma once

#include "BodyStatePrivatePCH.h"
#include "IInputDevice.h"

class FBodyStateInputDevice : public IInputDevice
{
public:
	FBodyStateInputDevice(const TSharedRef< FGenericApplicationMessageHandler >& MessageHandler);

	/** Tick the interface (e.g. check for new controllers) */
	virtual void Tick(float DeltaTime) override;

	/** Poll for controller state and send events if needed */
	virtual void SendControllerEvents() override;

	/** Actual Tick functions, abstracted so we have control over flow*/
	void DispatchInput();		//raw input
	void DispatchEstimators();	//merge and estimation
	void DispatchRecognizers();	//recognition ( heavy parts may run off-thread)

	/** Set which MessageHandler will get the events from SendControllerEvents. */
	virtual void SetMessageHandler(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler) override;

	/** Exec handler to allow console commands to be passed through for debugging */
	virtual bool Exec(UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Ar) override;

	/** IForceFeedbackSystem pass through functions **/
	virtual void SetChannelValue(int32 ControllerId, FForceFeedbackChannelType ChannelType, float Value) override;
	virtual void SetChannelValues(int32 ControllerId, const FForceFeedbackValues &values) override;

	virtual ~FBodyStateInputDevice();

	TSharedRef< FGenericApplicationMessageHandler > MessageHandler;

	/** Main Controller data and settings reference*/
	//LeapControllerData ControllerData;
	
	//Event Delegation
	void AddEventDelegate(UObject* EventDelegate);
	void RemoveEventDelegate(UObject* EventDelegate);

private:
	//Private UProperties
	TArray<UObject*> EventDelegates;		//delegate storage
	class HMDSnapshotSamples* HMDSamples;	//timewarp

	//Private utility methods
	void CallFunctionOnDelegates(TFunction< void(UObject*)> InFunction);	//lambda multi-cast convenience wrapper
	bool EmitKeyUpEventForKey(FKey Key, int32 User, bool Repeat);
	bool EmitKeyDownEventForKey(FKey Key, int32 User, bool Repeat);
	bool EmitAnalogInputEventForKey(FKey Key, float Value, int32 User, bool Repeat);
};