// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "BodyStateBone.h"
#include "BodyStateEnums.h"
#include "BodyStateSkeleton.generated.h"

//Used for replication
USTRUCT()
struct BODYSTATE_API FNamedBoneData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	FBodyStateBoneData Data;

	UPROPERTY()
	TEnumAsByte<EBodyStateUEHumanoidBone> Name;
};

//Used for replication
USTRUCT()
struct BODYSTATE_API FNamedTransform
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	FTransform Transform;

	UPROPERTY()
	TEnumAsByte<EBodyStateUEHumanoidBone> Name;
};

//Used for replication
USTRUCT()
struct BODYSTATE_API FNamedBoneMeta
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	FBodyStateBoneMeta Meta;

	UPROPERTY()
	TEnumAsByte<EBodyStateUEHumanoidBone> Name;
};

//Used for replication
USTRUCT()
struct BODYSTATE_API FNamedSkeletonData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	TArray<FNamedBoneData> TrackedAdvancedBones;

	UPROPERTY()
	TArray<FNamedTransform> TrackedBasicBones;

	UPROPERTY()
	TArray<FNamedBoneMeta> UniqueMetas;
};


UCLASS()
class BODYSTATE_API UBodyStateSkeleton : public UObject
{
	GENERATED_UCLASS_BODY()

	//Note: Storage of actual bone data should be here
	UPROPERTY(BlueprintReadOnly, Category = "BodyState Skeleton")
	TArray<UBodyStateBone*> Bones;		//All bones stored here

	//internal lookup for the bones
	TMap<EBodyStateUEHumanoidBone, UBodyStateBone*> BoneMap;

	//Used for reference point calibration e.g. hydra base origin
	UPROPERTY(BlueprintReadOnly, Category = "BodyState Skeleton")
	FTransform RootOffset;

	//Convenience bone getters

	//Root
	UFUNCTION(BlueprintPure, Category = "BodyState Skeleton")
	UBodyStateBone* RootBone();

	//Arms & Hands
	UFUNCTION(BlueprintPure, Category = "BodyState Skeleton")
	UBodyStateBone* LeftHand();

	UFUNCTION(BlueprintPure, Category = "BodyState Skeleton")
	UBodyStateBone* RightHand();

	//Spine & Head
	UFUNCTION(BlueprintPure, Category = "BodyState Skeleton")
	UBodyStateBone* Head();

	/*Get Bone data by enum*/
	UFUNCTION(BlueprintPure, Category = "BodyState Skeleton")
	class UBodyStateBone* BoneForEnum(TEnumAsByte<EBodyStateUEHumanoidBone> Bone);

	/*Get Bone data by name matching*/
	UFUNCTION(BlueprintPure, Category = "BodyState Skeleton")
	class UBodyStateBone* BoneNamed(const FString& Name);


	//Replication and Setting Data

	//Setting Bone Data
	UFUNCTION(BlueprintCallable, Category = "BodyState Skeleton Setting")
	void ResetToDefaultSkeleton();

	UFUNCTION(BlueprintCallable, Category = "BodyState Skeleton Setting")
	void SetDataForBone(const FBodyStateBoneData& BoneData, TEnumAsByte<EBodyStateUEHumanoidBone> Bone);

	UFUNCTION(BlueprintCallable, Category = "BodyState Skeleton Setting")
	void SetTransformForBone(const FTransform& Transform, TEnumAsByte<EBodyStateUEHumanoidBone> Bone);

	UFUNCTION(BlueprintCallable, Category = "BodyState Skeleton Setting")
	void SetMetaForBone(const FBodyStateBoneMeta& BoneMeta, TEnumAsByte<EBodyStateUEHumanoidBone> Bone);


	FNamedSkeletonData GetMinimalNamedSkeletonData();	//key replication getter
	void SetFromNamedSkeletonData(const FNamedSkeletonData& NamedSkeletonData);	//key replication setter

	//Replication
	UFUNCTION(Unreliable, Server, WithValidation)
	void ServerUpdateBodyState(const FNamedSkeletonData InBodyStateSkeleton);

	UFUNCTION(NetMulticast, Unreliable)
	void Multi_UpdateBodyState(const FNamedSkeletonData InBodyStateSkeleton);

protected:

	TArray<FNamedBoneData> TrackedBoneData();
	TArray<FNamedTransform> TrackedBasicBones();
	TArray<FNamedBoneData> TrackedAdvancedBones();
	TArray<FNamedBoneMeta> UniqueBoneMetas();
};
