// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "BodyStatePrivatePCH.h"
#include "BodyStateDevice.h"
#include "BodyStateDeviceConfig.h"
#include "BodyStateSkeleton.h"

UBodyStateDevice::UBodyStateDevice(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	InputCallbackDelegate = nullptr;	//ensure this is null at start to stop debug null

	Skeleton = ObjectInitializer.CreateDefaultSubobject<UBodyStateSkeleton>(this, "Skeleton");
	Config = ObjectInitializer.CreateDefaultSubobject<UBodyStateDeviceConfig>(this, "Config");
}