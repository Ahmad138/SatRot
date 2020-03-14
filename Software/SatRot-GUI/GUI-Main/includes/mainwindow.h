#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <iostream>

#include "includes/api.h"
#include "includes/webappview.h"
//#include "includes/tcpsocketsserver.h"
//#include "includes/tcpsocketsclient.h"
#include "includes/tcpserver.h"

// this_thread::sleep_for example
#include <iostream>       // std::cout
#include <iomanip>        // std::put_time
#include <thread>         // std::this_thread::sleep_until
#include <chrono>         // std::chrono::system_clock
#include <ctime>          // std::time_t, std::tm, std::localtime, std::mktime

#include <QMessageBox>
#include <QNetworkInterface>

using namespace std;

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
    void on_horizontalSlider_valueChanged(int value);


    void on_verticalSlider_valueChanged(int value);

    void on_pushButton_clicked();



    void on_webView_loadStarted();
    void on_pushButton_2_clicked();


    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    TCPServer server;
};
#endif // MAINWINDOW_H
