#pragma once

#include "BodyStatePrivatePCH.h"
#include "IHeadMountedDisplay.h"
#include "BodyStateHMDSnapshot.h"


void HMDSnapshotSamples::AddCurrentHMDSample()
{
	//Grab current sample
	Samples[CurrentIndex] = CurrentHMDSample();

	//Circular tracker - slot it in correctly
	CurrentIndex++;
	if (CurrentIndex >= MAX_HMD_SNAPSHOT_COUNT)
	{
		CurrentIndex = 0;
	}
}

BodyStateHMDSnapshot::BodyStateHMDSnapshot(int64 InTimeStamp, const FVector& InPosition, const FQuat& InOrientation)
{
	Timestamp = InTimeStamp;
	Position = InPosition;
	Orientation = InOrientation;
}
BodyStateHMDSnapshot BodyStateHMDSnapshot::Difference(BodyStateHMDSnapshot& Other, float Tween)
{
	BodyStateHMDSnapshot Result;
	Result.Timestamp = Timestamp - Other.Timestamp;
	Other.Orientation = FQuat::Slerp(Orientation, Other.Orientation, Tween);

	FTransform DeltaTransform = Other.Transform().GetRelativeTransform(Transform());

	Result.Orientation = DeltaTransform.GetRotation();
	Result.Position = DeltaTransform.GetTranslation();
	return Result;
}

FTransform BodyStateHMDSnapshot::Transform()
{
	return FTransform(Orientation, Position, FVector(1.f));
}


BodyStateHMDSnapshot BodyStateHMDSnapshot::operator*(float Mult)
{
	//Orientation.Slerp(Orientation, )
	return BodyStateHMDSnapshot(Timestamp, Position * Mult, Orientation * Mult);
}

void BodyStateHMDSnapshot::operator*=(float Mult)
{
	this->Position *= Mult;
	this->Orientation *= Mult;
}

BodyStateHMDSnapshot HMDSnapshotSamples::CurrentHMDSample()
{
	BodyStateHMDSnapshot Snapshot;

	Snapshot.Timestamp = FPlatformTime::Seconds();
	Snapshot.Orientation;
	Snapshot.Position;

	GEngine->HMDDevice->GetCurrentOrientationAndPosition(Snapshot.Orientation, Snapshot.Position);
	return Snapshot;
}


BodyStateHMDSnapshot HMDSnapshotSamples::LastHMDSample()
{
	return Samples[CurrentIndex];
}

BodyStateHMDSnapshot& HMDSnapshotSamples::HMDSampleClosestToTimestamp(int64 Timestamp)
{
	int64 MinDifference = INT64_MAX;
	int32 MinIndex = 0;	//always have a valid index in case something goes wrong

						//UE_LOG(LeapPluginLog, Log, TEXT("Timewarp Debug - Now: %d"), Timestamp);

	for (int32 i = 0; i < MAX_HMD_SNAPSHOT_COUNT; i++)
	{
		BodyStateHMDSnapshot& Snapshot = Samples[i];
		int32 Difference = FMath::Abs(Snapshot.Timestamp - Timestamp);

		//UE_LOG(LeapPluginLog, Log, TEXT("Timewarp Debug - Snapshot: %d, Difference: %d"), Snapshot.Timestamp, Difference);

		if (Difference < MinDifference)
		{
			MinDifference = Difference;
			MinIndex = i;
		}
	}
	//UE_LOG(LeapPluginLog, Log, TEXT("Timewarp Debug - MinSnapshot: %d, MinDifference: %d"), Samples[MinIndex].Timestamp, MinDifference);
	return Samples[MinIndex];
}