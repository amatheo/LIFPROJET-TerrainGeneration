#pragma once
#ifndef __Erosion__
#define __Erosion__
#include "terrain.h"
#include "erosion-parameter.h"

#pragma once
class Erosion
{
public:
	static Terrain ErodeTerrain(int numIteration, Terrain terrain, ErosionParameter parameter);
private :
	static float float_rand(float min, float max);
};
#endif