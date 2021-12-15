#include "terrain.h"
#include <QtGui/QImage>

Terrain::Terrain(QImage image, Box box, float heightScale):ScalarField(box, 200, 200)
{
	this->heightScale = heightScale;
}

Terrain::Terrain() : ScalarField()
{
}

Vector Terrain::getPoint(int i, int j)
{
	Vector vec = Vector();
	vec= this->get2dPoint(i, j);
	vec[2] = this->getHeight(i, j);
	return vec;
}

Vector Terrain::getNormal(int i, int j)
{
	return Vector::Z;
}

Mesh Terrain::toMesh()
{
	QVector<Vector> vertices;
	QVector<int> indices;
	for (int i = 0; i < this->ni; i++) {

		for (int j = 0; j < this->nj; j++) {
			Vector v = getPoint(i, j);
			v[2] = v[2] * heightScale;
			vertices.push_back(v);
		}
	}

	for (int i = 0; i < this->ni-1; i++) {

		for (int j = 0; j < this->nj-1; j++) {
			//Top Left
			int tl = getIndex(i,j);
			//Top Right
			int tr = getIndex(i+1, j);
			//Bottom Left
			int bl = getIndex(i, j+1);
			//Bottom Right
			int br = getIndex(i + 1, j + 1);

			//First triangle
			indices.push_back(tl);
			indices.push_back(tr);
			indices.push_back(bl);

			//Second Triangle
			indices.push_back(tr);
			indices.push_back(br);
			indices.push_back(bl);
		}
	}
	
	//QVector<Vector> normals = vertices;
	Mesh m = Mesh(vertices, indices);
	m.SmoothNormals(); //Else list of normal is not same as list of vertices !!DIRTY FIX
	return m;
}

Terrain::~Terrain()
{
}

