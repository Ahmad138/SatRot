#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <iostream>
#include <QDir>

#include "includes/api.h"
#include "includes/tcpserver.h"
#include "includes/tcpclient.h"
#include "includes/testmodel.h"
#include "includes/customlistmodel.h"
#include "includes/satellitelist.h"
#include "includes/digitalclock.h"
#include "getgeolocation.h"
#include "includes/httpwindow.h"

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

/**
 * @brief
 *
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief
     *
     * @param parent
     */
    MainWindow(QWidget *parent = nullptr);
    /**
     * @brief
     *
     */
    ~MainWindow();

private slots:
    /**
     * @brief
     *
     * @param value
     */
    void on_horizontalSlider_valueChanged(int value);


    /**
     * @brief
     *
     * @param value
     */
    void on_verticalSlider_valueChanged(int value);

    /**
     * @brief
     *
     */
    void on_pushButton_clicked();
    /**
     * @brief
     *
     */
    void on_webView_loadStarted();
    /**
     * @brief
     *
     */
    void on_pushButton_2_clicked();


    /**
     * @brief
     *
     */
    void on_pushButton_3_clicked();

    /**
     * @brief
     *
     */
    void on_getSatData_clicked();

    /**
     * @brief
     *
     * @param checked
     */
    void on_checkBox_toggled(bool checked);
    /**
     * @brief
     *
     */
    void showTime();

    /**
     * @brief
     *
     */
    void webView();

    /**
     * @brief
     *
     */
    void on_pushButton_5_clicked();

    /**
     * @brief
     *
     */
    void on_pushButton_6_clicked();
    /**
     * @brief
     *
     * @param endpoint
     */
    void getCZML(QString endpoint);
    /**
     * @brief
     *
     * @param event
     */
    void resizeEvent(QResizeEvent* event);

private:
    Ui::MainWindow *ui; /**< TODO: describe */
    TCPServer server; /**< TODO: describe */
    TCPClient client; /**< TODO: describe */

    QWebEngineView *view; /**< TODO: describe */

    CustomListModel *model = new CustomListModel(this); /**< TODO: describe */
    satelliteList sl; /**< TODO: describe */

    QString startDate, stopDate, latitude, longitude, norad; /**< TODO: describe */

};
#endif // MAINWINDOW_H
