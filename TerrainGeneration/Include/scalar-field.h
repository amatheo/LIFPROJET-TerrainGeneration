#include "terrain.h"
#include "evector.h"
#include "mesh.h"
#include <vector>

class ScalarField {

private:
	Box box;
	int nx, ny;
	std::vector<float> v2;
public:
	float getHeight(int x, int y);       //the method val() 
	float slope(int x, int y);
	Vector gradient(int x, int y);
	int getIndex(int x, int y);
	ScalarField();
	int getNx();
	int getNy();
	std::vector<float> getV2();
};


