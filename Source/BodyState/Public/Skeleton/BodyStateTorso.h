#pragma once

#include "BodyStateTorso.generated.h"

UCLASS(BlueprintType)
class BODYSTATE_API UBodyStateTorso : public UObject
{
	GENERATED_UCLASS_BODY()

	//Hand Properties
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "BodyState Torso")
	float Alpha;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "BodyState Torso")
	float Confidence;


	//Arm and Wrist, NB: Consider moving this up the skeletal tree, for leap this is sufficient
	UPROPERTY(BlueprintReadOnly, Category = "BodyState Torso")
	UBodyStateBone* Pelvis;

	UPROPERTY(BlueprintReadOnly, Category = "BodyState Torso")
	UBodyStateBone* SpineLower;

	UPROPERTY(BlueprintReadOnly, Category = "BodyState Torso")
	UBodyStateBone* SpineMiddle;

	UPROPERTY(BlueprintReadOnly, Category = "BodyState Torso")
	UBodyStateBone* SpineUpper;

	UPROPERTY(BlueprintReadOnly, Category = "BodyState Torso")
	UBodyStateBone* Neck;

	UPROPERTY(BlueprintReadOnly, Category = "BodyState Torso")
	UBodyStateBone* Head;


	UFUNCTION(BlueprintCallable, Category = "BodyState Torso")
	bool Enabled();

	UFUNCTION(BlueprintCallable, Category = "BodyState Torso")
	void SetEnabled(bool Enable = true);

	UFUNCTION(BlueprintCallable, Category = "BodyState Torso")
	void TranslateHand(FVector Shift);

	UFUNCTION(BlueprintCallable, Category = "BodyState Torso")
	void ChangeBasis(FRotator PreBase, FRotator PostBase, bool AdjustVectors = true);

};