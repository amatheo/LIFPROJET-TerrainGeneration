#include "scalar-field.h"

ScalarField::ScalarField() {
	this->box = Box();
	this->nx = 0;
	this->ny = 0;
}
ScalarField::ScalarField(int width, int length, int nbX, int nbY) {
	//dummy example of how the box si filled
	this->nx = nbX;
	this->ny = nbY;
	int segmentx = width / (this->nx - 1);
	int segmenty = width / (this->ny - 1);

	int position;
	for (int y = 0; y < this->ny; y++) {

		for (int x = 0; x < this->nx; x++) {
			position = getIndex(x, y);
			this->box[position] = Vector(segmentx*x, segmenty*y, 0);
			this->heightVector[position] = 0;
		}
	}


}


float ScalarField::getHeight(int x, int y) {
	//donne la hauteur du point en x y, stocké dans heightVector
	int index = getIndex(x, y);
	return this->heightVector[index];
}

Vector ScalarField::gradient(int x, int y) {
	double gradient = ((y + 1) - y) / ((x + 1) - x);
	return Vector(gradient);
}

float ScalarField::slope(int x, int y) {
	Vector g = gradient(x, y);
	return Norm(g);
}

int ScalarField::getIndex(int x, int y) {
	//since box is one dimensionnal, we need to calculate where the data for a point in x y is stored
	return (x * ny) + y;
}