#pragma once
#ifndef __ErosionCo__
#define __ErosionCo__
#include "terrain.h"


#pragma once
class ErosionCo : public Terrain
{




private:
	int qtyDroplet;
	float speed, absorption, amountAbsorption, maxAbsorption;
	ScalarField workTerrain;

public:

	ErosionCo();
	ErosionCo(Terrain t ,int nbdrop);
	void applyErosion();
	void setAbsorption(float max, float amount);
	void applyDroplet(int nbdrop);
	int getDirection( int x, int y, int prevDir);
	vector<int> getTreeList();
	bool checkTree(int i);







};
#endif

