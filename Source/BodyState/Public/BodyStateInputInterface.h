// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once


#include "BodyStateInputInterface.generated.h"

UINTERFACE(MinimalAPI)
class UBodyStateInputInterface : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class IBodyStateInputInterface
{
	GENERATED_IINTERFACE_BODY()

public:

	/* Requests your device to update the skeleton. You can use this BS polling method or push updates to your skeleton*/
	//UFUNCTION(BlueprintNativeEvent, Category = "Body State Poll Interface")
	//	void UpdateInput(int32 DeviceID, class UBodyStateSkeleton* Skeleton);	//todo: define
};