#pragma once
#ifndef __ScalarField__
#define __ScalarField__

#include "evector.h"
#include "mesh.h"
#include <vector>
#include "vectorfield.h"

using namespace std;

class ScalarField {

private:
	float intervalX, intervalY;// self-explanatory
	Box box; // Contains a b point needed to plane
	vector<float> heightVector;
public:
	int ni, nj;//nb point X & y

	ScalarField();
	ScalarField(Box data, int nbX, int nbY);
	
	float getHeight(int i, int j);//the method val() 
	float getHeight(int index);
	float slope(int i, int j);
	Vector gradient(int i, int j);
	int getIndex(int i, int j);
	Vector get2dPoint(int i, int j); // Z will always be 0
protected:
	VectorField vecField;
};

#endif

