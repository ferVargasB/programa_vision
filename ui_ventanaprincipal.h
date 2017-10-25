/********************************************************************************
** Form generated from reading UI file 'ventanaprincipal.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANAPRINCIPAL_H
#define UI_VENTANAPRINCIPAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VentanaPrincipal
{
public:
    QAction *actionAbrir_Imagen;
    QAction *actionOperador_Igualdad;
    QAction *actionInverso_Negativo;
    QAction *actionUmbral;
    QAction *actionUmbral_Binario;
    QAction *actionUmbral_Binario_Invertido;
    QAction *actionAbrir_chart;
    QAction *actionUmbral_Escala_de_Grises;
    QAction *actionExtension;
    QAction *actionTranslacion;
    QAction *actionRotacion;
    QAction *actionNegativo_a_Imagen_a_Color;
    QAction *actionAbrir_Imagen_a_Color;
    QAction *actionTraslacion_Color;
    QAction *actionEscalar;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *layOutOriginal;
    QLabel *labelImagenPrincipal;
    QGraphicsView *graphicsViewOriginal;
    QVBoxLayout *layOutProcesada;
    QLabel *labelImagenProcesada;
    QGraphicsView *graphicsViewProcesada;
    QMenuBar *menuBar;
    QMenu *menuOperadores;
    QMenu *menuArchivo;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *VentanaPrincipal)
    {
        if (VentanaPrincipal->objectName().isEmpty())
            VentanaPrincipal->setObjectName(QStringLiteral("VentanaPrincipal"));
        VentanaPrincipal->resize(729, 524);
        actionAbrir_Imagen = new QAction(VentanaPrincipal);
        actionAbrir_Imagen->setObjectName(QStringLiteral("actionAbrir_Imagen"));
        actionOperador_Igualdad = new QAction(VentanaPrincipal);
        actionOperador_Igualdad->setObjectName(QStringLiteral("actionOperador_Igualdad"));
        actionInverso_Negativo = new QAction(VentanaPrincipal);
        actionInverso_Negativo->setObjectName(QStringLiteral("actionInverso_Negativo"));
        actionUmbral = new QAction(VentanaPrincipal);
        actionUmbral->setObjectName(QStringLiteral("actionUmbral"));
        actionUmbral_Binario = new QAction(VentanaPrincipal);
        actionUmbral_Binario->setObjectName(QStringLiteral("actionUmbral_Binario"));
        actionUmbral_Binario_Invertido = new QAction(VentanaPrincipal);
        actionUmbral_Binario_Invertido->setObjectName(QStringLiteral("actionUmbral_Binario_Invertido"));
        actionAbrir_chart = new QAction(VentanaPrincipal);
        actionAbrir_chart->setObjectName(QStringLiteral("actionAbrir_chart"));
        actionUmbral_Escala_de_Grises = new QAction(VentanaPrincipal);
        actionUmbral_Escala_de_Grises->setObjectName(QStringLiteral("actionUmbral_Escala_de_Grises"));
        actionExtension = new QAction(VentanaPrincipal);
        actionExtension->setObjectName(QStringLiteral("actionExtension"));
        actionTranslacion = new QAction(VentanaPrincipal);
        actionTranslacion->setObjectName(QStringLiteral("actionTranslacion"));
        actionRotacion = new QAction(VentanaPrincipal);
        actionRotacion->setObjectName(QStringLiteral("actionRotacion"));
        actionNegativo_a_Imagen_a_Color = new QAction(VentanaPrincipal);
        actionNegativo_a_Imagen_a_Color->setObjectName(QStringLiteral("actionNegativo_a_Imagen_a_Color"));
        actionAbrir_Imagen_a_Color = new QAction(VentanaPrincipal);
        actionAbrir_Imagen_a_Color->setObjectName(QStringLiteral("actionAbrir_Imagen_a_Color"));
        actionTraslacion_Color = new QAction(VentanaPrincipal);
        actionTraslacion_Color->setObjectName(QStringLiteral("actionTraslacion_Color"));
        actionEscalar = new QAction(VentanaPrincipal);
        actionEscalar->setObjectName(QStringLiteral("actionEscalar"));
        centralWidget = new QWidget(VentanaPrincipal);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        layOutOriginal = new QVBoxLayout();
        layOutOriginal->setSpacing(6);
        layOutOriginal->setObjectName(QStringLiteral("layOutOriginal"));
        labelImagenPrincipal = new QLabel(centralWidget);
        labelImagenPrincipal->setObjectName(QStringLiteral("labelImagenPrincipal"));
        labelImagenPrincipal->setAlignment(Qt::AlignCenter);

        layOutOriginal->addWidget(labelImagenPrincipal);

        graphicsViewOriginal = new QGraphicsView(centralWidget);
        graphicsViewOriginal->setObjectName(QStringLiteral("graphicsViewOriginal"));

        layOutOriginal->addWidget(graphicsViewOriginal);


        gridLayout->addLayout(layOutOriginal, 0, 0, 1, 1);

        layOutProcesada = new QVBoxLayout();
        layOutProcesada->setSpacing(6);
        layOutProcesada->setObjectName(QStringLiteral("layOutProcesada"));
        labelImagenProcesada = new QLabel(centralWidget);
        labelImagenProcesada->setObjectName(QStringLiteral("labelImagenProcesada"));
        labelImagenProcesada->setAlignment(Qt::AlignCenter);

        layOutProcesada->addWidget(labelImagenProcesada);

        graphicsViewProcesada = new QGraphicsView(centralWidget);
        graphicsViewProcesada->setObjectName(QStringLiteral("graphicsViewProcesada"));

        layOutProcesada->addWidget(graphicsViewProcesada);


        gridLayout->addLayout(layOutProcesada, 0, 1, 1, 1);

        VentanaPrincipal->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(VentanaPrincipal);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 729, 22));
        menuOperadores = new QMenu(menuBar);
        menuOperadores->setObjectName(QStringLiteral("menuOperadores"));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QStringLiteral("menuArchivo"));
        VentanaPrincipal->setMenuBar(menuBar);
        mainToolBar = new QToolBar(VentanaPrincipal);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        VentanaPrincipal->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(VentanaPrincipal);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        VentanaPrincipal->setStatusBar(statusBar);

        menuBar->addAction(menuOperadores->menuAction());
        menuBar->addAction(menuArchivo->menuAction());
        menuOperadores->addAction(actionOperador_Igualdad);
        menuOperadores->addAction(actionInverso_Negativo);
        menuOperadores->addAction(actionUmbral);
        menuOperadores->addAction(actionUmbral_Binario);
        menuOperadores->addAction(actionUmbral_Binario_Invertido);
        menuOperadores->addAction(actionUmbral_Escala_de_Grises);
        menuOperadores->addAction(actionExtension);
        menuOperadores->addAction(actionTranslacion);
        menuOperadores->addAction(actionRotacion);
        menuOperadores->addAction(actionEscalar);
        menuOperadores->addAction(actionNegativo_a_Imagen_a_Color);
        menuOperadores->addAction(actionTraslacion_Color);
        menuArchivo->addAction(actionAbrir_Imagen);
        menuArchivo->addAction(actionAbrir_chart);
        menuArchivo->addAction(actionAbrir_Imagen_a_Color);

        retranslateUi(VentanaPrincipal);

        QMetaObject::connectSlotsByName(VentanaPrincipal);
    } // setupUi

    void retranslateUi(QMainWindow *VentanaPrincipal)
    {
        VentanaPrincipal->setWindowTitle(QApplication::translate("VentanaPrincipal", "VentanaPrincipal", Q_NULLPTR));
        actionAbrir_Imagen->setText(QApplication::translate("VentanaPrincipal", "Abrir Imagen", Q_NULLPTR));
        actionOperador_Igualdad->setText(QApplication::translate("VentanaPrincipal", "Operador Igualdad", Q_NULLPTR));
        actionInverso_Negativo->setText(QApplication::translate("VentanaPrincipal", "Inverso Negativo", Q_NULLPTR));
        actionUmbral->setText(QApplication::translate("VentanaPrincipal", "Umbral", Q_NULLPTR));
        actionUmbral_Binario->setText(QApplication::translate("VentanaPrincipal", "Umbral Binario", Q_NULLPTR));
        actionUmbral_Binario_Invertido->setText(QApplication::translate("VentanaPrincipal", "Umbral Binario Invertido", Q_NULLPTR));
        actionAbrir_chart->setText(QApplication::translate("VentanaPrincipal", "Abrir chart", Q_NULLPTR));
        actionUmbral_Escala_de_Grises->setText(QApplication::translate("VentanaPrincipal", "Umbral Escala de Grises", Q_NULLPTR));
        actionExtension->setText(QApplication::translate("VentanaPrincipal", "Extension", Q_NULLPTR));
        actionTranslacion->setText(QApplication::translate("VentanaPrincipal", "Translacion", Q_NULLPTR));
        actionRotacion->setText(QApplication::translate("VentanaPrincipal", "Rotacion", Q_NULLPTR));
        actionNegativo_a_Imagen_a_Color->setText(QApplication::translate("VentanaPrincipal", "Negativo a Imagen a Color", Q_NULLPTR));
        actionAbrir_Imagen_a_Color->setText(QApplication::translate("VentanaPrincipal", "Abrir Imagen a Color", Q_NULLPTR));
        actionTraslacion_Color->setText(QApplication::translate("VentanaPrincipal", "Traslacion Color", Q_NULLPTR));
        actionEscalar->setText(QApplication::translate("VentanaPrincipal", "Escalar", Q_NULLPTR));
        labelImagenPrincipal->setText(QApplication::translate("VentanaPrincipal", "Principal", Q_NULLPTR));
        labelImagenProcesada->setText(QApplication::translate("VentanaPrincipal", "Imagen Procesada", Q_NULLPTR));
        menuOperadores->setTitle(QApplication::translate("VentanaPrincipal", "Operadores", Q_NULLPTR));
        menuArchivo->setTitle(QApplication::translate("VentanaPrincipal", "Archivo", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VentanaPrincipal: public Ui_VentanaPrincipal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANAPRINCIPAL_H
