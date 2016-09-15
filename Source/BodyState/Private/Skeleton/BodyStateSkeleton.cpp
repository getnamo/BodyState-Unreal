// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "BodyStatePrivatePCH.h"
#include "BodyStateSkeleton.h"

UBodyStateSkeleton::UBodyStateSkeleton(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	//Todo: build

	//add a bone for each possible bone in the skeleton
	for (int i = 0; i < BodyStateUEHumanoidBone::BONES_COUNT; i++)
	{
		//Make bone
		auto Bone = NewObject<UBodyStateBone>(this, *FString::Printf(TEXT("BSBone%d"),i));

		//Add bone
		Bones.Add(Bone);
	}
}

UBodyStateBone* UBodyStateSkeleton::RootBone()
{
	return Bones[BodyStateUEHumanoidBone::BONE_ROOT];
}

UBodyStateBone* UBodyStateSkeleton::LeftHand()
{
	return Bones[BodyStateUEHumanoidBone::BONE_HAND_L];
}

UBodyStateBone* UBodyStateSkeleton::RightHand()
{
	return Bones[BodyStateUEHumanoidBone::BONE_HAND_R];
}

UBodyStateBone* UBodyStateSkeleton::Head()
{
	return Bones[BodyStateUEHumanoidBone::BONE_SPINE_03];
}

UBodyStateBone* UBodyStateSkeleton::BoneForEnum(TEnumAsByte<BodyStateUEHumanoidBone> Bone)
{
	return Bones[Bone];
}

class UBodyStateBone* UBodyStateSkeleton::BoneNamed(const FString& Name)
{
	UE_LOG(BodyStateLog, Log, TEXT("Not implemented yet."));
	return nullptr;
}
