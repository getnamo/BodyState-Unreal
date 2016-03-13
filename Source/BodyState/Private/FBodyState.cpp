// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "BodyStatePrivatePCH.h"
#include "FBodyStateInputDevice.h"
#include "FBodyState.h"

#undef LOCTEXT_NAMESPACE

#define LOCTEXT_NAMESPACE "BodyState"
#define PLUGIN_VERSION "0.1.0"

void FBodyState::StartupModule()
{
	// This code will execute after your module is loaded into memory (but after global variables are initialized, of course.)
	// Custom module-specific init can go here.

	// IMPORTANT: This line registers our input device module with the engine.
	//	      If we do not register the input device module with the engine,
	//	      the engine won't know about our existence. Which means 
	//	      CreateInputDevice never gets called, which means the engine
	//	      will never try to poll for events from our custom input device.
	IModularFeatures::Get().RegisterModularFeature(IInputDeviceModule::GetModularFeatureName(), this);
}

void FBodyState::ShutdownModule()
{
	// Unregister our input device module
	IModularFeatures::Get().UnregisterModularFeature(IInputDeviceModule::GetModularFeatureName(), this);
}

TSharedPtr< class IInputDevice > FBodyState::CreateInputDevice(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler)
{
	UE_LOG(BodyStateLog, Log, TEXT("CreateInputDevice BodyState version %s"), TEXT(PLUGIN_VERSION));

	//Expose all of our input mapping keys to the engine
	//EKeys::AddKey(FKeyDetails(EKeysLeap::LeapLeftPinch, LOCTEXT("LeapLeftPinch", "Leap Left Pinch"), FKeyDetails::GamepadKey));

	BodyStateInputDevice = MakeShareable(new FBodyStateInputDevice(InMessageHandler));

	bActive = true;

	return TSharedPtr< class IInputDevice >(BodyStateInputDevice);
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FBodyState, BodyState)