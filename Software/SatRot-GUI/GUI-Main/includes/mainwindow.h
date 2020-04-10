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
#include "includes/getgeolocation.h"
#include "includes/httpwindow.h"
#include "includes/positionmodel.h"
#include "includes/visualpassmodel.h"
#include "includes/radiopassmodel.h"
#include "includes/tlemodel.h"


// this_thread::sleep_for example
#include <iostream>       // std::cout
#include <iomanip>        // std::put_time
#include <thread>         // std::this_thread::sleep_until
#include <chrono>         // std::chrono::system_clock
#include <ctime>          // std::time_t, std::tm, std::localtime, std::mktime

#include <QMessageBox>
#include <QNetworkInterface>
#include <QWebEngineView>

/***********TCPClient***********/
#include <QAbstractSocket>
class TCPClient;
class QStandardItemModel;
/***********TCPClient***********/

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

    void getSatDetails(QList<QString> endpoint);
    void getSatPos(QString endpoint);
    void getSatVisPass(QString endpoint);
    void getSatRadPass(QString endpoint);
    void getSatTLE(QString endpoint);

    void tables();
    void updateTable();
    void clearTable();
    void setValue(QList<QString> value);
    void tableTimer();

    void toggleStartServer();
    void logMessage(const QString &msg);

    /**
     * @brief
     *
     * @param event
     */
    void resizeEvent(QResizeEvent* event);

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void clientInit();
    /***********TCPClient***********/
    void attemptConnection();
    void connectedToServer();
    void attemptLogin(const QString &userName);
    void loggedIn();
    void loginFailed(const QString &reason);
    void messageReceived(const QString &sender, const QString &text);
    void sendMessage();
    void disconnectedFromServer();
    void userJoined(const QString &username);
    void userLeft(const QString &username);
    void error(QAbstractSocket::SocketError socketError);
    /***********TCPClient***********/

private:
    Ui::MainWindow *ui; /**< TODO: describe */
    TCPServer *m_TCPServer;; /**< TODO: describe */
    TCPClient *m_TCPClient; /**< TODO: describe */

    /***********TCPClient***********/
    QStandardItemModel *m_chatModel;
    QString m_lastUserName;
    /***********TCPClient***********/

    QWebEngineView *view; /**< TODO: describe */

    CustomListModel *model = new CustomListModel(this); /**< TODO: describe */
    satelliteList sl; /**< TODO: describe */

    QString startDate, stopDate, latitude, longitude, norad; /**< TODO: describe */
    QList<QString> noradL;

    // Create models:
    PositionModel *PositionM = new PositionModel(this);
    VisualPassModel *VisualPassM = new VisualPassModel(this);
    RadioPassModel *RadioPassM = new RadioPassModel(this);
    TLEModel *TLEM = new TLEModel(this);

    QString apikey = "DGA852-94JPPA-5N2KPG-4B9Y";
    QString predictSecs = "300";
    QString alt = "0";
    QString fordays = "10";
    QString leastSecs = "300";
    QString leastEl = "40";

    QList<QString> m_value;

    //List for TLE data
    QList<QString> tm_satid;
    QList<QString> tm_satname;
    QList<QString> tm_tle;

    //List for Position data
    QList<QJsonObject> positions;

    QList<QString> tm_satidPos;
    QList<QString> tm_satnamePos;
    QList<QString> tm_satlatitude;
    QList<QString> tm_satlongitude;
    QList<QString> tm_sataltitude;
    QList<QString> tm_azimuth;
    QList<QString> tm_elevation;
    QList<QString> tm_ra;
    QList<QString> tm_dec;
    QList<QString> tm_timestamp;

    //List for Visual Pass data

    QList<QString> tm_satidVP;
    QList<QString> tm_satnameVP;
    QList<QString> tm_passescount;
    QList<QString> tm_startUTC;
    QList<QString> tm_startAz;
    QList<QString> tm_startEl;
    QList<QString> tm_maxUTC;
    QList<QString> tm_maxAz;
    QList<QString> tm_maxEl;
    QList<QString> tm_endUTC;
    QList<QString> tm_endAz;
    QList<QString> tm_endEl;
    QList<QString> tm_startAzCompass;
    QList<QString> tm_maxAzCompass;
    QList<QString> tm_endAzCompass;
    QList<QString> tm_mag;
    QList<QString> tm_duration;

    //List for Radio Pass data

    QList<QString> tm_satidR;
    QList<QString> tm_satnameR;
    QList<QString> tm_passescountR;
    QList<QString> tm_startUTCR;
    QList<QString> tm_startAzR;
    QList<QString> tm_maxUTCR;
    QList<QString> tm_maxAzR;
    QList<QString> tm_maxElR;
    QList<QString> tm_endAzR;
    QList<QString> tm_endUTCR;
    QList<QString> tm_startAzCompassR;
    QList<QString> tm_maxAzCompassR;
    QList<QString> tm_endAzCompassR;

signals:
    void valueChanged();

};
#endif // MAINWINDOW_H
