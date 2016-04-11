#include "BodyStatePrivatePCH.h"
#include "BodyStateLeg.h"

UBodyStateLeg::UBodyStateLeg(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	//Thumb = ObjectInitializer.CreateDefaultSubobject<UBodyStateFinger>(this, TEXT("Thumb"));
}

bool UBodyStateLeg::Enabled()
{
	return Alpha == 1.f;
}

void UBodyStateLeg::SetEnabled(bool enable)
{
	if (enable)
	{
		Alpha = 1.f;
	}
	else
	{
		Alpha = 0.f;
	}

	//Forward to every bones
	//Thumb->SetEnabled(enable);
}

void UBodyStateLeg::TranslateLeg(FVector Shift)
{
	//Shift all bones
	//Thumb->TranslateFinger(shift);
}

void UBodyStateLeg::ChangeBasis(FRotator PreBase, FRotator PostBase, bool AdjustVectors)
{
	//Change Basis for all bones
	//Thumb->ChangeBasis(PreBase, PostBase, adjustVectors);
}