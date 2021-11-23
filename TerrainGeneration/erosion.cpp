#include "erosion.h"


Erosion::Erosion() {
}

Erosion::Erosion(Terrain t, int nbdrop):Terrain(t.heightmap, this->getBox(), this->za, this->zb){
	this->qtyDroplet = nbdrop;
	this->amountAbsorption = getMaxHeight()*0.05;
	this->maxAbsorption = this->amountAbsorption*10;
	this->speed = 0;//dummy values are applied for the moment
	//herites de terrain
	//extend pour l'heritage
	//plus de workTerrain, adapter le constructeur
	//travailler sur terrain avec terrain.methode()
	//getHeight(1, 2);
	//nombre de droplet a set quand lors du run avec les paramètres sur les gouttes
	//objet erosion mais aussi à coté fonction erosion qui l'applique sur chaque terrain
	//erosion doit être un héritage pour garder les données et pouvoir y accéder
}



void Erosion::applyErosion() {
	applyDroplet();

}
void Erosion::setAbsorption( float max, float amount) {
	this->maxAbsorption = max;
	this->amountAbsorption = amount;

}


void Erosion::applyDroplet(int nbdrop=100) {
	for (int i=0; i < nbdrop; i++) {
		this->speed = 0;//dummy stat for now
		this->absorption = 0;
		int prevDir = rand() % 3+1;
		//getting the starting point
		int  x, y;
		x = rand() % this->ni;
		y = rand() % this->nj;
		bool followup = true;
		while (followup) {
			int dir = getDirection( x, y, prevDir);
			if (dir == 0) {
				//we reached the bottomest point possible
				followup = false;
				addHeight(x, y, this->absorption);
			}
			else {
				//absorb a part of the height into the droplet
				if (this->absorption < this->maxAbsorption) {
					this->absorption = this->absorption + this->amountAbsorption;
					addHeight(x, y, -amountAbsorption);//no fear of going under 0, since the min always get a positive value, minus is applied only on something superior to min
				}
				if (prevDir == dir) {
					this->speed = this->speed + 1;
				}
				else {
					this->speed = 1;
					prevDir = dir;
				}
				//we get next analyzed point, which will never be out of scope
				switch (dir) {
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
	}
}

int Erosion::getDirection( int x, int y, int prevDir) {
	//slope à réutiliser
	//changer vitesse pour la rendre importante avec de l'inertie
	int currentHeight = getHeight(x, y);
	int north, east, south, west;
	if (x == 0) {
		west = getHeight(x, y);
	}
	else {
		west = getHeight(x - 1, y);
	}
	if (x == ni) {
		east = getHeight(x, y);
	}
	else {
		east = getHeight(x + 1, y);
	}
	if (y == 0) {
		north = getHeight(x, y);
	}
	else {
		north = getHeight(x, y - 1);
	}
	if (y == nj) {
		south = getHeight(x, y);
	}
	else {
		south = getHeight(x, y + 1);
	}
	vector<int> list1{ currentHeight, north, east, south, west };
	int minIndicator = *min_element(list1.begin(), list1.end());
	if (currentHeight == minIndicator){
		// i do this test first to cover evey case at border of terrain, because this way we are sure to not have any error
		// i am sure we never reach out of scope state thanks to that
		//we basically reach the pit when returning 0
		return 0;
	}
	else {
		// in case of equality, then the droplet goes into the same direction as the previous direction, emulating speed
		if (north == minIndicator) {
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
			if (east == minIndicator) {
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
				if (south == minIndicator) {
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
					if (west == minIndicator) {
						//this last if is trivial, but i prefer to show it for clarity when reading
						return 4;
					}
				}
			}
		}
	}

}
