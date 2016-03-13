#pragma once


#include "BodyStateBone.generated.h"

UCLASS(BlueprintType)
class BODYSTATE_API UBodyStateBone : public UObject
{
	GENERATED_UCLASS_BODY()

	/** Human readable name */
	UPROPERTY(BlueprintReadWrite, Category = "BodyState Bone")
	FString Name;

	/** Parent Bone - If available */
	UPROPERTY(BlueprintReadWrite, Category = "BodyState Bone")
	UBodyStateBone* Parent;

	/** Blending Alpha */
	UPROPERTY(BlueprintReadWrite, Category = "BodyState Bone")
	float Alpha;

	/** Tracking Confidence */
	UPROPERTY(BlueprintReadWrite, Category = "BodyState Bone")
	float Confidence;

	/** Bone Length */
	UPROPERTY(BlueprintReadWrite, Category = "BodyState Bone")
	float Length;

	/** Transform holding main bone values*/
	UPROPERTY(BlueprintReadWrite, Category = "BodyState Bone")
	FTransform Transform;

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


	//Convenience Functions
	UFUNCTION(BlueprintCallable, Category = "BodyState Bone")
	virtual bool Enabled();

	UFUNCTION(BlueprintCallable, Category = "BodyState Bone")
	virtual void SetEnabled(bool enable = true);

	UFUNCTION(BlueprintCallable, Category = "BodyState Bone")
	virtual void ShiftBone(FVector ShiftAmount);

	UFUNCTION(BlueprintCallable, Category = "BodyState Bone")
	virtual void ChangeBasis(FRotator PreBase, FRotator PostBase, bool adjustVectors = true);
};