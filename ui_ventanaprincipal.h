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
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *labelImagenPrincipal;
    QGraphicsView *graphicsViewOriginal;
    QLabel *labelHistogranaOriginal;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelImagenProcesada;
    QGraphicsView *graphicsViewProcesada;
    QLabel *labelHistogranaProcesada;
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
        centralWidget = new QWidget(VentanaPrincipal);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        labelImagenPrincipal = new QLabel(centralWidget);
        labelImagenPrincipal->setObjectName(QStringLiteral("labelImagenPrincipal"));
        labelImagenPrincipal->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelImagenPrincipal);

        graphicsViewOriginal = new QGraphicsView(centralWidget);
        graphicsViewOriginal->setObjectName(QStringLiteral("graphicsViewOriginal"));

        verticalLayout->addWidget(graphicsViewOriginal);

        labelHistogranaOriginal = new QLabel(centralWidget);
        labelHistogranaOriginal->setObjectName(QStringLiteral("labelHistogranaOriginal"));
        labelHistogranaOriginal->setFrameShape(QFrame::WinPanel);
        labelHistogranaOriginal->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelHistogranaOriginal);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        labelImagenProcesada = new QLabel(centralWidget);
        labelImagenProcesada->setObjectName(QStringLiteral("labelImagenProcesada"));
        labelImagenProcesada->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(labelImagenProcesada);

        graphicsViewProcesada = new QGraphicsView(centralWidget);
        graphicsViewProcesada->setObjectName(QStringLiteral("graphicsViewProcesada"));

        verticalLayout_2->addWidget(graphicsViewProcesada);

        labelHistogranaProcesada = new QLabel(centralWidget);
        labelHistogranaProcesada->setObjectName(QStringLiteral("labelHistogranaProcesada"));
        labelHistogranaProcesada->setFrameShape(QFrame::WinPanel);
        labelHistogranaProcesada->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(labelHistogranaProcesada);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);

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
        menuArchivo->addAction(actionAbrir_Imagen);

        retranslateUi(VentanaPrincipal);

        QMetaObject::connectSlotsByName(VentanaPrincipal);
    } // setupUi

    void retranslateUi(QMainWindow *VentanaPrincipal)
    {
        VentanaPrincipal->setWindowTitle(QApplication::translate("VentanaPrincipal", "VentanaPrincipal", Q_NULLPTR));
        actionAbrir_Imagen->setText(QApplication::translate("VentanaPrincipal", "Abrir Imagen", Q_NULLPTR));
        actionOperador_Igualdad->setText(QApplication::translate("VentanaPrincipal", "Operador Igualdad", Q_NULLPTR));
        labelImagenPrincipal->setText(QApplication::translate("VentanaPrincipal", "Imagen Pricipal", Q_NULLPTR));
        labelHistogranaOriginal->setText(QApplication::translate("VentanaPrincipal", "H Original", Q_NULLPTR));
        labelImagenProcesada->setText(QApplication::translate("VentanaPrincipal", "Imagen Procesada", Q_NULLPTR));
        labelHistogranaProcesada->setText(QApplication::translate("VentanaPrincipal", "H Procesada", Q_NULLPTR));
        menuOperadores->setTitle(QApplication::translate("VentanaPrincipal", "Operadores", Q_NULLPTR));
        menuArchivo->setTitle(QApplication::translate("VentanaPrincipal", "Archivo", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VentanaPrincipal: public Ui_VentanaPrincipal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANAPRINCIPAL_H