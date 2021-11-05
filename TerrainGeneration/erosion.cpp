#include "erosion.h"


Erosion::Erosion() {
}

Erosion::Erosion(int nbdrop, ScalarField terrain) {
	this->qtyDroplet = nbdrop;
	this->workTerrain = terrain;
	this->maxAbsorption = 0.5;//this two parameters
	this->amountAbsorption = 0.1;// will have to be settable in the future


	for (int i = 0; i < this->qtyDroplet; i++) {
		this->workTerrain=applyDroplet(this->workTerrain);
	}


}

ScalarField Erosion::applyDroplet(ScalarField terrain) {
	this->speed = 0;
	this->absorption = 0;
	//getting the starting point
	int  x, y;
	x = rand()%terrain.ni;
	y = rand()%terrain.nj;
	bool followup = true;
	while (followup) {
		int dir = getDirection(terrain, x, y);
		if (dir == 0) {
			//we reached the bottomest point possible
			followup = false;
			terrain.setHeight(x, y, this->absorption);
		}
		else {
			//absorb a part of the height into the droplet
			if (this->absorption < this->maxAbsorption) {
				this->absorption = this->absorption + this->amountAbsorption;
				terrain.setHeight(x, y, -amountAbsorption);//no fear of going under 0, since the min always get a positive value, minus is applied only on something superior to min
			}
			//we get next analyzed point, which will never be out of scope
			switch(dir){
			case 1: y = y - 1;
				break;
			case 2: x = x + 1;
				break;
			case 3: y = y + 1;
				break;
			case 4: x = x - 1;
				break;
			}
			
			
		}
	}
	






	return terrain;

}

int Erosion::getDirection(ScalarField terrain, int x, int y) {
	int currentHeight = terrain.getHeight(x, y);
	int north, east, south, west;
	if (x == 0) {
		west = terrain.getHeight(x, y);
	}
	else {
		west = terrain.getHeight(x - 1, y);
	}
	if (x == terrain.ni) {
		east = terrain.getHeight(x, y);
	}
	else {
		east = terrain.getHeight(x + 1, y);
	}
	if (y == 0) {
		north = terrain.getHeight(x, y);
	}
	else {
		north = terrain.getHeight(x, y - 1);
	}
	if (y == terrain.nj) {
		south = terrain.getHeight(x, y);
	}
	else {
		south = terrain.getHeight(x, y + 1);
	}
	vector<int> list1{ currentHeight, north, east, south, west };
	int indicator = *min_element(list1.begin(), list1.end());
	if (currentHeight == indicator){
		// i do this test first to cover evey case at border of terrain, because this way we are sure to not have any error
		// i am sure we never reach out of scope state thanks to that
		return 0;

	}
	else {
		// for now, in case of equality, the following order is chosen: north, east, south, west, probably need a rework later
		if (north == indicator) {
			return 1;

		}
		else {
			if (east == indicator) {
				return 2;

			}
			else {
				if (south == indicator) {
					return 3;

				}
				else {
					if (west == indicator) {
						//this last if is trivial, but i prefer to show it to be clearer when reading
						return 4;

					}
				}
			}
		}
	}

}
