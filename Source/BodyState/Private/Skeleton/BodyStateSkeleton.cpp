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

//All types of bones
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

//Only basic ones
TArray<FNamedTransform> UBodyStateSkeleton::TrackedBasicBones()
{
	TArray<FNamedTransform> ResultArray;

	for (int i = 0; i < Bones.Num(); i++)
	{
		if (Bones[i]->IsTracked() && !Bones[i]->BoneData.AdvancedBoneType)
		{
			FNamedTransform NamedData;
			NamedData.Transform = Bones[i]->BoneData.Transform;
			NamedData.Name = EBodyStateUEHumanoidBone(i);

			ResultArray.Add(NamedData);
		}
	}

	return ResultArray;
}

//Only advanced ones
TArray<FNamedBoneData> UBodyStateSkeleton::TrackedAdvancedBones()
{
	TArray<FNamedBoneData> ResultArray;

	for (int i = 0; i < Bones.Num(); i++)
	{
		if (Bones[i]->IsTracked() && Bones[i]->BoneData.AdvancedBoneType)
		{
			FNamedBoneData NamedData;
			NamedData.Data = Bones[i]->BoneData;
			NamedData.Name = EBodyStateUEHumanoidBone(i);

			ResultArray.Add(NamedData);
		}
	}

	return ResultArray;
}

TArray<FNamedBoneMeta> UBodyStateSkeleton::UniqueBoneMetas()
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

FNamedSkeletonData UBodyStateSkeleton::GetMinimalNamedSkeletonData()
{
	FNamedSkeletonData NamedSkeleton;

	NamedSkeleton.TrackedBasicBones = TrackedBasicBones();
	NamedSkeleton.TrackedAdvancedBones = TrackedAdvancedBones();
	NamedSkeleton.UniqueMetas = UniqueBoneMetas();

	return NamedSkeleton;
}

void UBodyStateSkeleton::ResetToDefaultSkeleton()
{
	for (int i = 0; i < Bones.Num(); i++)
	{
		Bones[i]->Initialize();
	}
}

void UBodyStateSkeleton::SetDataForBone(const FBodyStateBoneData& BoneData, TEnumAsByte<EBodyStateUEHumanoidBone> Bone)
{
	Bones[Bone]->BoneData = BoneData;
}

void UBodyStateSkeleton::SetTransformForBone(const FTransform& Transform, TEnumAsByte<EBodyStateUEHumanoidBone> Bone)
{
	Bones[Bone]->BoneData.SetFromTransform(Transform);
}

void UBodyStateSkeleton::SetMetaForBone(const FBodyStateBoneMeta& BoneMeta, TEnumAsByte<EBodyStateUEHumanoidBone> Bone)
{
	Bones[Bone]->Meta = BoneMeta;
}

void UBodyStateSkeleton::SetFromNamedSkeletonData(const FNamedSkeletonData& NamedSkeletonData)
{
	//Clear our skeleton data
	ResetToDefaultSkeleton();

	//Set the tracked bone data

	//Basic
	for (int i = 0; i < NamedSkeletonData.TrackedBasicBones.Num(); i++)
	{
		const FNamedTransform& NamedData = NamedSkeletonData.TrackedBasicBones[i];
		SetTransformForBone(NamedData.Transform, NamedData.Name);
	}

	//Advanced
	for (int i = 0; i < NamedSkeletonData.TrackedAdvancedBones.Num(); i++)
	{
		const FNamedBoneData& NamedData = NamedSkeletonData.TrackedAdvancedBones[i];
		SetDataForBone(NamedData.Data, NamedData.Name);
	}

	//Add the unique meta for each bone
	for (int i = 0; i < NamedSkeletonData.UniqueMetas.Num(); i++)
	{
		const FNamedBoneMeta& NamedMeta = NamedSkeletonData.UniqueMetas[i];
		SetMetaForBone(NamedMeta.Meta, NamedMeta.Name);
	}
}

bool UBodyStateSkeleton::ServerUpdateBodyState_Validate(FNamedSkeletonData BodyState)
{
	return true;
}

void UBodyStateSkeleton::ServerUpdateBodyState_Implementation(const FNamedSkeletonData InBodyStateSkeleton)
{
	// Multi cast to everybody
	Multi_UpdateBodyState(InBodyStateSkeleton);
}

void UBodyStateSkeleton::Multi_UpdateBodyState_Implementation(const FNamedSkeletonData InBodyStateSkeleton)
{
	SetFromNamedSkeletonData(InBodyStateSkeleton);
}
