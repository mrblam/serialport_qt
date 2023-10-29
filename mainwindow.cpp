#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSerialPort>

//QSerialPort *serialPort;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , serialPort(nullptr)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadPort();
}

MainWindow::~MainWindow()
{
    delete ui;
    if(serialPort != nullptr){
        serialPort->close();
        delete serialPort;
    }
}


void MainWindow::on_send_clicked()
{
//    serialPort->write("tt ngok ngech");
}




void MainWindow::loadPort()
{
    foreach(auto &port,QSerialPortInfo::availablePorts()){
        ui->portList->addItem( port.portName());
    }
}


void MainWindow::on_openPort_clicked()
{
    if(serialPort != nullptr){
        serialPort->close();
        delete serialPort;
    }
    serialPort = new QSerialPort;
    serialPort->setPortName(ui->portList->currentText());
    serialPort->setBaudRate(QSerialPort::BaudRate::Baud115200);
    serialPort->setParity(QSerialPort::Parity::NoParity);
    serialPort->setDataBits(QSerialPort::DataBits::Data8);
    serialPort->setStopBits(QSerialPort::OneStop);
    if(serialPort->open(QIODevice::ReadWrite)){
        QMessageBox::information(this,"Result","Port open");
        connect(serialPort,&QSerialPort::readyRead,this,&MainWindow::readDataSerial);
    } else{
        QMessageBox::critical(this,"Port Error","Unable to open port");
    }
    qDebug()<<"openning";
    if(serialPort->isOpen()){
        qDebug()<<"Serial COM15 opened";

    }else{
        qDebug()<<"Serial COM15 not opened";
    }
}


void MainWindow::on_btnSend_clicked()
{
    if(!serialPort->isOpen()){
        QMessageBox::critical(this,"Port Error","Port is not opened");
        return;
    }
    serialPort->write(ui->inMessage->text().toUtf8());
}

void MainWindow::readDataSerial()
{
    if(!serialPort->isOpen()){
        QMessageBox::critical(this,"Port Error","Port is not opened");
        return;
    }
    auto dataReceived = serialPort->readAll();
    ui->lstMessages->addItem(QString(dataReceived));
}

