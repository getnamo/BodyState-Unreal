#pragma once

#include "BodyStatePrivatePCH.h"
#include "IBodyState.h"

class FBodyState : public IBodyState
{
public:
	virtual TSharedPtr< class IInputDevice > CreateInputDevice(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler);

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	//virtual struct LeapControllerData* ControllerData() override;
	//virtual void AddEventDelegate(UObject* EventDelegate) override;
	//virtual void RemoveEventDelegate(UObject* EventDelegate) override;
	
	bool IsActive();

	TSharedPtr< class FBodyStateInputDevice > BodyStateInputDevice;

private:
	bool bActive = false;
};