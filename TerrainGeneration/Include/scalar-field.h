#include "terrain.h"
#include "evector.h"
#include "mesh.h"
#include <vector>

using namespace std;

class ScalarField {

private:

public:
	ScalarField();
	Box box;
	int nx, ny;
	float getHeight(int x, int y);       //the method val() 
	float slope(int x, int y);
	Vector gradient(int x, int y);
	int getIndex(int x, int y);
	vector<float> heightVector;
};


