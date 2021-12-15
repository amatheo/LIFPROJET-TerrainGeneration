#pragma once
#ifndef __Erosion__
#define __Erosion__
#include "terrain.h"


#pragma once
class Erosion : public Terrain
{




private:
	int qtyDroplet;
	float speed, absorption, amountAbsorption, maxAbsorption;
	ScalarField workTerrain;

public:

	Erosion();
	Erosion(Terrain t ,int nbdrop);
	void applyErosion();
	void setAbsorption(float max, float amount);
	void applyDroplet(int nbdrop);
	int getDirection( int x, int y, int prevDir);
	vector<int> getTreeList();
	bool checkTree(int i);







};
#endif
