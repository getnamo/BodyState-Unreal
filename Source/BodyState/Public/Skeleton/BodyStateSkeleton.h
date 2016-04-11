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

	//Note: Storage of actual bone data should be here
	UPROPERTY(BlueprintReadOnly, Category = "BodyState Skeleton")
	TArray<UBodyStateBone*> Bones;		//All bones stored here

	//internal lookup for the bones
	TMap<BodyStateUEHumanoidBone, UBodyStateBone*> BoneMap;

	//Used for reference point calibration e.g. hydra base origin
	UPROPERTY(BlueprintReadOnly, Category = "BodyState Skeleton")
	FTransform RootOffset;


	//Convenience getters and object wrappers - offers a convenient perspective on the data

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

	//Todo: implement contextual fetch for fingers / hands / head
	//UFUNCTION(BlueprintPure, Category = "BodyState Skeleton")
	//TArray<UBodyStateFinger> Fingers();

	//UFUNCTION(BlueprintPure, Category = "BodyState Skeleton")
	//TArray<UBodyStateHand> Hands();

	//UFUNCTION(BlueprintPure, Category = "BodyState Skeleton")
	//UBodyStateBone* Head();

	/*Get Bone data by enum*/
	UFUNCTION(BlueprintPure, Category = "BodyState Skeleton")
	class UBodyStateBone* BoneForEnum(TEnumAsByte<BodyStateUEHumanoidBone> Bone);

	/*Get Bone data by name matching*/
	UFUNCTION(BlueprintPure, Category = "BodyState Skeleton")
	class UBodyStateBone* BoneNamed(const FString& Name);
};
