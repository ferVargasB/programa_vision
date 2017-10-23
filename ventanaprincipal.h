#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <QMainWindow>
#include <QImage>
#include <QGraphicsScene>
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

private:
    Ui::VentanaPrincipal *ui;
    QImage *imgOriginal;
    QImage *imgProcesada;
    QGraphicsScene *escenaOriginal;
    QGraphicsScene *escenaProcesada;

    //funcion para convertir a escala de grises
    void convertirGris();

    //Funciones del apartado archivo
    void abrirImagen();

    //Funciones de los operadores
    void realizarIgualdad();
};

#endif // VENTANAPRINCIPAL_H
