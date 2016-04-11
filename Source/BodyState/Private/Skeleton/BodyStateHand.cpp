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

void UBodyStateHand::SetEnabled(bool Enable)
{
	if (Enable)
	{
		Alpha = 1.f;
	}
	else
	{
		Alpha = 0.f;
	}

	//Forward to every finger
	Thumb->SetEnabled(Enable);
	Index->SetEnabled(Enable);
	Middle->SetEnabled(Enable);
	Ring->SetEnabled(Enable);
	Pinky->SetEnabled(Enable);
}

void UBodyStateHand::TranslateHand(FVector Shift)
{
	//Shift all fingers
	Thumb->TranslateFinger(Shift);
	Index->TranslateFinger(Shift);
	Middle->TranslateFinger(Shift);
	Ring->TranslateFinger(Shift);
	Pinky->TranslateFinger(Shift);
}

void UBodyStateHand::ChangeBasis(FRotator PreBase, FRotator PostBase, bool AdjustVectors)
{
	//Change Basis for all fingers
	Thumb->ChangeBasis(PreBase, PostBase, AdjustVectors);
	Index->ChangeBasis(PreBase, PostBase, AdjustVectors);
	Middle->ChangeBasis(PreBase, PostBase, AdjustVectors);
	Ring->ChangeBasis(PreBase, PostBase, AdjustVectors);
	Pinky->ChangeBasis(PreBase, PostBase, AdjustVectors);
}