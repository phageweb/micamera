#ifndef GUI_H
#define GUI_H

#include "gui.h"
#include "micamera.h"
#include "cvrecognize.h"

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <QMainWindow>
#include <QImage>
#include <QPainter>
#include <QTimer>
#include <QThread>
#include <qthread.h>
#include <iostream>
#include <raspicam/raspicam_cv.h>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QtWidgets>

namespace Ui {
class gui;
}

class gui : public QMainWindow
{
    Q_OBJECT

public:

    explicit gui(QWidget *parent = 0);
    ~gui();


    micamera micamera1;
    cvRecognize cvrecognize1;

private slots:
    void on_create_photo_clicked();

    void on_initCamera_clicked();

    void on_closeCamera_clicked();

    void on_transformImage_clicked();


    void viewImage(cv::Mat cvImage);



    void on_pushButton_clicked();

    void on_pushButton_m1l_clicked();

    void sendCmd;
private:
    Ui::gui *ui;

    QSerialPort *arduino;
    static const quint16 arduino_uno_vendor_id = 9025;
    static const quint16 arduino_uno_product_id = 67;
    QString arduino_port_name;
    bool arduino_is_available;
};



#endif // GUI_H



