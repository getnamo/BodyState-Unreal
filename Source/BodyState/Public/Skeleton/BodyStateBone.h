#pragma once


#include "BodyStateBone.generated.h"

UCLASS(BlueprintType)
class BODYSTATE_API UBodyStateBone : public UObject
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "BodyState Bone")
	UBodyStateBone* Parent;

	UPROPERTY(BlueprintReadWrite, Category = "BodyState Bone")
	FVector Position;

	UPROPERTY(BlueprintReadWrite, Category = "BodyState Bone")
	FRotator Orientation;

	UPROPERTY(BlueprintReadWrite, Category = "BodyState Bone")
	FVector Scale;


	UPROPERTY(BlueprintReadWrite, Category = "BodyState Bone")
	float Length;

	UPROPERTY(BlueprintReadWrite, Category = "BodyState Bone")
	float Alpha;

	UPROPERTY(BlueprintReadWrite, Category = "BodyState Bone")
	float Confidence;


	UFUNCTION(BlueprintCallable, Category = "BodyState Bone")
	void SetFromTransform(const FTransform& in);

	UFUNCTION(BlueprintCallable, Category = "BodyState Bone")
	FTransform GetTransform();


	UFUNCTION(BlueprintCallable, Category = "BodyState Bone")
	virtual bool Enabled();

	UFUNCTION(BlueprintCallable, Category = "BodyState Bone")
	virtual void SetEnabled(bool enable = true);


	UFUNCTION(BlueprintCallable, Category = "BodyState Bone")
	virtual void TranslateBone(FVector shift);

	UFUNCTION(BlueprintCallable, Category = "BodyState Bone")
	virtual void ChangeBasis(FRotator PreBase, FRotator PostBase, bool adjustVectors = true);
};