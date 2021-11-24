#pragma once
#ifndef __ErosionParameter__
#define __ErosionParameter__

class ErosionParameter
{
public:
	ErosionParameter();
	~ErosionParameter();
	int erosionRadius;
	float inertia; // 0-1
	float sedimentCapacityFactor; //4
	float minSedimentCapacity; //0.1f
	float erodeSpeed;
	float depositSpeed; //0-1
	float evaporateSpeed; //0-1
	int maxDropletLifetime; //30
	float initialSpeed;
	float initialWaterVolume;
private:
	
};
#endif
