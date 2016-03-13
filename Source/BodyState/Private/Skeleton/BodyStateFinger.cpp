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

void UBodyStateFinger::SetEnabled(bool enable)
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
	Metacarpal->SetEnabled(enable);
	Proximal->SetEnabled(enable);
	Intermediate->SetEnabled(enable);
	Distal->SetEnabled(enable);
}

void UBodyStateFinger::TranslateFinger(FVector shift)
{
	//Shift all bones
	Metacarpal->ShiftBone(shift);
	Proximal->ShiftBone(shift);
	Intermediate->ShiftBone(shift);
	Distal->ShiftBone(shift);
}

void UBodyStateFinger::ChangeBasis(FRotator PreBase, FRotator PostBase, bool adjustVectors)
{
	//Change Basis for all bones
	Metacarpal->ChangeBasis(PreBase, PostBase, adjustVectors);
	Proximal->ChangeBasis(PreBase, PostBase, adjustVectors);
	Intermediate->ChangeBasis(PreBase, PostBase, adjustVectors);
	Distal->ChangeBasis(PreBase, PostBase, adjustVectors);
}