#pragma once

#include "BodyStateFinger.h"
#include "BodyStateArm.generated.h"

UCLASS(BlueprintType)
class BODYSTATE_API UBodyStateArm : public UObject
{
	GENERATED_UCLASS_BODY()

	//Hand Properties
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "BodyState Hand")
	float Alpha;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "BodyState Hand")
	float Confidence;

	//Fingers
	UPROPERTY(BlueprintReadOnly, Category = "BodyState Hand Finger")
	UBodyStateFinger* Thumb;

	UPROPERTY(BlueprintReadOnly, Category = "BodyState Hand Finger")
	UBodyStateFinger* Index;
	
	UPROPERTY(BlueprintReadOnly, Category = "BodyState Hand Finger")
	UBodyStateFinger* Middle;

	UPROPERTY(BlueprintReadOnly, Category = "BodyState Hand Finger")
	UBodyStateFinger* Ring;

	UPROPERTY(BlueprintReadOnly, Category = "BodyState Hand Finger")
	UBodyStateFinger* Pinky;
	
	//Arm and Wrist, NB: Consider moving this up the skeletal tree, for leap this is sufficient
	UPROPERTY(BlueprintReadOnly, Category = "BodyState Hand")
	UBodyStateBone* Wrist;

	UPROPERTY(BlueprintReadOnly, Category = "BodyState Hand")
	UBodyStateBone* Palm;

	UPROPERTY(BlueprintReadOnly, Category = "BodyState Hand")
	UBodyStateBone* LowerArm;

	UFUNCTION(BlueprintCallable, Category = "BodyState Hand")
	bool Enabled();

	UFUNCTION(BlueprintCallable, Category = "BodyState Hand")
	void SetEnabled(bool enable = true);

	UFUNCTION(BlueprintCallable, Category = "BodyState Hand")
	void TranslateArm(FVector shift);

	UFUNCTION(BlueprintCallable, Category = "BodyState Hand")
	void ChangeBasis(FRotator PreBase, FRotator PostBase, bool adjustVectors = true);

};