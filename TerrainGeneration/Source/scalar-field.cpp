#include "scalar-field.h"

ScalarField::ScalarField() {
	this->box = Box();
	this->nx = 0;
	this->ny = 0;
}
ScalarField::ScalarField(Box data, int nbX, int nbY) {
	//constructor used by terrain cpp

	this->box = data;
	this->nx = nbX;
	this->ny = nbY;
	this->intervalX =(/* abs(*/ this->box[1][0] - this->box[0][0]) / (this->nx - 1);
	this->intervalY = (/*abs(*/ this->box[1][1] - this->box[0][1]) / (this->ny - 1);
	//i dont think using abs is a good idea: we would lose the way and have incorrect data, but i struggle to exactly explain why

	int position;
	for (int x = 0; x < this->nx; x++) {

		for (int y = 0; y < this->ny; y++) {
			position = getIndex(x, y);
			this->vecField[position] = Vector(this->intervalX * x + this->box[0][0], this->intervalY * y + this->box[0][1], 0);
			//i add the length to the starting point from data[0], so it includeds every possibility and is clean
			this->heightVector[position] = 0;//here we fill it separately
		}
	}
	//box stay almost untouched
	
}


float ScalarField::getHeight(int x, int y) {
	//gives height of the point in x y, stored in heightVector
	int index = getIndex(x, y);
	return this->heightVector[index];
}

float ScalarField::getHeight(int index) {
	//gives height of the point in x y, stored in heightVector
	return this->heightVector[index];
}

Vector ScalarField::gradient(int x, int y) {
	//the 4 points surrounding the original point
	int prevXId;
	int prevYId;
	int succXId;
	int succYId;
	// covering case of calculating at borders
	if (x == 0) {
		prevXId = getIndex(x, y);
	}
	else {
		prevXId = getIndex(x - 1, y);
	}
	if (x == nx) {
		succXId = getIndex(x, y);
	}
	else {
		succXId = getIndex(x + 1, y);
	}
	if (y == 0) {
		prevYId = getIndex(x, y);
	}
	else {
		prevYId = getIndex(x, y - 1);
	}
	if (y == ny) {
		succYId = getIndex(x, y);
	}
	else {
		succYId = getIndex(x, y + 1);
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

float ScalarField::slope(int x, int y) {
	//is ok, and very simple
	Vector g = gradient(x, y);
	return Norm(g);
}

int ScalarField::getIndex(int x, int y) {
	//since vecFGield and heightVectore are one dimensionnal, we need to calculate where the data for the point in x y is stored
	return (x * ny) + y;
}