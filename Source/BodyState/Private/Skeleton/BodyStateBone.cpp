
#include "BodyStatePrivatePCH.h"
#include "BodyStateUtility.h"
#include "BodyStateBone.h"

UBodyStateBone::UBodyStateBone(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	Transform.SetScale3D(FVector(1.f));
}

FVector UBodyStateBone::Position()
{
	return Transform.GetTranslation();
}


void UBodyStateBone::SetPosition(const FVector& InPosition)
{
	Transform.SetTranslation(InPosition);
}

FRotator UBodyStateBone::Orientation()
{
	return Transform.GetRotation().Rotator();
}


void UBodyStateBone::SetOrientation(const FRotator& InOrientation)
{
	Transform.SetRotation(InOrientation.Quaternion());
}

FVector UBodyStateBone::Scale()
{
	return Transform.GetScale3D();
}


void UBodyStateBone::SetScale(const FVector& InScale)
{
	Transform.SetScale3D(InScale);
}

bool UBodyStateBone::Enabled()
{
	return Alpha == 1.f;
}

void UBodyStateBone::SetEnabled(bool enable)
{
	enable ? Alpha = 1.f: Alpha = 0.f;
}

void UBodyStateBone::ShiftBone(FVector shift)
{
	Transform.SetTranslation(Transform.GetTranslation() + shift);
}

void UBodyStateBone::ChangeBasis(FRotator PreBase, FRotator PostBase, bool adjustVectors)
{
	//Adjust the orientation
	FRotator postCombine = CombineRotators(Orientation(), PostBase);
	Transform.SetRotation(FQuat(CombineRotators(PreBase, postCombine)));

	//Rotate our vector/s
	if (adjustVectors) 
	{
		Transform.SetTranslation(PostBase.RotateVector(Position()));
	}
}