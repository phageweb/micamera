#ifndef MICAMERA_H
#define MICAMERA_H


#include <QCommandLineParser>
#include <QImage>
#include <QMainWindow>
#include <QImage>
#include <QPainter>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
#include <raspicam/raspicam_cv.h>

class micamera
{
public:

    cv::Mat cvImage;
    raspicam::RaspiCam_Cv camera1;


    micamera();
    void initCamera();
    void closeCamera();
    cv::Mat createImageFromCamera();
   // cv::Mat  tranformImage(cv::Mat cvImage);








};

#endif // MICAMERA_H
