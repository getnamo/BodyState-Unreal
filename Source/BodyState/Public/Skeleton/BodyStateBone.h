#pragma once

#include "BodyStateBone.generated.h"


USTRUCT(BlueprintType)
struct BODYSTATE_API FBodyStateBoneMeta
{
	GENERATED_USTRUCT_BODY()

	/** Is this meta data distinct from parents? */
	UPROPERTY()
	bool ParentDistinctMeta;

	/** Name of tracking type*/
	UPROPERTY()
	FString TrackingType;

	/** Accuracy in cm of tracking data if distinct */
	UPROPERTY()
	float Accuracy;

	FBodyStateBoneMeta()
	{
		ParentDistinctMeta = false;
		TrackingType = FString(TEXT("Unknown"));
		Accuracy = 0.f;
	}
};

USTRUCT(BlueprintType)
struct BODYSTATE_API FBodyStateBoneData
{
	GENERATED_USTRUCT_BODY()

	/** Transform holding main bone values*/
	UPROPERTY(BlueprintReadWrite, Category = "BodyState Bone Data")
	FTransform Transform;

	/** Tracking Confidence */
	UPROPERTY(BlueprintReadWrite, Category = "BodyState Bone Data")
	float Confidence;

	FBodyStateBoneData()
	{
		Transform.SetScale3D(FVector(1.f));
		Confidence = 0.f;
	}
};

UCLASS(BlueprintType)
class BODYSTATE_API UBodyStateBone : public UObject
{
	GENERATED_UCLASS_BODY()

	/** Human readable name */
	UPROPERTY(BlueprintReadWrite, Category = "BodyState Bone")
	FString Name;

	UPROPERTY(BlueprintReadWrite, Category = "BodyState Bone")
	FBodyStateBoneData BoneData;

	UPROPERTY(BlueprintReadWrite, Category = "BodyState Bone")
	FBodyStateBoneMeta Meta;

	/** Parent Bone - If available */
	UPROPERTY(BlueprintReadWrite, Category = "BodyState Bone")
	UBodyStateBone* Parent;

	/** Children Bones - If available */
	UPROPERTY(BlueprintReadWrite, Category = "BodyState Bone")
	TArray<UBodyStateBone*> Children;

	/** Blending Alpha */
	UPROPERTY(BlueprintReadWrite, Category = "BodyState Bone")
	float Alpha;

	/** Bone Length */
	UPROPERTY(BlueprintReadWrite, Category = "BodyState Bone Data")
	float Length;

	/** Bone Position */
	UFUNCTION(BlueprintPure, Category = "BodyState Bone")
	FVector Position();

	UFUNCTION(BlueprintCallable, Category = "BodyState Bone")
	void SetPosition(const FVector& InPosition);

	/** Bone Orientation */
	UFUNCTION(BlueprintPure, Category = "BodyState Bone")
	FRotator Orientation();

	UFUNCTION(BlueprintCallable, Category = "BodyState Bone")
	void SetOrientation(const FRotator& InOrientation);

	/** Bone Scale */
	UFUNCTION(BlueprintPure, Category = "BodyState Bone")
	FVector Scale();

	UFUNCTION(BlueprintCallable, Category = "BodyState Bone")
	void SetScale(const FVector& InScale);


	/** Re-initialize from bone data */
	void InitializeFromBoneData(const FBodyStateBoneData& InData);
	void Initialize();

	//Convenience Functions
	UFUNCTION(BlueprintCallable, Category = "BodyState Bone")
	virtual bool Enabled();

	UFUNCTION(BlueprintCallable, Category = "BodyState Bone")
	virtual void SetEnabled(bool Enable = true);

	UFUNCTION(BlueprintCallable, Category = "BodyState Bone")
	virtual void ShiftBone(FVector ShiftAmount);

	UFUNCTION(BlueprintCallable, Category = "BodyState Bone")
	virtual void ChangeBasis(FRotator PreBase, FRotator PostBase, bool AdjustVectors = true);

	UFUNCTION(BlueprintPure, Category = "BodyState Bone")
	virtual bool IsTracked();
};