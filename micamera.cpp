#include "micamera.h"

#include "gui.h"
#include "cvrecognize.h"


#include <iostream>
#include <fstream>
#include <unistd.h>



micamera::micamera()
{

      //  this->nCount=100;
        //set camera params
//    this->camera1.set( CV_CAP_PROP_FORMAT, CV_8UC1 );



}

cv::Mat micamera::createImageFromCamera(){

        camera1.grab();
        camera1.retrieve (cvImage);

        return cvImage;

        //camera1.release();
            //cv::imwrite("/home/pi/novotny/mikamera/micamera_view/micamera/foto.jpg",cvImage);
    }
 void micamera::initCamera(){
    camera1.set( CV_CAP_PROP_CONVERT_RGB, CV_8UC1 );
    camera1.open();

 }

 void micamera::closeCamera(){
    camera1.release();

 }




