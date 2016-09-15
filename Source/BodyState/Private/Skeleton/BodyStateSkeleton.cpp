// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "BodyStatePrivatePCH.h"
#include "BodyStateSkeleton.h"

UBodyStateSkeleton::UBodyStateSkeleton(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	//Todo: build

	//add a bone for each possible bone in the skeleton
	for (int i = 0; i < EBodyStateUEHumanoidBone::BONES_COUNT; i++)
	{
		//Make bone
		auto Bone = NewObject<UBodyStateBone>(this, *FString::Printf(TEXT("BSBone%d"),i));

		//Add bone
		Bones.Add(Bone);
	}
}

UBodyStateBone* UBodyStateSkeleton::RootBone()
{
	return Bones[EBodyStateUEHumanoidBone::BONE_ROOT];
}

UBodyStateBone* UBodyStateSkeleton::LeftHand()
{
	return Bones[EBodyStateUEHumanoidBone::BONE_HAND_L];
}

UBodyStateBone* UBodyStateSkeleton::RightHand()
{
	return Bones[EBodyStateUEHumanoidBone::BONE_HAND_R];
}

UBodyStateBone* UBodyStateSkeleton::Head()
{
	return Bones[EBodyStateUEHumanoidBone::BONE_HEAD];
}

UBodyStateBone* UBodyStateSkeleton::BoneForEnum(TEnumAsByte<EBodyStateUEHumanoidBone> Bone)
{
	return Bones[Bone];
}

class UBodyStateBone* UBodyStateSkeleton::BoneNamed(const FString& Name)
{
	UE_LOG(BodyStateLog, Log, TEXT("Not implemented yet."));
	return nullptr;
}

TArray<FNamedBoneData> UBodyStateSkeleton::TrackedBoneData()
{
	TArray<FNamedBoneData> ResultArray;

	for (int i = 0; i < Bones.Num();i++)
	{
		if (Bones[i]->IsTracked())
		{
			FNamedBoneData NamedData;
			NamedData.Data = Bones[i]->BoneData;
			NamedData.Name = EBodyStateUEHumanoidBone(i);

			ResultArray.Add(NamedData);
		}
	}

	return ResultArray;
}

TArray<FNamedBoneMeta> UBodyStateSkeleton::UniqueBoneMeta()
{
	TArray<FNamedBoneMeta> ResultArray;

	for (int i = 0; i < Bones.Num(); i++)
	{
		if (Bones[i]->Meta.ParentDistinctMeta)
		{
			FNamedBoneMeta NamedMeta;
			NamedMeta.Meta = Bones[i]->Meta;
			NamedMeta.Name = EBodyStateUEHumanoidBone(i);

			ResultArray.Add(NamedMeta);
		}
	}

	return ResultArray;
}
