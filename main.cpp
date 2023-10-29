#include "mainwindow.h"

#include <QApplication>
#include <QSerialPort>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QSerialPort serial;
//    serial.setPortName("COM7");
//    if(serial.open(QIODevice::ReadWrite)){
//        //Now the serial port is open try to set configuration
//        if(!serial.setBaudRate(QSerialPort::Baud57600))
//            qDebug()<<serial.errorString();

//        if(!serial.setDataBits(QSerialPort::Data8))
//            qDebug()<<serial.errorString();

//        if(!serial.setParity(QSerialPort::NoParity))
//            qDebug()<<serial.errorString();

//        if(!serial.setStopBits(QSerialPort::OneStop))
//            qDebug()<<serial.errorString();

//        if(!serial.setFlowControl(QSerialPort::NoFlowControl))
//            qDebug()<<serial.errorString();

//        //If any error was returned the serial il corrctly configured

//        serial.write("M114 \n");
//        //the serial must remain opened

//        if(serial.waitForReadyRead(100)){
//            //Data was returned
//            qDebug()<<"Response: "<<serial.readAll();
//        }else{
//            //No data
//            qDebug()<<"Time out";
//        }

//        //I have finish alla operation
//        serial.close();
//    }else{
//        qDebug()<<"Serial COM7 not opened. Error: "<<serial.errorString();
//    }
//        QSerialPort *serialPort;
//        serialPort = new QSerialPort;
//        serialPort->setPortName("COM15");
//        serialPort->setBaudRate(QSerialPort::BaudRate::Baud115200);
//        serialPort->setParity(QSerialPort::Parity::NoParity);
//        serialPort->setDataBits(QSerialPort::DataBits::Data8);
//        serialPort->setStopBits(QSerialPort::OneStop);
//        serialPort->open(QIODevice::ReadWrite);
//        qDebug()<<"openning";
//        if(serialPort->isOpen()){
//            qDebug()<<"Serial COM15 opened";
//            serialPort->write("fhfgfhg");
//        }else{
//            qDebug()<<"Serial COM15 not opened";
//        }
    w.show();
    return a.exec();
}
