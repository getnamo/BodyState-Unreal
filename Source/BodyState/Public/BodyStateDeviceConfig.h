// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "BodyStateDeviceConfig.generated.h"


UENUM(BlueprintType)
enum BodyStateDeviceInputType
{
	INERTIAL_INPUT_TYPE,			//e.g. IMU with direct no external references
	CAMERA_MOUNTED_INPUT_TYPE,		//e.g. leap motion
	EXTERNAL_REFERENCE_INPUT_TYPE,	//e.g. lighthouse
	MIXED_INPUT_TYPE
};

UCLASS()
class BODYSTATE_API UBodyStateDeviceConfig : public UObject
{
	GENERATED_UCLASS_BODY()

	UPROPERTY()
	FString Name;

	UPROPERTY()
	TEnumAsByte<BodyStateDeviceInputType> InputType;
};
