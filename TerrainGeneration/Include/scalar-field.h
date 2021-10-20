#include "terrain.h"
#include "evector.h"
#include "mesh.h"
#include <vector>
#include "vectorfield.h"

using namespace std;

class ScalarField {

private:

public:
	ScalarField();
	ScalarField(Box data, int nbX, int nbY);
	Box box;//box containing every point of the terrain
	float intervalX, intervalY;// self-explanatory
	int nx, ny;//length, width
	float getHeight(int x, int y);       //the method val() 
	float slope(int x, int y);
	Vector gradient(int x, int y);
	int getIndex(int x, int y);
	vector<float> heightVector;
	VectorField vecField;
};


