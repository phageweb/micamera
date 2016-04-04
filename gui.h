#ifndef MICAMERA_H
#define MICAMERA_H


#include "raspcamera.h"
#include "micamera.h"
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <QMainWindow>
#include <QImage>
#include <QPainter>
#include <iostream>
#include <raspicam/raspicam_cv.h>
namespace Ui {
class micamera;
}

class micamera : public QMainWindow
{
    Q_OBJECT

public:
    explicit micamera(QWidget *parent = 0);
    ~micamera();
    raspcamera camera1;
    QImage Mat2QImage(cv::Mat const& src);

private slots:
    void on_create_photo_clicked();

    void on_initCamera_clicked();

    void on_closeCamera_clicked();

private:
    Ui::micamera *ui;
};

#endif // MICAMERA_H
