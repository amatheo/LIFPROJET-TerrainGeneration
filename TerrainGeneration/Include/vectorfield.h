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
};

#endif