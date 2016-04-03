#ifndef RASPCAMERA_H
#define RASPCAMERA_H






#include <QCommandLineParser>
#include <QImage>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
#include <raspicam/raspicam_cv.h>

class raspcamera
{
public:
    raspcamera();
    void createImageFromCamera();
    void initCamera();
    void closeCamera();
    time_t timer_begin,timer_end;
     int nCount;
     raspicam::RaspiCam_Cv camera1;
     cv::Mat image;

};

#endif // RASPCAMERA_H
