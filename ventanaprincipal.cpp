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
    imgOriginal = new QImage;
    escenaOriginal = new QGraphicsScene;
    escenaProcesada = new QGraphicsScene;
    ui->graphicsView->setScene(escenaOriginal);
    ui->graphicsView_2->setScene(escenaProcesada);

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
    imgOriginal = &img;
    escenaOriginal->addPixmap(QPixmap::fromImage(*imgOriginal));
}

void VentanaPrincipal::realizarIgualdad()
{
    QImage imgCopia(imgOriginal->width(), imgOriginal->height(), QImage::Format);
    for (int c = 0; c < imgOriginal->width(); c++){
        for (int f = 0; f < imgOriginal->height(); f++){
             QColor pixel = imgOriginal->pixelColor(c,f);
             imgCopia.setPixelColor(c,f,pixel);
        }
    }
    imgProcesada = &imgCopia;
    escenaProcesada->addPixmap(QPixmap::fromImage(*imgProcesada));
}

void VentanaPrincipal::on_actionAbrir_Imagen_triggered()
{
    abrirImagen();
}

void VentanaPrincipal::convertirGris()
{

}

void VentanaPrincipal::on_actionOperador_Igualdad_triggered()
{
    realizarIgualdad();
}
