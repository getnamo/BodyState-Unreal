// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "BodyStateDeviceConfig.generated.h"


UENUM(BlueprintType)
enum BodyStateDeviceInputType
{
	IMU_INPUT_TYPE,
	POSITION_INPUT_TYPE,
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
