#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPortInfo>
#include <QDebug>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_send_clicked();

    void on_openPort_clicked();

    void on_btnSend_clicked();

    void readDataSerial();
private:
    Ui::MainWindow *ui;
    void loadPort();
    QSerialPort *serialPort;
};
#endif // MAINWINDOW_H
