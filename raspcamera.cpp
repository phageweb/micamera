#include "raspcamera.h"
#include <iostream>
#include <fstream>
#include <unistd.h>



raspcamera::raspcamera()
{

      //  this->nCount=100;
        //set camera params
//    this->camera1.set( CV_CAP_PROP_FORMAT, CV_8UC1 );



}

void raspcamera::createImageFromCamera(){

        camera1.grab();
        camera1.retrieve ( image);
        //camera1.release();
            //cv::imwrite("/home/pi/novotny/mikamera/micamera_view/micamera/foto.jpg",image);
    }
 void raspcamera::initCamera(){
    camera1.set( CV_CAP_PROP_CONVERT_RGB, CV_8UC1 );
    camera1.open();

 }
 void raspcamera::closeCamera(){
    camera1.release();

 }




