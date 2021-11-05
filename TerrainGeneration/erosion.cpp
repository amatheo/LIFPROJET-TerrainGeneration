#include "erosion.h"


Erosion::Erosion() {
}

Erosion::Erosion(int nbdrop, ScalarField terrain) {
	this->qtyDroplet = nbdrop;
	this->workTerrain = terrain;
	this->maxAbsorption = 0.5;//this two parameters
	this->amountAbsorption = 0.1;// will have to be settable in the future
	//to do: add a max height to scalarfield so we can take a small portion of this for erosion, like 0.5%
	this->speed = 0;//dummy values are applied to it for the moment


	for (int i = 0; i < this->qtyDroplet; i++) {
		this->workTerrain=applyDroplet(this->workTerrain);
	}


}

ScalarField Erosion::applyDroplet(ScalarField terrain) {
	this->speed = 0;
	this->absorption = 0;
	int prevDir = rand()%4;// to avoid errors, ask matheo if it excludes 0 from the possible answers, if not then %3+1 is the answer
	//getting the starting point
	int  x, y;
	x = rand()%terrain.ni;
	y = rand()%terrain.nj;
	bool followup = true;
	while (followup) {
		int dir = getDirection(terrain, x, y, prevDir);
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

			if (prevDir == dir) {
				this->speed = this->speed + 1;

			}
			else {
				this->speed = 1;
				prevDir = dir;
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

int Erosion::getDirection(ScalarField terrain, int x, int y, int prevDir) {
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
		// i am sure we never reach out of scope state thanks to that1
		//we basically rerach the pit when returning 0
		return 0;

	}
	else {
		// in case of equality, then the droplet goes into the same direction as the previous direction, emulating speed
		if (north == indicator) {
			if (north != east && north != south && north != west || prevDir == 1) {
				return 1;
			}
			else {
				if (north == east && prevDir == 2) {
					return 2;
				}
				else {
					if (north == south && prevDir == 3) {
						return 3;
					}
					else {
						if (north == west && prevDir == 4) {
							return 4;
							// last if trivial, but i prefer to be sure
						}
					}
				}
			}
		}
		else {
			if (east == indicator) {
				if (east != south && east != west || prevDir == 2) {
					return 2;
				}
				else {
					if (east == south && prevDir == 3) {
						return 3;

					}
					else {
						if (east == west && prevDir == 4) {
							return 4;
							// last if trivial, but i prefer to be sure
						}
					}
				}
				

			}
			else {
				if (south == indicator) {
					if (south!=west || prevDir==3) {
						return 3;
					}
					else {
						if (south == west && prevDir == 4) {
							return 4;
						}
					}
						

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
