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
	TArray<FNamedBoneData> TrackedBones;

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

	//Convenience getters and object wrappers - offers a convenient perspective on the data

	//We use a general concept hierarchy as a convenience wrapper around bones

	//Root
	UFUNCTION(BlueprintPure, Category = "BodyState Skeleton")
	UBodyStateBone* RootBone();

	//Convenience Links

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


	//Replication
	TArray<FNamedBoneData> TrackedBoneData();
	TArray<FNamedBoneMeta> UniqueBoneMeta();
};
