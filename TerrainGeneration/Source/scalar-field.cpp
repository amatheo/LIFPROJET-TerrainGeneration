#include "scalar-field.h"


ScalarField::ScalarField()
{
}

ScalarField::ScalarField(Box data, int nbX, int nbY) {
	//constructor used by terrain cpp
	//added a small text
	this->box = data;
	this->ni = nbX;
	this->nj = nbY;

	this->intervalX =(/* abs(*/ this->box[1][0] - this->box[0][0]) / (this->ni - 1);
	this->intervalY = (/*abs(*/ this->box[1][1] - this->box[0][1]) / (this->nj - 1);
	//i dont think using abs is a good idea: we would lose the way and have incorrect data, but i struggle to exactly explain why

	for (int x = 0; x < this->ni; x++) {

		for (int y = 0; y < this->nj; y++) {
			int position;
			position = getIndex(x, y);
			this->vecField.v.push_back(Vector(this->intervalX * x + this->box[0][0], this->intervalY * y + this->box[0][1], 0));

			//i add the length to the starting point from data[0], so it includeds every possibility and is clean
			float r2 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 1.0f));
			this->heightVector.push_back(r2);//here we fill it separately
		}
	}
}

void ScalarField::setHeight(int i, int j, float val) {
	int index = getIndex(i, j);
	this->heightVector[index] = val;
}

void ScalarField::addHeight(int i, int j, float val) {
	int index = getIndex(i, j);
	this->heightVector[index] += val;
}

void ScalarField::addHeight(int index, float val)
{
	this->heightVector[index] += val;
}

int ScalarField::getSize() {
	return (ni * nj);
}


float ScalarField::getHeight(int i, int j) {
	//gives height of the point in x y, stored in heightVector
	int index = getIndex(i, j);
	return this->heightVector[index];
}

float ScalarField::getHeight(int index) {
	//gives height of the point in x y, stored in heightVector
	return this->heightVector[index];
}
float ScalarField::getMaxHeight() {
	float max = 0;
	int size = this->ni * this->nj;
	for (int i = 0; i < size; i++) {
		if (this->heightVector[i] > max) {
			max = i;
		}
	}
	return this->heightVector[max];
}


Vector ScalarField::gradient(float posX, float posY)
{
	int coordX = (int)posX;
	int coordY = (int)posY;

	// Calculate droplet's offset inside the cell (0,0) = at NW node, (1,1) = at SE node
	float x = posX - coordX;
	float y = posY - coordY;

	//the 4 points surrounding the original point
	int indexNW = getIndex(coordX, coordY);
	int indexNE = getIndex(coordX+1, coordY);
	int indexSW = getIndex(coordX, coordY+1);
	int indexSE = getIndex(coordX+1, coordY+1);
	
	float heightNW = getHeight(indexNW);
	float heightNE = getHeight(indexNE);
	float heightSW = getHeight(indexSW);
	float heightSE = getHeight(indexSE);
	
	float gradientX = (heightNE - heightNW) * (1 - y) + (heightSE - heightSW) * y;
	float gradientY = (heightSW - heightNW) * (1 - x) + (heightSE - heightNE) * x;

	float height = heightNW * (1 - x) * (1 - y) + heightNE * x * (1 - y) + heightSW * (1 - x) * y + heightSE * x * y;
	
	return Vector(gradientX,gradientY, height);
}

float ScalarField::slope(int i, int j) {
	//is ok, and very simple
	Vector g = gradient(i, j);
	return Norm(g);
}

int ScalarField::getIndex(int i, int j) {
	//since vectorField and heightVector are one dimensionnal, we need to calculate where the data for the point in x y is stored
	return (i * nj) + j;
}

Vector ScalarField::getCoord(int nj, int index)
{
	int x = index / nj;
	int y = index % nj;
	return Vector(x,y,0);
}

Vector ScalarField::get2dPoint(int i, int j)
{
	int pos = getIndex(i, j);
	return vecField[pos];
}
