#include "qte.h"



#include <QtWidgets/qfiledialog.h>
#include "terrain.h"
#include <erosion.h>


MainWindow::MainWindow()
{
	// Chargement de l'interface
	uiw.setupUi(this);

	// Chargement du GLWidget
	meshWidget = new MeshWidget;
	QGridLayout* GLlayout = new QGridLayout;
	GLlayout->addWidget(meshWidget, 0, 0);
	GLlayout->setContentsMargins(0, 0, 0, 0);
	uiw.widget_GL->setLayout(GLlayout);

	// Creation des connect
	CreateActions();

	meshWidget->SetCamera(Camera(Vector(639, -604, 76), Vector(0.0, 0.0, 0.0)));
}

MainWindow::~MainWindow()
{
	delete meshWidget;
}

void MainWindow::CreateActions()
{
	// Buttons
	connect(uiw.boxMesh, SIGNAL(clicked()), this, SLOT(BoxMeshExample()));
	connect(uiw.resetcameraButton, SIGNAL(clicked()), this, SLOT(ResetCamera()));
	connect(uiw.wireframe, SIGNAL(clicked()), this, SLOT(UpdateMaterial()));
	connect(uiw.orthographic_mode, SIGNAL(clicked()), this, SLOT(ChangeCameraProjection()));
	connect(uiw.terrainMeshButton, SIGNAL(clicked()), this, SLOT(GeneratePlaneMesh()));
	connect(uiw.erodeButton, SIGNAL(clicked()), this, SLOT(StartErosion()));
	connect(uiw.spawnTreeButton, SIGNAL(clicked()), this, SLOT(SpawnTree()));


	// Widget edition
	connect(meshWidget, SIGNAL(_signalEditSceneLeft(const Ray&)), this, SLOT(editingSceneLeft(const Ray&)));
	connect(meshWidget, SIGNAL(_signalEditSceneRight(const Ray&)), this, SLOT(editingSceneRight(const Ray&)));
}

void MainWindow::editingSceneLeft(const Ray&)
{
}

void MainWindow::editingSceneRight(const Ray&)
{
}

void MainWindow::BoxMeshExample()
{
	meshColor = MeshColor(Mesh(Box(1.0)));
	UpdateGeometry();
}

void MainWindow::UpdateGeometry()
{
	meshWidget->ClearAll();
	meshWidget->AddMesh("BoxMesh", meshColor);

	uiw.lineEdit->setText(QString::number(meshColor.Vertexes()));
	uiw.lineEdit_2->setText(QString::number(meshColor.Triangles()));

	UpdateMaterial();
}

void MainWindow::UpdateMaterial()
{
	meshWidget->UseWireframeGlobal(uiw.wireframe->isChecked());
}

void MainWindow::ResetCamera()
{
	meshWidget->SetCamera(Camera(Vector(-10.0), Vector(0.0)));
}

void MainWindow::ChangeCameraProjection() {
	meshWidget->SetCameraMode(uiw.orthographic_mode->isChecked());
}


void MainWindow::GeneratePlaneMesh() {

	QImage image = QImage();

	Box b = Box(Vector(0, 0, 0), Vector(10, 10, 0));
	currentTerrain = Terrain(image, b, 2);

	meshColor = MeshColor(currentTerrain.toMesh());

	meshWidget->ClearAll();
	meshWidget->AddMesh("TerrainMesh", meshColor);

	uiw.lineEdit->setText(QString::number(meshColor.Vertexes()));
	uiw.lineEdit_2->setText(QString::number(meshColor.Triangles()));

	UpdateMaterial();
}

void MainWindow::StartErosion()
{
	ErosionParameter param = ErosionParameter();
	currentTerrain = Erosion::ErodeTerrain(1000, currentTerrain, param);
	meshColor = MeshColor(currentTerrain.toMesh());
	meshWidget->ClearAll();
	meshWidget->AddMesh("TerrainMesh", meshColor);

	uiw.lineEdit->setText(QString::number(meshColor.Vertexes()));
	uiw.lineEdit_2->setText(QString::number(meshColor.Triangles()));

	UpdateMaterial();
}

void MainWindow::UpdateTerrain()
{
	meshWidget->DeleteMesh("TerrainMesh");
	meshColor = MeshColor(currentTerrain.toMesh());
	meshWidget->AddMesh("TerrainMesh", meshColor);
	UpdateMaterial();
}

void MainWindow::SpawnTree()
{


	//fix problem
	int maxY = currentTerrain.nj;
	int ratioX = currentTerrain.getIntervalX();
	int ratioY = currentTerrain.getIntervalY();
	int xpos = 0;
	int ypos = 0;
	int zpos;
	
	vector<int> treeList = currentTerrain.getTreeList();
	
	for (int i = 0; i<treeList.size();i++) {
		
		
		
		if (treeList[i] > 0){
			zpos = currentTerrain.getHeight(i);
			meshColor = MeshColor(Mesh(Box(0.5)));
			Vector dir(xpos* ratioX, ypos*ratioY, zpos);
			meshColor.Translate(dir);
			meshWidget->AddMesh("tree"+i, meshColor);
			
		}



		if (ypos == maxY) {
			ypos = 0;
			xpos++;
		}
		else {
			ypos++;
		}

		

	}

	


	
	UpdateMaterial();
}
