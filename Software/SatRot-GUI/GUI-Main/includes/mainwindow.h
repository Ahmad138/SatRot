#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <iostream>

#include "includes/api.h"
#include "includes/tcpserver.h"
#include "includes/tcpclient.h"
#include "includes/testmodel.h"
#include "includes/customlistmodel.h"
#include "includes/satellitelist.h"

// this_thread::sleep_for example
#include <iostream>       // std::cout
#include <iomanip>        // std::put_time
#include <thread>         // std::this_thread::sleep_until
#include <chrono>         // std::chrono::system_clock
#include <ctime>          // std::time_t, std::tm, std::localtime, std::mktime

#include <QMessageBox>
#include <QNetworkInterface>
#include <QWebEngineView>

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

    void on_getSatData_clicked();

private:
    Ui::MainWindow *ui;
    TCPServer server;
    TCPClient client;

    CustomListModel *model = new CustomListModel(this);
    satelliteList sl;
};
#endif // MAINWINDOW_H
