#include "micamera.h"
#include "ui_micamera.h"

micamera::micamera(QWidget *parent) :

    QMainWindow(parent),
    ui(new Ui::micamera)
{
    ui->setupUi(this);
}

micamera::~micamera()
{
    delete ui;

}




void micamera::on_create_photo_clicked()
{
    camera1.createImageFromCamera();
    //qimage1=QImage("/home/pi/novotny/mikamera/micamera_view/micamera/foto.jpg");
  //  qimage1=QImage(const uchar *)camera1.image, camera1.image.cols, camera1.image.rows , QImage::Format_RGB888);
    //image(3,3,QImage::Format_ARGB32_Premultiplied);
    //ui->viewphoto->setPixmap(QPixmap::fromImage(Mat2QImage(camera1.image)));
    QImage qimage1= QImage((uchar*) camera1.image.data, camera1.image.cols, camera1.image.rows, camera1.image.step, QImage::Format_RGB888);

 ui->viewphoto->setPixmap(QPixmap::fromImage(qimage1).scaled(400,240,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
 //imshow("neco", camera1.image);
 }



void micamera::on_initCamera_clicked()
{
    camera1.initCamera();
}



void micamera::on_closeCamera_clicked()
{
    camera1.closeCamera();
}
