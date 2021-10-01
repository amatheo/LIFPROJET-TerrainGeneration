#include "terrain.h"
#include <QtGui/QImage>

Terrain::Terrain(int _width, int _height, int _resolutionX, int _resolutionY)
{
	this->width = _width;
	this->height = _height;
	this->resolutionX = _resolutionX;
	this->resolutionY = _resolutionY;
}

Terrain::Terrain(int _width, int _height, int _resolutionX, int _resolutionY, QImage _heightmap, double _heightscale)
{
	Terrain(_width, _height, _resolutionX, _resolutionY);
	this->heightmap = _heightmap;
	this->heightscale = _heightscale;
}

Terrain::~Terrain()
{
}

void Terrain::Generate()
{
	if (this->heightmap.isNull()) {
		this->InitializePlane(width, height, resolutionX, resolutionY);
		this->GenerateHeightmap();
	}
	else {
		this->InitializeTerrain(width, height, resolutionX, resolutionY, heightmap, height);
	}
}

QImage Terrain::GenerateHeightmap()
{
	QImage img(resolutionX+1, resolutionY + 1, QImage::Format::Format_Grayscale8);
	for (int x = 0; x < resolutionX+1; x++)
	{
		for (int y = 0; y < resolutionY+1; y++)
		{
			//TODO
		}
	}
	return img;
}

void Terrain::InitializeTerrain(double scaleX, double scaleY, int resolutionX, int resolutionY, QImage heightmap, double heightscale)
{
	int nbWidthVertex = resolutionX + 1;
	int nbHeightVertex = resolutionY + 1;
	int nbTotalVertex = nbHeightVertex * nbWidthVertex;

	//Heightmap processing
	QSize scaleFactor(nbWidthVertex, nbHeightVertex);
	heightmap.scaled(scaleFactor, Qt::IgnoreAspectRatio, Qt::TransformationMode::SmoothTransformation);

	//  Optimizing:
	//  Also resize narray and varray
	vertices.resize(nbTotalVertex);
	normals.resize(nbTotalVertex);

	for (int x = 0; x < nbWidthVertex; x++) 
	{
		for (int y = 0; y < nbHeightVertex; y++)
		{
			QRgb color = heightmap.pixel(x, y);
			int gradient = qGray(color);

			double xposition = ((double)scaleX / (double)resolutionX) * (double)x;
			double yposition = ((double)scaleY / (double)resolutionY) * (double)y;
			double zposition = (2.0 * gradient / 255) * heightscale;

			int index = (nbHeightVertex * x) + y;
			vertices[index] = Vector(xposition, yposition, zposition);
			normals[index] = Vector(0.0f, 0.0f, 1.0f);
		}
	}

	for (int x = 0; x < nbWidthVertex - 1; x++) 
	{
		for (int y = 0; y < nbHeightVertex - 1; y++)
		{
			//Top Left
			int tl = (nbHeightVertex * x) + y;
			//Top Right
			int tr = (nbHeightVertex * (x + 1)) + y;
			//Bottom Left
			int bl = (nbHeightVertex * x) + (y + 1);
			//Bottom Right
			int br = (nbHeightVertex * (x + 1)) + (y + 1);
			//Add first triangle
			AddTriangle(tl, tr, br, 0);
			//Add second triangle
			AddTriangle(bl, tl, br, 0);
		}
	}
}



void Terrain::InitializePlane(double scaleX, double scaleY, int resolutionX, int resolutionY)
{
	int nbWidthVertex = resolutionX + 1;
	int nbHeightVertex = resolutionY + 1;
	int nbTotalVertex = nbHeightVertex * nbWidthVertex;

	//  Optimizing:
	//  Also resize narray and varray
	vertices.resize(nbTotalVertex);
	normals.resize(nbTotalVertex);

	for (int x = 0; x < nbWidthVertex; x++) {
		for (int y = 0; y < nbHeightVertex; y++)
		{
			int index = (nbHeightVertex * x) + y;

			double xposition = ((double)scaleX / (double)resolutionX) * (double)x;
			double yposition = ((double)scaleY / (double)resolutionY) * (double)y;

			vertices[index] = Vector(xposition, yposition, (double)0);
			normals[index] = Vector(0.0f, 0.0f, 1.0f);
		}
	}

	for (int x = 0; x < nbWidthVertex-1; x++) {
		for (int y = 0; y < nbHeightVertex-1; y++)
		{
			//Top Left
			int tl = (nbHeightVertex * x) + y;
			//Top Right
			int tr = (nbHeightVertex * (x+1)) + y;
			//Bottom Left
			int bl = (nbHeightVertex * x) + (y + 1);
			//Bottom Right
			int br = (nbHeightVertex * (x+1)) + (y + 1);
			//Add first triangle
			AddTriangle(tl, tr, br, 0);
			//Add second triangle
			AddTriangle(bl, tl, br, 0);
		}
	}
}
