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
			this->heightVector.push_back(0);//here we fill it separately
		}
	}
}
void ScalarField::setHeight(int i, int j, float val) {
	int index = getIndex(i, j);
	this->heightVector[index] = val;
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

Vector ScalarField::gradient(int i, int j) {
	//the 4 points surrounding the original point
	int prevXId;
	int prevYId;
	int succXId;
	int succYId;
	// covering case of calculating at borders
	if (i == 0) {
		prevXId = getIndex(i, j);
	}
	else {
		prevXId = getIndex(i - 1, j);
	}
	if (i == ni) {
		succXId = getIndex(i, j);
	}
	else {
		succXId = getIndex(i + 1, j);
	}
	if (j == 0) {
		prevYId = getIndex(i, j);
	}
	else {
		prevYId = getIndex(i, j - 1);
	}
	if (j == nj) {
		succYId = getIndex(i, j);
	}
	else {
		succYId = getIndex(i, j + 1);
	}
	/*
	*gradient missunderstood
	*double gradX = (heightVector[succXId] - heightVector[prevXId]) / (2 * intervalX);	
	*double gradY = (heightVector[succYId] - heightVector[prevYId]) / (2 * intervalY);
	*double fullGrad = gradX / gradY;
	*/
	/*
	* average
	//it should return the average of the height from the 4 neighbors points
	double fullGrad = (this->heightVector[prevXId] + this->heightVector[prevYId] + this->heightVector[succXId] + this->heightVector[succYId])/4;
	return Vector(fullGrad);
	*/

	//Vec2 G= Vec2 ( H(i+1,j)-H(i-1,j), H(i,j+1)-H(i,j-1) );
	//remplacer par getHeight
	Vector G= Vector ( getHeight(succXId)- getHeight(prevXId), getHeight(succYId)- getHeight(prevYId), 0 );
	return G;
}

float ScalarField::slope(int i, int j) {
	//is ok, and very simple
	Vector g = gradient(i, j);
	return Norm(g);
}

int ScalarField::getIndex(int i, int j) {
	//since vecFGield and heightVectore are one dimensionnal, we need to calculate where the data for the point in x y is stored
	return (i * nj) + j;
}

Vector ScalarField::get2dPoint(int i, int j)
{
	int pos = getIndex(i, j);
	return vecField[pos];
}
