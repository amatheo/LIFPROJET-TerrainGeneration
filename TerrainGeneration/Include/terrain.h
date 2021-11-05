#pragma once
#ifndef __Terrain__
#define __Terrain__

#include <QtGui/QImage>
#include <QtCore/QVector>

#include "scalar-field.h"

class Terrain : public ScalarField
{
public:
	int za, zb;
	QImage heightmap;

	Terrain();
	Terrain(QImage image, Box box, int za, int zb);
	
	Vector getPoint(int i, int j);
	Vector getNormal(int i, int j);
	
	ScalarField Slope;
	Mesh toMesh();
	~Terrain();
};
#endif