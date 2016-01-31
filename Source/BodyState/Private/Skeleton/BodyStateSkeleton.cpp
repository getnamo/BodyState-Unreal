// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "BodyStatePrivatePCH.h"
#include "BodyStateSkeleton.h"

UBodyStateSkeleton::UBodyStateSkeleton(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UBodyStateBone* UBodyStateSkeleton::RootBone()
{
	return nullptr;
}

UBodyStateArm* UBodyStateSkeleton::LeftArm()
{
	return nullptr;
}

UBodyStateArm* UBodyStateSkeleton::RightArm()
{
	return nullptr;
}

UBodyStateLeg* UBodyStateSkeleton::LeftLeg()
{
	return nullptr;
}

UBodyStateLeg* UBodyStateSkeleton::RightLeg()
{
	return nullptr;
}

UBodyStateTorso* UBodyStateSkeleton::Torso()
{
	return nullptr;
}

UBodyStateBone* UBodyStateSkeleton::BoneForEnum(TEnumAsByte<BodyStateUEHumanoidBone> Bone)
{
	return nullptr;
}

class UBodyStateBone* UBodyStateSkeleton::BoneNamed(const FString& Name)
{
	return nullptr;
}
