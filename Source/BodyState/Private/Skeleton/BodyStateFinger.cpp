#include "BodyStatePrivatePCH.h"
#include "BodyStateUtility.h"
#include "BodyStateFinger.h"

UBodyStateFinger::UBodyStateFinger(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	Metacarpal = ObjectInitializer.CreateDefaultSubobject<UBodyStateBone>(this, TEXT("Metacarpal"));
	Proximal = ObjectInitializer.CreateDefaultSubobject<UBodyStateBone>(this, TEXT("Proximal"));
	Intermediate = ObjectInitializer.CreateDefaultSubobject<UBodyStateBone>(this, TEXT("Intermediate"));
	Distal = ObjectInitializer.CreateDefaultSubobject<UBodyStateBone>(this, TEXT("Distal"));
}

bool UBodyStateFinger::Enabled()
{
	return Alpha == 1.f;
}

void UBodyStateFinger::SetEnabled(bool Enable)
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
	Metacarpal->SetEnabled(Enable);
	Proximal->SetEnabled(Enable);
	Intermediate->SetEnabled(Enable);
	Distal->SetEnabled(Enable);
}

void UBodyStateFinger::TranslateFinger(FVector Shift)
{
	//Shift all bones
	Metacarpal->ShiftBone(Shift);
	Proximal->ShiftBone(Shift);
	Intermediate->ShiftBone(Shift);
	Distal->ShiftBone(Shift);
}

void UBodyStateFinger::ChangeBasis(FRotator PreBase, FRotator PostBase, bool AdjustVectors)
{
	//Change Basis for all bones
	Metacarpal->ChangeBasis(PreBase, PostBase, AdjustVectors);
	Proximal->ChangeBasis(PreBase, PostBase, AdjustVectors);
	Intermediate->ChangeBasis(PreBase, PostBase, AdjustVectors);
	Distal->ChangeBasis(PreBase, PostBase, AdjustVectors);
}