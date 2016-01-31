// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "BodyStateBone.h"
#include "BodyStateArm.h"
#include "BodyStateLeg.h"
#include "BodyStateTorso.h"
#include "BodyStateEnums.h"
#include "BodyStateSkeleton.generated.h"


UCLASS()
class BODYSTATE_API UBodyStateSkeleton : public UObject
{
	GENERATED_UCLASS_BODY()

	//Storage of actual bones
	UPROPERTY(BlueprintReadOnly, Category = "BodyState Skeleton")
	TArray<UBodyStateBone*> Bones;		//All bones stored here


	//Convenience getters and object wrappers

	//We use a general concept hierarchy as a convenience wrapper around bones

	//Root
	UFUNCTION(BlueprintPure, Category = "BodyState Skeleton")
	UBodyStateBone* RootBone();

	//Arms & Hands
	UFUNCTION(BlueprintPure, Category = "BodyState Skeleton")
	UBodyStateArm* LeftArm();

	UFUNCTION(BlueprintPure, Category = "BodyState Skeleton")
	UBodyStateArm* RightArm();

	//Leg & Feet
	UFUNCTION(BlueprintPure, Category = "BodyState Skeleton")
	UBodyStateLeg* LeftLeg();

	UFUNCTION(BlueprintPure, Category = "BodyState Skeleton")
	UBodyStateLeg* RightLeg();

	//Spine & Head
	UFUNCTION(BlueprintPure, Category = "BodyState Skeleton")
	UBodyStateTorso* Torso();

	//Todo: implement contextual fetch for fingers / hands
	//UFUNCTION(BlueprintPure, Category = "BodyState Skeleton")
	//TArray<UBodyStateFinger> Fingers();

	//UFUNCTION(BlueprintPure, Category = "BodyState Skeleton")
	//TArray<UBodyStateHand> Hands();

	/*Get Bone data by enum*/
	UFUNCTION(BlueprintCallable, Category = "BodyState Skeleton")
	class UBodyStateBone* BoneForEnum(TEnumAsByte<BodyStateUEHumanoidBone> Bone);
};
