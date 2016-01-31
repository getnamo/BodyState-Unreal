#pragma once

#include "BodyStateLeg.generated.h"

UCLASS(BlueprintType)
class BODYSTATE_API UBodyStateLeg : public UObject
{
	GENERATED_UCLASS_BODY()

	//Hand Properties
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "BodyState Hand")
	float Alpha;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "BodyState Hand")
	float Confidence;

	
	//Arm and Wrist, NB: Consider moving this up the skeletal tree, for leap this is sufficient
	UPROPERTY(BlueprintReadOnly, Category = "BodyState Hand")
	UBodyStateBone* Thigh;

	UPROPERTY(BlueprintReadOnly, Category = "BodyState Hand")
	UBodyStateBone* Calf;

	UPROPERTY(BlueprintReadOnly, Category = "BodyState Hand")
	UBodyStateBone* Foot;

	UPROPERTY(BlueprintReadOnly, Category = "BodyState Hand")
	UBodyStateBone* Ball;


	UFUNCTION(BlueprintCallable, Category = "BodyState Hand")
	bool Enabled();

	UFUNCTION(BlueprintCallable, Category = "BodyState Hand")
	void SetEnabled(bool enable = true);

	UFUNCTION(BlueprintCallable, Category = "BodyState Hand")
	void TranslateLeg(FVector shift);

	UFUNCTION(BlueprintCallable, Category = "BodyState Hand")
	void ChangeBasis(FRotator PreBase, FRotator PostBase, bool adjustVectors = true);

};