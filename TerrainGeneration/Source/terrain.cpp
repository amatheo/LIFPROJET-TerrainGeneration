#include "terrain.h"
#include <QtGui/QImage>


/*!
* \brief constructor
* \param image of type QImage this is the image used as a base layer, it can be a heightmap
* \param box of type Box
* \param heightScale of type float
*/

Terrain::Terrain(QImage image, Box box, float heightScale):ScalarField(box, 200, 200)
{
	this->heightScale = heightScale;

	QSize scaleFactor(this->ni, this->nj);
	image.scaled(scaleFactor, Qt::IgnoreAspectRatio, Qt::TransformationMode::SmoothTransformation);

	for (int i = 0; i < ni; i++) {
		for (int j = 0; j < nj; j++)
		{
			QRgb color = image.pixel(i, j);
			float ratio = (float)qGray(color) / (float)255;
			setHeight(i, j, ratio);
		}
	}

}


/*!
* \brief constructor
* \param box of type Box
* \param heightScale of type float
*/

Terrain::Terrain(Box box, float heightScale):ScalarField(box, 200, 200)
{
	this->heightScale = heightScale;
}

/*!
* \brief constructor
*/
Terrain::Terrain() : ScalarField()
{
}

/*!
* \brief returns the Vector type object at the coordinates (i, j)
* \param i integer
* \param j integer
* \returns Vector type object
*/
Vector Terrain::getPoint(int i, int j)
{
	Vector vec = Vector();
	vec= this->get2dPoint(i, j);
	vec[2] = this->getHeight(i, j);
	return vec;
}

/*!
* \brief returns the normal Vector type object at the coordinates (i, j)
* \param i integer
* \param j integer
* \returns Vector type object
*/
Vector Terrain::getNormal(int i, int j)
{
	return Vector::Z;
}

/*!
* \brief transforms the Terrain type object into a Mesh type object
* \returns Mesh type object
*/
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

/*!
* \brief destructor
*/
Terrain::~Terrain()
{
}


/*!
* \brief returns the list of trees
* \returns a list of int
*/

vector<int> Terrain::getTreeList() {
	int size = getSize();
	//vector<float> treeHeight; useless data, might be used one day, but for now heightVector is enough
	vector<int> levelTree;
	for (int i = 0; i < size; i++) {
		
	//if(i%nj==0)
			if (checkTree(i)) {
				levelTree.push_back(1);

				//this is actually very dumb and will be changed very soon
				//why changing only previous on left and above? because we start from top left, so everything is added from this point, we cant know yet if there is a tree at right and under
			}
			else {
				//no tree
				levelTree.push_back(0);
			}
		
	}
	//it should have the same size as heightVector for manipulation
	vector<int> trueLevelTree;
	for (int i = 0; i < levelTree.size(); i++) {
		int xPos = (i - (i % this->nj)) / this->nj;
		int yPos = (i % this->nj);
		//the 4 points surrounding the original point
		//copypasted from gradient, might need a func
		int prevXId;
		int prevYId;
		int succXId;
		int succYId;
		// covering case of calculating at borders
		if (xPos == 0) {
			prevXId = getIndex(xPos, yPos);
		}
		else {
			prevXId = getIndex(xPos - 1, yPos);
		}
		if (xPos == ni-1) {
			succXId = getIndex(xPos, yPos);
		}
		else {
			succXId = getIndex(xPos + 1, yPos);
		}
		if (yPos == 0) {
			prevYId = getIndex(xPos, yPos);
		}
		else {
			prevYId = getIndex(xPos, yPos - 1);
		}
		if (yPos == nj-1) {
			succYId = getIndex(xPos, yPos);
		}
		else {
			succYId = getIndex(xPos, yPos + 1);
		}
		//the more surrounded of trees it is, the taller it is
		trueLevelTree.push_back(levelTree[prevXId] + levelTree[succXId] + levelTree[prevYId] + levelTree[succYId] + levelTree[i]);
		//trueLevelTree.push_back(levelTree[i]);
	}

	return trueLevelTree;
}
/*!
* \brief checks whether it is possible to place a tree
* \param i integer
* \returns boolean
*/
bool Terrain::checkTree(int i) {
	int xPos = (i - (i % this->nj)) / this->nj;
	int yPos = (i % this->nj);
	//the 4 points surrounding the original point
	//copypasted from gradient, might need a func
	int prevXId;
	int prevYId;
	int succXId;
	int succYId;
	// covering case of calculating at borders
	if (xPos == 0) {
		prevXId = getIndex(xPos, yPos);
	}
	else {
		prevXId = getIndex(xPos - 1, yPos);
	}
	if (xPos == ni-1) {
		succXId = getIndex(xPos, yPos);
	}
	else {
		succXId = getIndex(xPos + 1, yPos);
	}
	if (yPos == 0) {
		prevYId = getIndex(xPos, yPos);
	}
	else {
		prevYId = getIndex(xPos, yPos - 1);
	}
	if (yPos == nj-1) {
		succYId = getIndex(xPos, yPos);
	}
	else {
		succYId = getIndex(xPos, yPos + 1);
	}
	//if height equal eveywhere then the area is flat and a tree can appear
	if (getHeight(prevXId) == getHeight(succXId) == getHeight(prevYId) == getHeight(succYId) == getHeight(xPos, yPos)) {
		return true;
		// the position is good for a tree
	}
	return false;

}

