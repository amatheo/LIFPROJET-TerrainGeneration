#include "scalar-field.h"


#pragma once
class Erosion{




private:
	int qtyDroplet;
	float speed, absorption, amountAbsorption, maxAbsorption;
	ScalarField workTerrain;

public:

	Erosion();
	Erosion(int nbdrop, ScalarField terrain);
	ScalarField applyDroplet(ScalarField terrain);
	int getDirection(ScalarField terrain, int x, int y);






};

