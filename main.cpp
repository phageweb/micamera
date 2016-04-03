
#include "micamera.h"
#include <QApplication>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
#include <raspicam/raspicam_cv.h>


int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    micamera w;
    w.show();


    return a.exec();


}
