#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <QMainWindow>
#include <QImage>
#include <QGraphicsScene>
#include <QVector2D>
#include <QGenericMatrix>
#include <QtCharts>
#include <QLineSeries>
#include <QChartView>

namespace Ui {
class VentanaPrincipal;
}

class VentanaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaPrincipal(QWidget *parent = 0);
    ~VentanaPrincipal();

private slots:
    void on_actionAbrir_Imagen_triggered();

    void on_actionOperador_Igualdad_triggered();

    void on_actionInverso_Negativo_triggered();

    void on_actionUmbral_triggered();

    void on_actionUmbral_Binario_triggered();

    void on_actionUmbral_Binario_Invertido_triggered();

    void on_actionAbrir_chart_triggered();

    void on_actionUmbral_Escala_de_Grises_triggered();

    void on_actionExtension_triggered();

    void on_actionTranslacion_triggered();

    void on_actionRotacion_triggered();

    void on_actionNegativo_a_Imagen_a_Color_triggered();

    void on_actionAbrir_Imagen_a_Color_triggered();

    void on_actionTraslacion_Color_triggered();

    void on_actionEscalar_triggered();

private:
    Ui::VentanaPrincipal *ui;
    QImage *imgOriginal;
    QImage *imgProcesada;
    QGraphicsScene *escenaOriginal;
    QGraphicsScene *escenaProcesada;
    QGenericMatrix<3,3,int> matriz;
    QVector2D v;
    int nivelDeUmbral;
    int u1;
    int u2;

    //Funciones del apartado archivo
    void abrirImagen();

    //Funciones de los operadores
    void realizarIgualdad();
    void realizarInversoNegativo();
    void realizarUmbral();
    void realizarIntervaloUmbralBinario();
    void realizarUmbralBinarioInv();
    void realizarUmbralEscalaGrises();
    void realizarEscalaGrisesInv();
    void realizarExtension();
    void realizarTraslacion();
    void realizarRotacion();
    void realizarEscalamiento();
    void realizarInversoNegativoColor();
    void realizarTraslacionColor();

    //Funciones para el los histogramas
    void crearHistogramaOriginal();
    void crearHistogramaProcesada();
    void crearHistogramaOriginalColor();
    void crearHistogramaProcesadaColor();

};

#endif // VENTANAPRINCIPAL_H
