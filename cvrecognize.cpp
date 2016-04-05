#include "cvrecognize.h"

cvRecognize::cvRecognize()
{
    treshold_value=128;
}


cv::Mat cvRecognize::cvMake(cv::Mat cvImage){
     //qtImage=QImage("/home/pi/novotny/mikamera/gui_view/gui/foto.jpg");
   //  qtImage1=QImage(const uchar *)camera1.cvImage, camera1.image.cols, camera1.image.rows , QImage::Format_RGB888);
     //image(3,3,QImage::Format_ARGB32_Premultiplied);
     //ui->viewphoto->setPixmap(QPixmap::fromImage(Mat2QImage(camera1.image)));
    // vyytvoreni kopie img, 8 bitu, 1 kanal

    cv::threshold(cvImage, cvImage, treshold_value, 255.0, CV_THRESH_BINARY);
    return cvImage;


 }
void cvRecognize::setTreshold(int treshold){
    treshold_value=treshold;
}

