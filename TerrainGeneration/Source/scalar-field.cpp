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
			this->box[position] = Vector(segmentx * x, segmenty * y, 0);
			this->heightVector[position] = 0;
		}
	}


}


float ScalarField::getHeight(int x, int y) {
	//gives height of the point in x y, stored in heightVector
	int index = getIndex(x, y);
	return this->heightVector[index];
}

Vector ScalarField::gradient(int x, int y) {
	//the 4 points surrounding the original point
	int prevXId;
	int prevYId;
	int succXId;
	int succYId;
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
	int gradX = (heightVector[succXId] - heightVector[prevXId]) / (2 * box[ny][0]);
		
	int gradY = (heightVector[succYId] - heightVector[prevYId]) / (2 * box[1][1]);
	double fullGrad = gradX / gradY;
	return Vector(fullGrad);




	//think when calculating at borders(0, or nx/ny)


	//legacy text, dont want to lose it if change is bad
	//double gradient = ((y + 1) - y) / ((x + 1) - x);
	//return Vector(gradient);
}

float ScalarField::slope(int x, int y) {
	Vector g = gradient(x, y);
	return Norm(g);
}

int ScalarField::getIndex(int x, int y) {
	//since box is one dimensionnal, we need to calculate where the data for a point in x y is stored
	return (x * ny) + y;
}