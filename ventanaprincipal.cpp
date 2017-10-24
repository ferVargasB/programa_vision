#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"

#include <QImage>
#include  <QFileDialog>
#include <QPixmap>

VentanaPrincipal::VentanaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaPrincipal)
{
    ui->setupUi(this);
    nivelDeUmbral = 76;
    imgOriginal = new QImage;
    imgProcesada = new QImage;
    escenaOriginal = new QGraphicsScene;
    escenaProcesada = new QGraphicsScene;
    ui->graphicsViewOriginal->setScene(escenaOriginal);
    ui->graphicsViewProcesada->setScene(escenaProcesada);

}

VentanaPrincipal::~VentanaPrincipal()
{
    delete ui;
}

void VentanaPrincipal::abrirImagen()
{
    QString archivo = QFileDialog::getOpenFileName(this,
        tr("Abrir"), "", tr("Archivos de Imagen (*.png *.jpg *.bmp)"));
    QImage img(archivo);
    img = img.convertToFormat(QImage::Format_Grayscale8,Qt::AutoColor);
    *imgOriginal = img;
    escenaOriginal->addPixmap(QPixmap::fromImage(*imgOriginal));
}

void VentanaPrincipal::realizarIgualdad()
{
    QImage imgCopia(imgOriginal->width(), imgOriginal->height(), QImage::Format_Grayscale8);
    for (int c = 0; c < imgOriginal->width(); c++){
        for (int f = 0; f < imgOriginal->height(); f++){
             QColor pixel = imgOriginal->pixelColor(c,f);
             imgCopia.setPixelColor(c,f,pixel);
        }
    }
    *imgProcesada = imgCopia;
    escenaProcesada->addPixmap(QPixmap::fromImage(*imgProcesada));
}

void VentanaPrincipal::realizarInversoNegativo()
{
    QImage imgCopia(imgOriginal->width(), imgOriginal->height(), QImage::Format_Grayscale8);
    for (int c = 0; c < imgOriginal->width(); c++){
        for (int f = 0; f < imgOriginal->height(); f++){
             QColor pixel = imgOriginal->pixelColor(c,f);
             auto nivelDeColor = pixel.value();
             imgCopia.setPixelColor(c,f,255-nivelDeColor);
        }
    }
    *imgProcesada = imgCopia;
    escenaProcesada->addPixmap(QPixmap::fromImage(*imgProcesada));
}

void VentanaPrincipal::realizarUmbral()
{
    QImage imgCopia(imgOriginal->width(), imgOriginal->height(), QImage::Format_Grayscale8);
    for (int c = 0; c < imgCopia.width(); c++){
        for (int f = 0; f < imgCopia.height(); f++){
             QColor pixel = imgOriginal->pixelColor(c,f);
             auto nivelDeColor = pixel.value();
             if ( nivelDeColor >= nivelDeUmbral){
                 imgCopia.setPixelColor(c,f, QColor(255,255,255));
             } else {
                 imgCopia.setPixelColor(c,f, QColor(0,0,0));
             }
        }
    }
    *imgProcesada = imgCopia;
    escenaProcesada->addPixmap(QPixmap::fromImage(*imgProcesada));
}

void VentanaPrincipal::on_actionAbrir_Imagen_triggered()
{
    abrirImagen();
}

void VentanaPrincipal::on_actionOperador_Igualdad_triggered()
{
    realizarIgualdad();
}

void VentanaPrincipal::on_actionInverso_Negativo_triggered()
{
    realizarInversoNegativo();
}

void VentanaPrincipal::on_actionUmbral_triggered()
{
    realizarUmbral();
}
