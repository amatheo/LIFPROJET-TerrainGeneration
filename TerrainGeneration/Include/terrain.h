#pragma once
#ifndef __Terrain__
#define __Terrain__

#include <QtGui/QImage>
#include <QtCore/QVector>

#include "scalar-field.h"

class Terrain : public ScalarField
{
public:
	float heightScale;
	QImage heightmap;

	Terrain();
	Terrain(QImage image, Box box, float heightScale);
	Terrain(Box box, float heightScale);
	
	/*
	*
	*/
	Vector getPoint(int i, int j);
	Vector getNormal(int i, int j);

	Mesh toMesh();
	~Terrain();

	vector<int> getTreeList();
	bool checkTree(int i);
};
#endif