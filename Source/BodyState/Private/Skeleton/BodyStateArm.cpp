#include "BodyStatePrivatePCH.h"
#include "BodyStateArm.h"

UBodyStateArm::UBodyStateArm(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	//Thumb = ObjectInitializer.CreateDefaultSubobject<UBodyStateFinger>(this, TEXT("Thumb"));

}

bool UBodyStateArm::Enabled()
{
	return Alpha == 1.f;
}

void UBodyStateArm::SetEnabled(bool enable)
{
	if (enable)
	{
		Alpha = 1.f;
	}
	else
	{
		Alpha = 0.f;
	}
}

void UBodyStateArm::TranslateArm(FVector shift)
{
	//Shift all sub-bones
	//Thumb->TranslateFinger(shift);
}

void UBodyStateArm::ChangeBasis(FRotator PreBase, FRotator PostBase, bool adjustVectors)
{
	//Change Basis for all bones
	//Thumb->ChangeBasis(PreBase, PostBase, adjustVectors);
}