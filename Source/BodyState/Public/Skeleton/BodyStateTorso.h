#pragma once

#include "BodyStateTorso.generated.h"

UCLASS(BlueprintType)
class BODYSTATE_API UBodyStateTorso : public UObject
{
	GENERATED_UCLASS_BODY()

	//Hand Properties
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "BodyState Hand")
	float Alpha;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "BodyState Hand")
	float Confidence;


	//Arm and Wrist, NB: Consider moving this up the skeletal tree, for leap this is sufficient
	UPROPERTY(BlueprintReadOnly, Category = "BodyState Hand")
	UBodyStateBone* Pelvis;

	UPROPERTY(BlueprintReadOnly, Category = "BodyState Hand")
	UBodyStateBone* SpineLower;

	UPROPERTY(BlueprintReadOnly, Category = "BodyState Hand")
	UBodyStateBone* SpineMiddle;

	UPROPERTY(BlueprintReadOnly, Category = "BodyState Hand")
	UBodyStateBone* SpineUpper;

	UPROPERTY(BlueprintReadOnly, Category = "BodyState Hand")
	UBodyStateBone* Neck;

	UPROPERTY(BlueprintReadOnly, Category = "BodyState Hand")
	UBodyStateBone* Head;


	UFUNCTION(BlueprintCallable, Category = "BodyState Hand")
	bool Enabled();

	UFUNCTION(BlueprintCallable, Category = "BodyState Hand")
	void SetEnabled(bool enable = true);

	UFUNCTION(BlueprintCallable, Category = "BodyState Hand")
	void TranslateHand(FVector shift);

	UFUNCTION(BlueprintCallable, Category = "BodyState Hand")
	void ChangeBasis(FRotator PreBase, FRotator PostBase, bool adjustVectors = true);

};