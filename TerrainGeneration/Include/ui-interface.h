/********************************************************************************
** Form generated from reading UI file 'interface.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_2D_INTERFACE_H
#define UI_2D_INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Assets
{
public:
    QAction *actionExit;
    QAction *actionNew_Scene;
    QAction *actionExport_obj;
    QAction *actionExport_ma;
    QAction *actionLoad_ma;
    QAction *actionGL;
    QAction *actionVectorized;
    QAction *actionExport_svg;
    QAction *actionSphere_Tracing_png;
    QWidget *centralwidget;
    QHBoxLayout *hboxLayout;
    QGroupBox *Objects_groupBox;
    QGroupBox *LoadingBox;
    QPushButton *boxMesh;
    QPushButton *planeMeshButton;
    QLabel *label;
    QLabel *label_4;
    QSpinBox *planeMesh_Y;
    QSpinBox *planeMesh_X;
    QSpinBox *planeMesh_Res_X;
    QLabel *label_5;
    QLabel *label_6;
    QSpinBox *planeMesh_Res_Y;
    QCheckBox *useHeightmap;
    QWidget *widget_GL;
    QGroupBox *Parameters_groupBox;
    QGroupBox *groupBox_4;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QGroupBox *ShadingBox;
    QRadioButton *radioShadingButton_1;
    QCheckBox *wireframe;
    QGroupBox *CameraBox;
    QCheckBox *orthographic_mode;
    QPushButton *resetcameraButton;
    QGroupBox *groupBox;
    QLabel *selectedImage;
    QPushButton *loadHeightmapButton;
    QMenuBar *menubar;
    QMenu *menuFile;

    void setupUi(QMainWindow *Assets)
    {
        if (Assets->objectName().isEmpty())
            Assets->setObjectName(QString::fromUtf8("Assets"));
        Assets->resize(1193, 1000);
        Assets->setMinimumSize(QSize(420, 300));
        actionExit = new QAction(Assets);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionNew_Scene = new QAction(Assets);
        actionNew_Scene->setObjectName(QString::fromUtf8("actionNew_Scene"));
        actionExport_obj = new QAction(Assets);
        actionExport_obj->setObjectName(QString::fromUtf8("actionExport_obj"));
        actionExport_ma = new QAction(Assets);
        actionExport_ma->setObjectName(QString::fromUtf8("actionExport_ma"));
        actionLoad_ma = new QAction(Assets);
        actionLoad_ma->setObjectName(QString::fromUtf8("actionLoad_ma"));
        actionGL = new QAction(Assets);
        actionGL->setObjectName(QString::fromUtf8("actionGL"));
        actionVectorized = new QAction(Assets);
        actionVectorized->setObjectName(QString::fromUtf8("actionVectorized"));
        actionExport_svg = new QAction(Assets);
        actionExport_svg->setObjectName(QString::fromUtf8("actionExport_svg"));
        actionSphere_Tracing_png = new QAction(Assets);
        actionSphere_Tracing_png->setObjectName(QString::fromUtf8("actionSphere_Tracing_png"));
        centralwidget = new QWidget(Assets);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        hboxLayout = new QHBoxLayout(centralwidget);
        hboxLayout->setSpacing(0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        Objects_groupBox = new QGroupBox(centralwidget);
        Objects_groupBox->setObjectName(QString::fromUtf8("Objects_groupBox"));
        Objects_groupBox->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Objects_groupBox->sizePolicy().hasHeightForWidth());
        Objects_groupBox->setSizePolicy(sizePolicy);
        Objects_groupBox->setMinimumSize(QSize(350, 250));
        LoadingBox = new QGroupBox(Objects_groupBox);
        LoadingBox->setObjectName(QString::fromUtf8("LoadingBox"));
        LoadingBox->setGeometry(QRect(20, 20, 311, 251));
        LoadingBox->setFlat(false);
        boxMesh = new QPushButton(LoadingBox);
        boxMesh->setObjectName(QString::fromUtf8("boxMesh"));
        boxMesh->setGeometry(QRect(20, 20, 81, 23));
        boxMesh->setCheckable(false);
        planeMeshButton = new QPushButton(LoadingBox);
        planeMeshButton->setObjectName(QString::fromUtf8("planeMeshButton"));
        planeMeshButton->setGeometry(QRect(20, 60, 81, 23));
        planeMeshButton->setCheckable(false);
        label = new QLabel(LoadingBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 90, 31, 21));
        label_4 = new QLabel(LoadingBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 120, 31, 21));
        planeMesh_Y = new QSpinBox(LoadingBox);
        planeMesh_Y->setObjectName(QString::fromUtf8("planeMesh_Y"));
        planeMesh_Y->setGeometry(QRect(60, 120, 42, 22));
        planeMesh_Y->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        planeMesh_Y->setMinimum(1);
        planeMesh_Y->setMaximum(500);
        planeMesh_Y->setValue(1);
        planeMesh_X = new QSpinBox(LoadingBox);
        planeMesh_X->setObjectName(QString::fromUtf8("planeMesh_X"));
        planeMesh_X->setGeometry(QRect(60, 90, 42, 22));
        planeMesh_X->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        planeMesh_X->setMinimum(1);
        planeMesh_X->setMaximum(500);
        planeMesh_X->setValue(1);
        planeMesh_Res_X = new QSpinBox(LoadingBox);
        planeMesh_Res_X->setObjectName(QString::fromUtf8("planeMesh_Res_X"));
        planeMesh_Res_X->setGeometry(QRect(190, 90, 42, 22));
        planeMesh_Res_X->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        planeMesh_Res_X->setMinimum(1);
        planeMesh_Res_X->setMaximum(400);
        planeMesh_Res_X->setValue(1);
        label_5 = new QLabel(LoadingBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(120, 90, 61, 21));
        label_6 = new QLabel(LoadingBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(120, 120, 61, 21));
        planeMesh_Res_Y = new QSpinBox(LoadingBox);
        planeMesh_Res_Y->setObjectName(QString::fromUtf8("planeMesh_Res_Y"));
        planeMesh_Res_Y->setGeometry(QRect(190, 120, 42, 22));
        planeMesh_Res_Y->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        planeMesh_Res_Y->setMinimum(1);
        planeMesh_Res_Y->setMaximum(400);
        planeMesh_Res_Y->setValue(1);
        useHeightmap = new QCheckBox(LoadingBox);
        useHeightmap->setObjectName(QString::fromUtf8("useHeightmap"));
        useHeightmap->setGeometry(QRect(20, 150, 101, 17));

        hboxLayout->addWidget(Objects_groupBox);

        widget_GL = new QWidget(centralwidget);
        widget_GL->setObjectName(QString::fromUtf8("widget_GL"));

        hboxLayout->addWidget(widget_GL);

        Parameters_groupBox = new QGroupBox(centralwidget);
        Parameters_groupBox->setObjectName(QString::fromUtf8("Parameters_groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Parameters_groupBox->sizePolicy().hasHeightForWidth());
        Parameters_groupBox->setSizePolicy(sizePolicy1);
        Parameters_groupBox->setMinimumSize(QSize(450, 141));
        groupBox_4 = new QGroupBox(Parameters_groupBox);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 20, 171, 121));
        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 20, 61, 21));
        lineEdit_2 = new QLineEdit(groupBox_4);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(70, 50, 81, 20));
        lineEdit_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_2->setReadOnly(true);
        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 50, 61, 21));
        lineEdit = new QLineEdit(groupBox_4);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(70, 20, 81, 20));
        lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit->setReadOnly(true);
        ShadingBox = new QGroupBox(Parameters_groupBox);
        ShadingBox->setObjectName(QString::fromUtf8("ShadingBox"));
        ShadingBox->setGeometry(QRect(190, 20, 251, 121));
        radioShadingButton_1 = new QRadioButton(ShadingBox);
        radioShadingButton_1->setObjectName(QString::fromUtf8("radioShadingButton_1"));
        radioShadingButton_1->setGeometry(QRect(20, 20, 61, 20));
        radioShadingButton_1->setChecked(true);
        wireframe = new QCheckBox(ShadingBox);
        wireframe->setObjectName(QString::fromUtf8("wireframe"));
        wireframe->setGeometry(QRect(90, 20, 81, 17));
        wireframe->setChecked(true);
        CameraBox = new QGroupBox(Parameters_groupBox);
        CameraBox->setObjectName(QString::fromUtf8("CameraBox"));
        CameraBox->setGeometry(QRect(190, 150, 251, 51));
        CameraBox->setFlat(false);
        orthographic_mode = new QCheckBox(CameraBox);
        orthographic_mode->setObjectName(QString::fromUtf8("orthographic_mode"));
        orthographic_mode->setGeometry(QRect(20, 20, 81, 17));
        orthographic_mode->setChecked(true);
        resetcameraButton = new QPushButton(CameraBox);
        resetcameraButton->setObjectName(QString::fromUtf8("resetcameraButton"));
        resetcameraButton->setGeometry(QRect(130, 20, 81, 23));
        resetcameraButton->setCheckable(true);
        resetcameraButton->setAutoDefault(false);
        resetcameraButton->setFlat(false);
        groupBox = new QGroupBox(Parameters_groupBox);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 150, 171, 191));
        selectedImage = new QLabel(groupBox);
        selectedImage->setObjectName(QString::fromUtf8("selectedImage"));
        selectedImage->setGeometry(QRect(10, 20, 101, 101));
        selectedImage->setMouseTracking(true);
        selectedImage->setContextMenuPolicy(Qt::CustomContextMenu);
        selectedImage->setAcceptDrops(true);
        selectedImage->setFrameShape(QFrame::Box);
        selectedImage->setFrameShadow(QFrame::Plain);
        selectedImage->setTextFormat(Qt::RichText);
        selectedImage->setScaledContents(true);
        selectedImage->setAlignment(Qt::AlignCenter);
        selectedImage->setTextInteractionFlags(Qt::NoTextInteraction);
        loadHeightmapButton = new QPushButton(groupBox);
        loadHeightmapButton->setObjectName(QString::fromUtf8("loadHeightmapButton"));
        loadHeightmapButton->setGeometry(QRect(10, 130, 71, 23));
        loadHeightmapButton->setCheckable(false);

        hboxLayout->addWidget(Parameters_groupBox);

        Assets->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Assets);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1193, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        Assets->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());

        retranslateUi(Assets);

        resetcameraButton->setDefault(false);


        QMetaObject::connectSlotsByName(Assets);
    } // setupUi

    void retranslateUi(QMainWindow *Assets)
    {
        Assets->setWindowTitle(QCoreApplication::translate("Assets", "Implicit Terrain", nullptr));
        actionExit->setText(QCoreApplication::translate("Assets", "Exit", nullptr));
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("Assets", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        actionNew_Scene->setText(QCoreApplication::translate("Assets", "New Scene", nullptr));
        actionExport_obj->setText(QCoreApplication::translate("Assets", "OBJ File (.obj)", nullptr));
        actionExport_ma->setText(QCoreApplication::translate("Assets", "Maya File (.ma)", nullptr));
        actionLoad_ma->setText(QCoreApplication::translate("Assets", "Load", nullptr));
        actionGL->setText(QCoreApplication::translate("Assets", "GL", nullptr));
        actionVectorized->setText(QCoreApplication::translate("Assets", "Vectorized", nullptr));
        actionExport_svg->setText(QCoreApplication::translate("Assets", "SVG File (.svg)", nullptr));
        actionSphere_Tracing_png->setText(QCoreApplication::translate("Assets", "Sphere Tracing (.png)", nullptr));
        Objects_groupBox->setTitle(QString());
        LoadingBox->setTitle(QCoreApplication::translate("Assets", "Load", nullptr));
#if QT_CONFIG(tooltip)
        boxMesh->setToolTip(QCoreApplication::translate("Assets", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#5500ff;\">Callback #01</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-style:italic; color:#aa00ff;\">Create Eurographics 1996 Bear</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        boxMesh->setText(QCoreApplication::translate("Assets", "Box Mesh", nullptr));
#if QT_CONFIG(tooltip)
        planeMeshButton->setToolTip(QCoreApplication::translate("Assets", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#5500ff;\">Callback #01</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-style:italic; color:#aa00ff;\">Create Eurographics 1996 Bear</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        planeMeshButton->setText(QCoreApplication::translate("Assets", "Plane Mesh", nullptr));
        label->setText(QCoreApplication::translate("Assets", "Width", nullptr));
        label_4->setText(QCoreApplication::translate("Assets", "Height", nullptr));
        label_5->setText(QCoreApplication::translate("Assets", "Resolution X", nullptr));
        label_6->setText(QCoreApplication::translate("Assets", "Resolution Y", nullptr));
        useHeightmap->setText(QCoreApplication::translate("Assets", "Use Heightmap", nullptr));
        Parameters_groupBox->setTitle(QString());
        groupBox_4->setTitle(QCoreApplication::translate("Assets", " Statistics", nullptr));
        label_2->setText(QCoreApplication::translate("Assets", "Vertex", nullptr));
        label_3->setText(QCoreApplication::translate("Assets", "Triangles", nullptr));
        lineEdit->setText(QString());
        ShadingBox->setTitle(QCoreApplication::translate("Assets", "Shading", nullptr));
        radioShadingButton_1->setText(QCoreApplication::translate("Assets", "Normal", nullptr));
        wireframe->setText(QCoreApplication::translate("Assets", "Wireframe", nullptr));
        CameraBox->setTitle(QCoreApplication::translate("Assets", "Camera", nullptr));
        orthographic_mode->setText(QCoreApplication::translate("Assets", "Orthographic", nullptr));
#if QT_CONFIG(tooltip)
        resetcameraButton->setToolTip(QCoreApplication::translate("Assets", "<html><head/><body><p><span style=\" color:#5500ff;\">Callback #03</span></p><p><span style=\" font-style:italic; color:#aa00ff;\">Create Eurographics 1996 Bird</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        resetcameraButton->setText(QCoreApplication::translate("Assets", "Reset Camera", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Assets", "Heightmap", nullptr));
        selectedImage->setText(QCoreApplication::translate("Assets", "No image", nullptr));
#if QT_CONFIG(tooltip)
        loadHeightmapButton->setToolTip(QCoreApplication::translate("Assets", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#5500ff;\">Callback #01</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-style:italic; color:#aa00ff;\">Create Eurographics 1996 Bear</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        loadHeightmapButton->setText(QCoreApplication::translate("Assets", "Select File", nullptr));
        menuFile->setTitle(QCoreApplication::translate("Assets", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Assets: public Ui_Assets {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_2D_INTERFACE_H
