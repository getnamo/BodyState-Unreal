#include "BodyStatePrivatePCH.h"
#include "BodyStateTorso.h"

UBodyStateTorso::UBodyStateTorso(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	//Thumb = ObjectInitializer.CreateDefaultSubobject<UBodyStateFinger>(this, TEXT("Thumb"));
}

bool UBodyStateTorso::Enabled()
{
	return Alpha == 1.f;
}

void UBodyStateTorso::SetEnabled(bool enable)
{
	if (enable)
	{
		Alpha = 1.f;
	}
	else
	{
		Alpha = 0.f;
	}

	//Forward to every bone
	//Thumb->SetEnabled(enable);
}

void UBodyStateTorso::TranslateHand(FVector shift)
{
	//Shift all fingers
	//Thumb->TranslateFinger(shift);
}

void UBodyStateTorso::ChangeBasis(FRotator PreBase, FRotator PostBase, bool adjustVectors)
{
	//Change Basis for all fingers
	//Thumb->ChangeBasis(PreBase, PostBase, adjustVectors);
}