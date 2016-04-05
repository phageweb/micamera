#include "gui.h"
#include "ui_gui.h"


gui::gui(QWidget *parent) :

    QMainWindow(parent),
    ui(new Ui::gui)
{
    ui->setupUi(this);



}


gui::~gui()
{
    delete ui;

}

void gui::on_create_photo_clicked()
{

    viewImage(micamera1.createImageFromCamera());


 }



void gui::on_initCamera_clicked()
{
    micamera1.initCamera();
}



void gui::on_closeCamera_clicked()
{
    micamera1.closeCamera();
}

void gui::on_transformImage_clicked()
{
   cvrecognize1.setTreshold(ui->spinBox_treshold->value());
   viewImage(cvrecognize1.cvMake(micamera1.createImageFromCamera()));

}
void gui::viewImage(cv::Mat cvImage){
    QImage qtImage = QImage((uchar*) cvImage.data, cvImage.cols, cvImage.rows, cvImage.step, QImage::Format_RGB888);
    ui->viewImage->setPixmap(QPixmap::fromImage(qtImage).scaled(400,240,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
}




