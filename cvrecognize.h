#ifndef CVRECOGNIZE_H
#define CVRECOGNIZE_H

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

class cvRecognize
{
public:
    int treshold_value;

    cv::Mat cvMake(cv::Mat cvImage);

    cvRecognize();
    void setTreshold(int treshold);
};

#endif // CVRECOGNIZE_H
