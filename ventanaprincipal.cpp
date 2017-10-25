#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"

#include <QImage>
#include <QFileDialog>
#include <QPixmap>
#include <QtCharts>
#include <QLineSeries>
#include <QChartView>
#include <QtMath>

VentanaPrincipal::VentanaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaPrincipal)
{
    ui->setupUi(this);
    u1 = 40;
    u2 = 140;
    nivelDeUmbral = 76;
    v.setX(0);
    v.setY(0);
    matriz.setToIdentity();
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

    crearHistogramaOriginal();
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

    crearHistogramaProcesada();
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

    crearHistogramaProcesada();
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

    crearHistogramaProcesada();
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

    crearHistogramaProcesada();
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

    crearHistogramaProcesada();
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

    crearHistogramaProcesada();
}

void VentanaPrincipal::realizarExtension()
{
    QImage imgCopia(imgOriginal->width(), imgOriginal->height(), QImage::Format_Grayscale8);
    for (int c = 0; c < imgCopia.width(); c++){
        for (int f = 0; f < imgCopia.height(); f++){
             QColor pixel = imgOriginal->pixelColor(c,f);
             auto nivelDeColor = pixel.value();
             if ( nivelDeColor > u1 && nivelDeColor < u2){
                 imgCopia.setPixelColor(c,f, ( (nivelDeColor-u1)*(255/(u2-u1)) ));
             } else {
                 imgCopia.setPixelColor(c,f, QColor(255,255,255));
             }
        }
    }
    *imgProcesada = imgCopia;
    escenaProcesada->addPixmap(QPixmap::fromImage(*imgProcesada));

    crearHistogramaProcesada();
}

void VentanaPrincipal::realizarTraslacion()
{
    int a = 50;
    int b = 100;
    matriz(2,0) = b;
    matriz(2,1) = a;

    QImage imgCopia(imgOriginal->width()+a, imgOriginal->height()+b, QImage::Format_Grayscale8);
    for (int c = 0; c < imgOriginal->width(); c++){
        for (int f = 0; f < imgOriginal->height(); f++){
            //Primer paso
             v.setX(c);
             v.setY(f);
             //Aplciar Traslacion
//             vR[0] = ( (matriz(0,0) * v.x()) + (matriz(1,0) * v.x()) + (matriz(2,0) * v.x()) );
//             vR[1] = ( (matriz(0,1) * v.y()) + (matriz(1,1) * v.y()) + (matriz(2,1) * v.y()) );
             //Obtener nuevas coordenadas
              QColor pixel = imgOriginal->pixelColor(c,f);
              //Aplicar a la nueva imagen
             imgCopia.setPixelColor(c + a, f + b,pixel);
        }
    }
    *imgProcesada = imgCopia;
    escenaProcesada->addPixmap(QPixmap::fromImage(*imgProcesada));
}

void VentanaPrincipal::realizarRotacion()
{
    int angulo = 45;

    QImage imgCopia(imgOriginal->width(), imgOriginal->height(), QImage::Format_Grayscale8);
    for (int c = 0; c < imgOriginal->width(); c++){
        for (int f = 0; f < imgOriginal->height(); f++){
             v.setX(c);
             v.setY(f);
             QColor pixel = imgOriginal->pixelColor(c,f);
             double x = ( (qCos(45) * v.x()) + ((qSin(45) * v.y())) );
             double y = ( (qSin(45) * v.x()) - ((qCos(45) * v.y())) );
             imgCopia.setPixelColor(x,y,pixel);
        }
    }
    *imgProcesada = imgCopia;
    escenaProcesada->addPixmap(QPixmap::fromImage(*imgProcesada));
}

void VentanaPrincipal::realizarEscalamiento()
{
    QImage imgCopia(imgOriginal->width(), imgOriginal->height(), QImage::Format_Grayscale8);
    for (int c = 0; c < imgOriginal->width(); c++){
        for (int f = 0; f < imgOriginal->height(); f++){
             v.setX(c);
             v.setY(f);
             QColor pixel = imgOriginal->pixelColor(c,f);
             int x = 2;
             int y = ( (qSin(45) * v.x()) - ((qCos(45) * v.y())) );
             imgCopia.setPixelColor(x,y,pixel);
        }
    }
    *imgProcesada = imgCopia;
    escenaProcesada->addPixmap(QPixmap::fromImage(*imgProcesada));
}

