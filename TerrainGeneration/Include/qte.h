#ifndef __Qte__
#define __Qte__

#include "ui-interface.h"
#include "realtime.h"
#include "meshcolor.h"
#include "terrain.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT
private:
	Ui::Assets uiw;				//!< Interface

	MeshWidget* meshWidget;		//!< Viewer
	MeshColor meshColor;		//!< Mesh.
	QString imagePath;
	Terrain currentTerrain;

public:
	MainWindow();
	~MainWindow();
	void CreateActions();
	void UpdateGeometry();

public slots:
	void editingSceneLeft(const Ray&);
	void editingSceneRight(const Ray&);
	void BoxMeshExample();
	void ResetCamera();
	void UpdateMaterial();
	void ChangeCameraProjection();
	void GeneratePlaneMesh();
	void StartErosion();
	void UpdateTerrain();
	void ChangeHeightmapImage();
	void SpawnTree();
};

#endif
