// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "BodyStateDevice.generated.h"

UCLASS()
class BODYSTATE_API UBodyStateDevice : public UObject
{
	GENERATED_UCLASS_BODY()

	UPROPERTY()
	int32 DeviceId;

	UPROPERTY()
	class UBodyStateDeviceConfig* Config;

	UPROPERTY()
	class UBodyStateSkeleton* Skeleton;

	UObject* InputCallbackDelegate;
};