void VentanaPrincipal::realizarInversoNegativoColor()
{
    QImage imgCopia(imgOriginal->width(), imgOriginal->height(), QImage::Format_RGB32);
    for (int c = 0; c < imgOriginal->width(); c++){
        for (int f = 0; f < imgOriginal->height(); f++){
             QColor pixel = imgOriginal->pixelColor(c,f);
             imgCopia.setPixelColor(c,f,QColor(255 - pixel.red(),255 - pixel.green(),255 - pixel.blue()));
        }
    }
    *imgProcesada = imgCopia;
    escenaProcesada->addPixmap(QPixmap::fromImage(*imgProcesada));

    crearHistogramaProcesada();
}

void VentanaPrincipal::realizarTraslacionColor()
{
    int a = 50;
    int b = 100;
    matriz(2,0) = b;
    matriz(2,1) = a;

    QImage imgCopia(imgOriginal->width()+a, imgOriginal->height()+b, QImage::Format_RGB32);
    for (int c = 0; c < imgOriginal->width(); c++){
        for (int f = 0; f < imgOriginal->height(); f++){
            //Primer paso
             v.setX(c);
             v.setY(f);
             //Aplciar Traslacion
//             vR[0] = ( (matriz(0,0) * v.x()) + (matriz(1,0) * v.x()) + (matriz(2,0) * v.x()) );
//             vR[1] = ( (matriz(0,1) * v.y()) + (matriz(1,1) * v.y()) + (matriz(2,1) * v.y()) );
             //Obtener nuevas coordenadas
              QColor pixel = imgOriginal->pixelColor(c,f);
              //Aplicar a la nueva imagen
             imgCopia.setPixelColor(c + a, f + b,pixel);
        }
    }
    *imgProcesada = imgCopia;
    escenaProcesada->addPixmap(QPixmap::fromImage(*imgProcesada));
}

void VentanaPrincipal::crearHistogramaOriginal()
{
    QLineSeries *series = new QLineSeries();
    QChart *chart = new QChart();

    for (int i = 0; i < imgOriginal->width(); i++){
        for (int j = 0; j <imgOriginal->height(); j++){
            QColor pixel = imgOriginal->pixelColor(i,j);
            auto valorPixel = pixel.value();
            QPoint coordenadaPixel(i, valorPixel);
            series->append(coordenadaPixel);
        }
    }

    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("Histograma");
    chart->legend()->hide();
    QChartView *chartView = new QChartView(chart,this);
    ui->layOutOriginal->addWidget(chartView);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->show();
}

void VentanaPrincipal::crearHistogramaProcesada()
{

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
    QBarSet *set0 = new QBarSet("1");

    for (int c = 0; c < imgOriginal->width(); c++){
        for (int f = 0; f < imgOriginal->height(); f++){
             QColor pixel = imgOriginal->pixelColor(c,f);
             auto nivelDeColor = pixel.value();
             *set0 << nivelDeColor;
        }
    }

    QBarSeries *series = new QBarSeries();
    series->append(set0);


    QChart *chart = new QChart();
    chart->setAnimationDuration(0);
    chart->addSeries(series);
    chart->setTitle("Histograma");

    //QStringList categories;
    //categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
    //axis->append(categories);
    chart->createDefaultAxes();
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignCenter);
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->layOutOriginal->addWidget(chartView);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->show();
}

void VentanaPrincipal::on_actionUmbral_Escala_de_Grises_triggered()
{
    realizarUmbralEscalaGrises();
}

void VentanaPrincipal::on_actionExtension_triggered()
{
    realizarExtension();
}

void VentanaPrincipal::on_actionTranslacion_triggered()
{
    realizarTraslacion();
}

void VentanaPrincipal::on_actionRotacion_triggered()
{
    realizarRotacion();
}

void VentanaPrincipal::on_actionNegativo_a_Imagen_a_Color_triggered()
{
    realizarInversoNegativoColor();
}

void VentanaPrincipal::on_actionAbrir_Imagen_a_Color_triggered()
{
    QString archivo = QFileDialog::getOpenFileName(this,
        tr("Abrir"), "", tr("Archivos de Imagen (*.png *.jpg *.bmp)"));
    QImage img(archivo);
    *imgOriginal = img;
    escenaOriginal->addPixmap(QPixmap::fromImage(*imgOriginal));
}

void VentanaPrincipal::on_actionTraslacion_Color_triggered()
{
    realizarTraslacionColor();
}
