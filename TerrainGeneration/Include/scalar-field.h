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

	void setHeight(int i, int j, float val);
	void addHeight(int i, int j, float val);
	void addHeight(int index, float val);

	Box getBox();
	float getHeight(int i, int j);//the method val() 
	float getHeight(int index);
	float getMaxHeight();
	int getSize();
	float getIntervalX();
	float getIntervalY();

	float slope(int i, int j);
	Vector gradient(float posX, float posY);
	int getIndex(int i, int j);
	static Vector getCoord(int nj, int index);
	Vector get2dPoint(int i, int j); // Z will always be 0
protected:
	VectorField vecField;
};

#endif

