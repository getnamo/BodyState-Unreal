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

UBodyStateArm* UBodyStateSkeleton::LeftArm()
{
	UE_LOG(BodyStateLog, Warning, TEXT("Not implemented yet."));
	return nullptr;
}

UBodyStateArm* UBodyStateSkeleton::RightArm()
{
	UE_LOG(BodyStateLog, Warning, TEXT("Not implemented yet."));
	return nullptr;
}

UBodyStateLeg* UBodyStateSkeleton::LeftLeg()
{
	UE_LOG(BodyStateLog, Warning, TEXT("Not implemented yet."));
	return nullptr;
}

UBodyStateLeg* UBodyStateSkeleton::RightLeg()
{
	UE_LOG(BodyStateLog, Warning, TEXT("Not implemented yet."));
	return nullptr;
}

UBodyStateTorso* UBodyStateSkeleton::Torso()
{
	UE_LOG(BodyStateLog, Warning, TEXT("Not implemented yet."));
	return nullptr;
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
