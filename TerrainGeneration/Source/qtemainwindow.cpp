#include "qte.h"


#include <QtWidgets/qfiledialog.h>
#include "terrain.h"

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

	QString imagePath;
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
	connect(uiw.planeMeshButton, SIGNAL(clicked()), this, SLOT(GeneratePlaneMesh()));
	connect(uiw.loadHeightmapButton, SIGNAL(clicked()), this, SLOT(ChangeHeightmapImage()));

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

	int width = uiw.planeMesh_X->value();
	int height = uiw.planeMesh_Y->value();
	int resolutionX = uiw.planeMesh_Res_X->value();
	int resolutionY = uiw.planeMesh_Res_Y->value();

	Terrain terrain(width, height, resolutionX, resolutionY);

	if (uiw.useHeightmap->isChecked()) {
		QImage img(imagePath);
		terrain.heightmap = img;
		terrain.heightscale = 5;
	}
	terrain.Generate();
	
	meshColor = MeshColor(terrain);

	meshWidget->ClearAll();
	meshWidget->AddMesh("PlaneMesh", meshColor);

	uiw.lineEdit->setText(QString::number(meshColor.Vertexes()));
	uiw.lineEdit_2->setText(QString::number(meshColor.Triangles()));

	UpdateMaterial();
}

void MainWindow::ChangeHeightmapImage() {
	imagePath = QFileDialog::getOpenFileName(this, tr("Open Image"), "/", tr("Image Files (*.png *.jpg)"));
	if (!imagePath.isEmpty()) {
		QPixmap preview(imagePath);
		if (!preview.isNull()) {
			uiw.selectedImage->clear();
			uiw.selectedImage->setPixmap(preview);
		}
	}
}
