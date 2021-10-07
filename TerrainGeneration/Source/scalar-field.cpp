#include "scalar-field.h"

float ScalarField::getHeight(int x, int y) {
	int index = getIndex(x, y);
	return this->v2[index];
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
	return (y * getNx()) + x;
}

int ScalarField::getNx() {
	return this->nx;
}

int ScalarField::getNy() {
	return this->ny;
}