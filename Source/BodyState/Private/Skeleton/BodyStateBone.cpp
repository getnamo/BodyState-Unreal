
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

void UBodyStateBone::ShiftBone(FVector Shift)
{
	Transform.SetTranslation(Transform.GetTranslation() + Shift);
}

void UBodyStateBone::ChangeBasis(FRotator PreBase, FRotator PostBase, bool AdjustVectors)
{
	//Adjust the orientation
	FRotator PostCombine = CombineRotators(Orientation(), PostBase);
	Transform.SetRotation(FQuat(CombineRotators(PreBase, PostCombine)));

	//Rotate our vector/s
	if (AdjustVectors)
	{
		Transform.SetTranslation(PostBase.RotateVector(Position()));
	}
}