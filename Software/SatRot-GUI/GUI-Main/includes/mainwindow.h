#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <iostream>
#include <QDir>
#include <QStandardPaths>

#include "../includes/api.h"
#include "../includes/tcpserver.h"
#include "../includes/tcpclient.h"
#include "../includes/testmodel.h"
#include "../includes/customlistmodel.h"
#include "../includes/satellitelist.h"
#include "../includes/digitalclock.h"
#include "../includes/getgeolocation.h"
#include "../includes/httpwindow.h"
#include "../includes/positionmodel.h"
#include "../includes/visualpassmodel.h"
#include "../includes/radiopassmodel.h"
#include "../includes/tlemodel.h"
#include "../includes/customdialog.h"

// this_thread::sleep_for example
#include <iostream>       // std::cout
#include <iomanip>        // std::put_time
#include <thread>         // std::this_thread::sleep_until
#include <chrono>         // std::chrono::system_clock
#include <ctime>          // std::time_t, std::tm, std::localtime, std::mktime

#include <QMessageBox>
#include <QNetworkInterface>
#include <QWebEngineView>
#include <QHostInfo>

/***********TCPClient***********/
#include <QAbstractSocket>
class TCPClient;
class QStandardItemModel;
/***********TCPClient***********/

//Manual Scribble
class ManualScribble;

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

protected:
    /**
     * @brief
     *
     * @param event
     */
    void closeEvent(QCloseEvent* event) override;

public:
    /**
     * @brief
     *
     * @param parent
     */
    MainWindow(QWidget* parent = nullptr);
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
//    void on_horizontalSlider_valueChanged(int value);


//    /**
//     * @brief
//     *
//     * @param value
//     */
//    void on_verticalSlider_valueChanged(int value);

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
    /**
     * @brief
     *
     * @param endpoint
     */
    void getSatPos(QString endpoint);
    /**
     * @brief
     *
     * @param endpoint
     */
    void getSatVisPass(QString endpoint);
    /**
     * @brief
     *
     * @param endpoint
     */
    void getSatRadPass(QString endpoint);
    /**
     * @brief
     *
     * @param endpoint
     */
    void getSatTLE(QString endpoint);

    /**
     * @brief
     *
     */
    void tables();
    /**
     * @brief
     *
     */
    void updateTable();
    /**
     * @brief
     *
     */
    void clearTable();
    /**
     * @brief
     *
     * @param value
     */
    void setValue(QList<QString> value);
    /**
     * @brief
     *
     */
    void tableTimer();

    /**
     * @brief
     *
     */
    void toggleStartServer();
    /**
     * @brief
     *
     * @param msg
     */
    void logMessage(const QString& msg);

    /**
     * @brief
     *
     * @param event
     */
    void resizeEvent(QResizeEvent* event);

    void on_sat_currentIndexChanged(const QString& arg1);

    /**
     * @brief
     *
     */
    void clientInit();
    /***********TCPClient***********/
    void attemptConnection();
    void connectedToServer();
    void attemptLogin(const QString& userName);
    /**
     * @brief
     *
     */
    void loggedIn();
    /**
     * @brief
     *
     * @param reason
     */
    void loginFailed(const QString& reason);
    /**
     * @brief
     *
     * @param sender
     * @param text
     */
    void messageReceived(const QString& sender, const QString& text);
    /**
     * @brief
     *
     */
    void sendMessage();
    /**
     * @brief
     *
     */
    void disconnectedFromServer();
    /**
     * @brief
     *
     * @param username
     */
    void userJoined(const QString& username);
    /**
     * @brief
     *
     * @param username
     */
    void userLeft(const QString& username);
    /**
     * @brief
     *
     * @param socketError
     */
    void error(QAbstractSocket::SocketError socketError);
    /***********TCPClient***********/

    void on_sendTrack_clicked();

    //Manual scribble
    /**
     * @brief
     *
     */
    void open();
    /**
     * @brief
     *
     */
    void save();
    /**
     * @brief
     *
     */
    void penColor();
    /**
     * @brief
     *
     */
    void penWidth();
    /**
     * @brief
     *
     */
    void about();
    /**
     * @brief
     *
     */
    void clearRadar();

    /**
     * @brief
     *
     * @param QMap<QString
     * @param angles
     */
    void logAngles(QMap<QString, double>& angles);

    /**
     * @brief
     *
     * @param position
     */
    void on_horizontalSlider_sliderMoved(int position);

    /**
     * @brief
     *
     * @param position
     */
    void on_verticalSlider_sliderMoved(int position);

