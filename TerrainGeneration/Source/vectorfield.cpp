#include "vectorfield.h"

VectorField::VectorField()
{
}

VectorField::VectorField(vector<Vector> vectorArray)
{
	v = vectorArray;
}

VectorField::VectorField(int size)
{
	v = vector<Vector>(size);
}
