#pragma once

#include "BodyStatePrivatePCH.h"

#define MAX_HMD_SNAPSHOT_COUNT 10

/**
* Structure holding a Head Mounted Display orientation and position at a given timestamp.
*/
struct BodyStateHMDSnapshot
{
public:
	double Timestamp;
	FVector Position;
	FQuat Orientation;

	BodyStateHMDSnapshot() {};
	BodyStateHMDSnapshot(int64 InTimeStamp, const FVector& InPosition, const FQuat& InOrientation);

	/** Returns the difference between the two snapshots*/
	BodyStateHMDSnapshot Difference(BodyStateHMDSnapshot& Other, float Tween);

	/** For the time warp adjustment itself*/
	FTransform Transform();

	//Operator overloads
	BodyStateHMDSnapshot operator*(float Mult);
	void operator*=(float Mult);
};


/**
* Keep last 20 samples for finding the closest sample to a specified timestamp
*/
class HMDSnapshotSamples
{
public:
	//Time warp utility methods
	void AddCurrentHMDSample();
	BodyStateHMDSnapshot CurrentHMDSample();
	BodyStateHMDSnapshot LastHMDSample();
	BodyStateHMDSnapshot& HMDSampleClosestToTimestamp(int64 Timestamp);

private:
	BodyStateHMDSnapshot Samples[MAX_HMD_SNAPSHOT_COUNT];
	int CurrentIndex = 0;
};
