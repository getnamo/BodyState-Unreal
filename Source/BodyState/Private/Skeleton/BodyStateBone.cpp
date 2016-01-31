
#include "BodyStatePrivatePCH.h"
#include "BodyStateUtility.h"
#include "BodyStateBone.h"

UBodyStateBone::UBodyStateBone(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	Scale = FVector(1, 1, 1);
}

bool UBodyStateBone::Enabled()
{
	return Alpha == 1.f;
}

void UBodyStateBone::SetEnabled(bool enable)
{
	enable ? Alpha = 1.f: Alpha = 0.f;
}

void UBodyStateBone::SetFromTransform(const FTransform& transform)
{
	Orientation = FRotator(transform.GetRotation());
	Position = transform.GetTranslation();
	Scale = transform.GetScale3D();
}

FTransform UBodyStateBone::GetTransform()
{
	return FTransform(FQuat(Orientation), Position, Scale);
}

void UBodyStateBone::TranslateBone(FVector shift)
{
	Position += shift;
}

void UBodyStateBone::ChangeBasis(FRotator PreBase, FRotator PostBase, bool adjustVectors)
{
	//Adjust the orientation
	FRotator postCombine = CombineRotators(Orientation, PostBase);
	Orientation = CombineRotators(PreBase, postCombine);

	//Rotate our vector/s
	if(adjustVectors)
		Position = PostBase.RotateVector(Position);
}