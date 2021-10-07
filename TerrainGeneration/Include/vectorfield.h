#pragma once
#ifndef __VectorField__
#define __VectorField__

#include <vector>
#include "evector.h"

using namespace std;
class VectorField {
public:
	vector<Vector> v;
	VectorField(vector<Vector> vectorArray);
	VectorField(int size);

	//Access Vector
	Vector operator[] (int) const;
	Vector& operator[] (int);
};

inline Vector VectorField::operator[](int i) const
{
	return v[i];
}

inline Vector& VectorField::operator[](int i)
{
	return v[i];
}

#endif