private:
    Ui::MainWindow* ui; /**< TODO: describe */
    TCPServer* m_TCPServer;; /**< TODO: describe */
    TCPClient* m_TCPClient; /**< TODO: describe */

    /***********TCPClient***********/
    QStandardItemModel* m_chatModel;
    QString m_lastUserName;
    /***********TCPClient***********/

    QWebEngineView* view; /**< TODO: describe */

    CustomListModel* model = new CustomListModel(this); /**< TODO: describe */
    satelliteList sl; /**< TODO: describe */

    QString startDate, stopDate, latitude, longitude, norad; /**< TODO: describe */
    QList<QString> noradL;

    // Create models:
    PositionModel* PositionM = new PositionModel(this); /**< TODO: describe */
    VisualPassModel* VisualPassM = new VisualPassModel(this); /**< TODO: describe */
    RadioPassModel* RadioPassM = new RadioPassModel(this); /**< TODO: describe */
    TLEModel* TLEM = new TLEModel(this); /**< TODO: describe */

    QString apikey = "DGA852-94JPPA-5N2KPG-4B9Y"; /**< TODO: describe */
    QString predictSecs = "300"; /**< TODO: describe */
    QString alt = "0"; /**< TODO: describe */
    QString fordays = "10"; /**< TODO: describe */
    QString leastSecs = "300"; /**< TODO: describe */
    QString leastEl = "40"; /**< TODO: describe */

    QList<QString> m_value; /**< TODO: describe */

    //List for TLE data
    QJsonObject satTLEDetails; /**< TODO: describe */

    QList<QString> tm_satid; /**< TODO: describe */
    QList<QString> tm_satname; /**< TODO: describe */
    QList<QString> tm_tle; /**< TODO: describe */

    //List for Position data
    QList<QJsonObject> positions; /**< TODO: describe */
    QJsonObject satPDetails; /**< TODO: describe */

    QList<QString> tm_satidPos; /**< TODO: describe */
    QList<QString> tm_satnamePos; /**< TODO: describe */
    QList<QString> tm_satlatitude; /**< TODO: describe */
    QList<QString> tm_satlongitude; /**< TODO: describe */
    QList<QString> tm_sataltitude; /**< TODO: describe */
    QList<QString> tm_azimuth; /**< TODO: describe */
    QList<QString> tm_elevation; /**< TODO: describe */
    QList<QString> tm_ra; /**< TODO: describe */
    QList<QString> tm_dec; /**< TODO: describe */
    QList<QString> tm_timestamp; /**< TODO: describe */

    //List for Visual Pass data
    QJsonObject satVPDetails; /**< TODO: describe */

    QList<QString> tm_satidVP; /**< TODO: describe */
    QList<QString> tm_satnameVP; /**< TODO: describe */
    QList<QString> tm_passescount; /**< TODO: describe */
    QList<QString> tm_startUTC; /**< TODO: describe */
    QList<QString> tm_startAz; /**< TODO: describe */
    QList<QString> tm_startEl; /**< TODO: describe */
    QList<QString> tm_maxUTC; /**< TODO: describe */
    QList<QString> tm_maxAz; /**< TODO: describe */
    QList<QString> tm_maxEl; /**< TODO: describe */
    QList<QString> tm_endUTC; /**< TODO: describe */
    QList<QString> tm_endAz; /**< TODO: describe */
    QList<QString> tm_endEl; /**< TODO: describe */
    QList<QString> tm_startAzCompass; /**< TODO: describe */
    QList<QString> tm_maxAzCompass; /**< TODO: describe */
    QList<QString> tm_endAzCompass; /**< TODO: describe */
    QList<QString> tm_mag; /**< TODO: describe */
    QList<QString> tm_duration; /**< TODO: describe */

    //List for Radio Pass data
    QJsonObject satRPDetails; /**< TODO: describe */

    QList<QString> tm_satidR; /**< TODO: describe */
    QList<QString> tm_satnameR; /**< TODO: describe */
    QList<QString> tm_passescountR; /**< TODO: describe */
    QList<QString> tm_startUTCR; /**< TODO: describe */
    QList<QString> tm_startAzR; /**< TODO: describe */
    QList<QString> tm_maxUTCR; /**< TODO: describe */
    QList<QString> tm_maxAzR; /**< TODO: describe */
    QList<QString> tm_maxElR; /**< TODO: describe */
    QList<QString> tm_endAzR; /**< TODO: describe */
    QList<QString> tm_endUTCR; /**< TODO: describe */
    QList<QString> tm_startAzCompassR; /**< TODO: describe */
    QList<QString> tm_maxAzCompassR; /**< TODO: describe */
    QList<QString> tm_endAzCompassR; /**< TODO: describe */

    QJsonObject AzEl /**< TODO: describe */
    {
        {"Az", "0"},
        {"El", "0"}
    };

    //Manual Scribble
    /**
     * @brief
     *
     */
    void createActions();
    /**
     * @brief
     *
     */
    void createMenus();
    /**
     * @brief
     *
     * @return bool
     */
    bool maybeSave();
    /**
     * @brief
     *
     * @param fileFormat
     * @return bool
     */
    bool saveFile(const QByteArray& fileFormat);
    /**
     * @brief
     *
     */
    void documentation();

    ManualScribble* MScribble; /**< TODO: describe */

    QMenu* saveAsMenu; /**< TODO: describe */
    QMenu* fileMenu; /**< TODO: describe */
    QMenu* optionMenu; /**< TODO: describe */
    QMenu* helpMenu; /**< TODO: describe */

    QAction* openAct; /**< TODO: describe */
    QList<QAction*> saveAsActs;  /**< TODO: describe */
    QAction* exitAct; /**< TODO: describe */
    QAction* penColorAct; /**< TODO: describe */
    QAction* penWidthAct; /**< TODO: describe */
    QAction* printAct; /**< TODO: describe */
    QAction* clearScreenAct; /**< TODO: describe */
    QAction* aboutAct; /**< TODO: describe */
//    QAction *aboutQtAct;
    QAction* documentationAct; /**< TODO: describe */

    QString radarFileName = ":/img/img/radar.png"; /**< TODO: describe */

    QString downloadDirectoryPath; /**< TODO: describe */
    QString m_url; /**< TODO: describe */

signals:
    /**
     * @brief
     *
     */
    void valueChanged();

};
#endif // MAINWINDOW_H
