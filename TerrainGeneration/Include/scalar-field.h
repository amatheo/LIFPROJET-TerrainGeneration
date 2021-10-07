#include "terrain.h"
#include "evector.h"
#include "mesh.h"

class ScalarField {
private:
	Terrain terrain;
	Mesh mesh;
	Vector vectorP;
	Vector vectorN;

public:
	ScalarField(Terrain terrain, Mesh mesh, Vector vectorP, Vector vectorN);
	~ScalarField();
};
