#include "scalar-field.h"

ScalarField::ScalarField() {
	this->box = Box();
	this->nx = 0;
	this->ny = 0;
}

float ScalarField::getHeight(int x, int y) {
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
	return (x * ny) + y;
}