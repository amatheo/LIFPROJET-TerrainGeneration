#pragma once
#ifndef __Terrain__
#define __Terrain__

#include <QtGui/QImage>
#include <QtCore/QVector>

#include "mesh.h"

class Terrain : public Mesh
{
public:
	Terrain(int width, int height, int resolutionX, int resolutionY, QImage heightmap, double heightscale);
	Terrain(int width, int height, int resolutionX, int resolutionY);
	Terrain(QImage image, Box box, int za, int zb);
	
	~Terrain();
	
	int width;
	int height;
	int resolutionX;
	int resolutionY;
	QImage heightmap;
	double heightscale;

	void Generate();
	QImage GenerateHeightmap();

private:
	void InitializeTerrain(QImage image, Box box, int za, int zb);
	void InitializePlane(double scaleX, double scaleY, int resolutionX, int resolutionY);
};
#endif