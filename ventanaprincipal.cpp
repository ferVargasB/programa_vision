#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"

#include <QImage>
#include <QFileDialog>
#include <QPixmap>
#include <QtCharts>
#include <QLineSeries>
#include <QChartView>

VentanaPrincipal::VentanaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaPrincipal)
{
    ui->setupUi(this);
    u1 = 40;
    u2 = 140;
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

void VentanaPrincipal::realizarIntervaloUmbralBinario()
{
    QImage imgCopia(imgOriginal->width(), imgOriginal->height(), QImage::Format_Grayscale8);
    for (int c = 0; c < imgCopia.width(); c++){
        for (int f = 0; f < imgCopia.height(); f++){
             QColor pixel = imgOriginal->pixelColor(c,f);
             auto nivelDeColor = pixel.value();
             if ( nivelDeColor > u1 && nivelDeColor < u2){
                 imgCopia.setPixelColor(c,f, QColor(255,255,255));
             } else {
                 imgCopia.setPixelColor(c,f, QColor(0,0,0));
             }
        }
    }
    *imgProcesada = imgCopia;
    escenaProcesada->addPixmap(QPixmap::fromImage(*imgProcesada));
}

void VentanaPrincipal::realizarUmbralBinarioInv()
{
    QImage imgCopia(imgOriginal->width(), imgOriginal->height(), QImage::Format_Grayscale8);
    for (int c = 0; c < imgCopia.width(); c++){
        for (int f = 0; f < imgCopia.height(); f++){
             QColor pixel = imgOriginal->pixelColor(c,f);
             auto nivelDeColor = pixel.value();
             if ( nivelDeColor > u1 && nivelDeColor < u2){
                 imgCopia.setPixelColor(c,f, QColor(0,0,0));
             } else {
                 imgCopia.setPixelColor(c,f, QColor(255,255,255));
             }
        }
    }
    *imgProcesada = imgCopia;
    escenaProcesada->addPixmap(QPixmap::fromImage(*imgProcesada));
}

void VentanaPrincipal::realizarUmbralEscalaGrises()
{
    QImage imgCopia(imgOriginal->width(), imgOriginal->height(), QImage::Format_Grayscale8);
    for (int c = 0; c < imgCopia.width(); c++){
        for (int f = 0; f < imgCopia.height(); f++){
             QColor pixel = imgOriginal->pixelColor(c,f);
             auto nivelDeColor = pixel.value();
             if ( nivelDeColor > u1 && nivelDeColor < u2){
                 imgCopia.setPixelColor(c,f, pixel);
             } else {
                 imgCopia.setPixelColor(c,f, QColor(255,255,255));
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

void VentanaPrincipal::on_actionUmbral_Binario_triggered()
{
    realizarIntervaloUmbralBinario();
}

void VentanaPrincipal::on_actionUmbral_Binario_Invertido_triggered()
{
    realizarUmbralBinarioInv();
}

void VentanaPrincipal::on_actionAbrir_chart_triggered()
{
     QLineSeries *series = new QLineSeries();

     series->append(0, 6);
     series->append(2, 4);
     series->append(3, 8);
     series->append(7, 4);
     series->append(10, 5);
     *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);

     QChart *chart = new QChart();

     chart->addSeries(series);
     chart->createDefaultAxes();
     chart->setTitle("Simple line chart example");

     ui->graphicsViewOriginal->setFixedSize(500, 500);
     ui->graphicsViewOriginal->setSceneRect(0, 0, 500, 500);
     ui->graphicsViewOriginal->fitInView(0, 0, 500, 500, Qt::KeepAspectRatio);
     escenaOriginal->addItem(chart);
}

void VentanaPrincipal::on_actionUmbral_Escala_de_Grises_triggered()
{
    realizarUmbralEscalaGrises();
}
