#include "BodyStatePrivatePCH.h"
#include "BodyStateHand.h"

UBodyStateHand::UBodyStateHand(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	Thumb = ObjectInitializer.CreateDefaultSubobject<UBodyStateFinger>(this, TEXT("Thumb"));
	Index = ObjectInitializer.CreateDefaultSubobject<UBodyStateFinger>(this, TEXT("Index"));
	Middle = ObjectInitializer.CreateDefaultSubobject<UBodyStateFinger>(this, TEXT("Middle"));
	Ring = ObjectInitializer.CreateDefaultSubobject<UBodyStateFinger>(this, TEXT("Ring"));
	Pinky = ObjectInitializer.CreateDefaultSubobject<UBodyStateFinger>(this, TEXT("Pinky"));

}

bool UBodyStateHand::Enabled()
{
	return Alpha == 1.f;
}

void UBodyStateHand::SetEnabled(bool enable)
{
	if (enable)
	{
		Alpha = 1.f;
	}
	else
	{
		Alpha = 0.f;
	}

	//Forward to every finger
	Thumb->SetEnabled(enable);
	Index->SetEnabled(enable);
	Middle->SetEnabled(enable);
	Ring->SetEnabled(enable);
	Pinky->SetEnabled(enable);
}

void UBodyStateHand::TranslateHand(FVector shift)
{
	//Shift all fingers
	Thumb->TranslateFinger(shift);
	Index->TranslateFinger(shift);
	Middle->TranslateFinger(shift);
	Ring->TranslateFinger(shift);
	Pinky->TranslateFinger(shift);
}

void UBodyStateHand::ChangeBasis(FRotator PreBase, FRotator PostBase, bool adjustVectors)
{
	//Change Basis for all fingers
	Thumb->ChangeBasis(PreBase, PostBase, adjustVectors);
	Index->ChangeBasis(PreBase, PostBase, adjustVectors);
	Middle->ChangeBasis(PreBase, PostBase, adjustVectors);
	Ring->ChangeBasis(PreBase, PostBase, adjustVectors);
	Pinky->ChangeBasis(PreBase, PostBase, adjustVectors);
}