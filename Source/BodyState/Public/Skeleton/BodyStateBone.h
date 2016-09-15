#pragma once

#include "BodyStateBone.generated.h"


USTRUCT(BlueprintType)
struct BODYSTATE_API FBodyStateBoneMeta
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	bool Distinct;	//if not look into parents meta

	UPROPERTY()
	FString TrackingType;

	UPROPERTY()
	float Accuracy;

	UPROPERTY()
	float Confidence;
};

USTRUCT(BlueprintType)
struct BODYSTATE_API FBodyStateBoneData
{
	GENERATED_USTRUCT_BODY()

	/** Transform holding main bone values*/
	UPROPERTY(BlueprintReadWrite, Category = "BodyState Bone Data")
	FTransform Transform;

	/** Bone Length */
	UPROPERTY(BlueprintReadWrite, Category = "BodyState Bone Data")
	float Length;

	/** Tracking Confidence */
	UPROPERTY(BlueprintReadWrite, Category = "BodyState Bone Data")
	float Confidence;

	FBodyStateBoneData()
	{
		Transform.SetScale3D(FVector(1.f));
		Length = 0.f;
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

	/** Parent Bone - If available */
	UPROPERTY(BlueprintReadWrite, Category = "BodyState Bone")
	UBodyStateBone* Parent;

	/** Children Bones - If available */
	UPROPERTY(BlueprintReadWrite, Category = "BodyState Bone")
	TArray<UBodyStateBone*> Children;

	/** Blending Alpha */
	UPROPERTY(BlueprintReadWrite, Category = "BodyState Bone")
	float Alpha;

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
	UFUNCTION(BlueprintCallable, Category = "BodyState Bone")
	void InitializeFromBoneData(const FBodyStateBoneData& InData);

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