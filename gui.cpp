#include "gui.h"
#include "ui_gui.h"


gui::gui(QWidget *parent) :

    QMainWindow(parent),
    ui(new Ui::gui)
{
    ui->setupUi(this);

    arduino_is_available = false;
    arduino_port_name = "";
    arduino = new QSerialPort;


    qDebug() << "Number of available ports: " << QSerialPortInfo::availablePorts().length();
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        qDebug() << "Has vendor ID: " << serialPortInfo.hasVendorIdentifier();
        if(serialPortInfo.hasVendorIdentifier()){
            qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier();
        }
        qDebug() << "Has Product ID: " << serialPortInfo.hasProductIdentifier();
        if(serialPortInfo.hasProductIdentifier()){
            qDebug() << "Product ID: " << serialPortInfo.productIdentifier();
        }
    }


    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){
            if(serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id){
                if(serialPortInfo.productIdentifier() == arduino_uno_product_id){
                    arduino_port_name = serialPortInfo.portName();
                    arduino_is_available = true;
                }
            }
        }
    }

    if(arduino_is_available){
        // open and configure the serialport
        arduino->setPortName(arduino_port_name);
        arduino->open(QSerialPort::WriteOnly);
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
    }else{
        // give error message if not available
        QMessageBox::warning(this, "Port error", "Couldn't find the Arduino!");
    }

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

void gui::on_pushButton_m1l_clicked()
{
    gui::sendCmd(QString("m1l").arg(value));
}

void gui::on_pushButton_m1r_clicked()
{
    gui::sendCmd(QString("m1r").arg(value));
}


void gui::sendCmd(QString command)
{
    if(arduino->isWritable()){
        arduino->write(command.toStdString().c_str());
    }else{
        qDebug() << "Couldn't write to serial!";
    }
}

