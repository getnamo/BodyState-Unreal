// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "BodyStatePrivatePCH.h"
#include "BodyStateBPLibrary.h"

UBodyStateBPLibrary::UBodyStateBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

int32 UBodyStateBPLibrary::DeviceAttached(UBodyStateDeviceConfig* Configuration, TScriptInterface<IBodyStateInputInterface> InputCallbackDelegate)
{
	return -1;
}

bool UBodyStateBPLibrary::DeviceDetached(int32 DeviceID)
{
	return false;
}

