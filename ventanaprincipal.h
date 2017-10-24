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

    void on_actionInverso_Negativo_triggered();

    void on_actionUmbral_triggered();

    void on_actionUmbral_Binario_triggered();

    void on_actionUmbral_Binario_Invertido_triggered();

private:
    Ui::VentanaPrincipal *ui;
    QImage *imgOriginal;
    QImage *imgProcesada;
    QGraphicsScene *escenaOriginal;
    QGraphicsScene *escenaProcesada;
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

};

#endif // VENTANAPRINCIPAL_H
