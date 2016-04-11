// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "BodyStatePrivatePCH.h"
#include "BodyStateBPLibrary.h"

UBodyStateBPLibrary::UBodyStateBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
	UE_LOG(LogClass, Log, TEXT("UBodyStateBPLibrary called"));
}

int32 UBodyStateBPLibrary::DeviceAttached(UBodyStateDeviceConfig* Configuration, TScriptInterface<IBodyStateInputInterface> InputCallbackDelegate)
{
	UE_LOG(BodyStateLog, Warning, TEXT("Not implemented yet."));
	return -1;
}

bool UBodyStateBPLibrary::DeviceDetached(int32 DeviceID)
{
	UE_LOG(BodyStateLog, Warning, TEXT("Not implemented yet."));
	return false;
}

UBodyStateSkeleton* UBodyStateBPLibrary::SkeletonForDevice(int32 DeviceID)
{
	UE_LOG(BodyStateLog, Warning, TEXT("Not implemented yet."));
	return nullptr;
}

bool UBodyStateBPLibrary::AttachMergeAlgorithm(TFunction< void()> InFunction)
{
	UE_LOG(BodyStateLog, Warning, TEXT("Not implemented yet."));
	return false;
}

