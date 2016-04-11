#pragma once

#include "BodyStateBone.h"
#include "BodyStateEnums.h"
#include "BodyStateFinger.generated.h"



UCLASS(BlueprintType)
class BODYSTATE_API UBodyStateFinger : public UObject
{
	GENERATED_UCLASS_BODY()

	//Not typically used in basic animation
	UPROPERTY(BlueprintReadOnly, Category = "BodyState Finger")
	UBodyStateBone* Metacarpal;

	UPROPERTY(BlueprintReadOnly, Category = "BodyState Finger")
	UBodyStateBone* Proximal;

	UPROPERTY(BlueprintReadOnly, Category = "BodyState Finger")
	UBodyStateBone* Intermediate;

	UPROPERTY(BlueprintReadOnly, Category = "BodyState Finger")
	UBodyStateBone* Distal;


	UPROPERTY(BlueprintReadWrite, Category = "BodyState Finger")
	float Alpha;

	UPROPERTY(BlueprintReadWrite, Category = "BodyState Finger")
	float Confidence;


	UFUNCTION(BlueprintCallable, Category = "BodyState Finger")
	bool Enabled();

	UFUNCTION(BlueprintCallable, Category = "BodyState Finger")
	void SetEnabled(bool Enable = true);

	UFUNCTION(BlueprintCallable, Category = "BodyState Finger")
	void TranslateFinger(FVector Shift);

	UFUNCTION(BlueprintCallable, Category = "BodyState Finger")
	void ChangeBasis(FRotator PreBase, FRotator PostBase, bool AdjustVectors = true);
};