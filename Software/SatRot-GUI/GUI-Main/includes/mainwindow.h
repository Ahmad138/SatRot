#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <iostream>
#include <QDir>
#include <QStandardPaths>
#include <QTime>
#include <QTimer>
#include <QAbstractSocket>
#include <iomanip>
#include <thread>
#include <chrono>
#include <ctime>
#include <QMessageBox>
#include <QNetworkInterface>
#include <QWebEngineView>
#include <QHostInfo>

#include "../includes/api.h"
#include "../includes/tcpserver.h"
#include "../includes/tcpclient.h"
#include "../includes/customlistmodel.h"
#include "../includes/satellitelist.h"
#include "../includes/getgeolocation.h"
#include "../includes/httpwindow.h"
#include "../includes/positionmodel.h"
#include "../includes/visualpassmodel.h"
#include "../includes/radiopassmodel.h"
#include "../includes/tlemodel.h"
#include "../includes/customdialog.h"

/***********TCPClient***********/
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
 *This is the main gui class that handles everything about the gui. It brings all the other classes together into
 * a unified program.
 *
 * @authors -> Ahmad Muhammad (https://github.com/Ahmad138)
 * @authors -> Mohamed Salih
 * @authors -> Mohamed Salim
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

protected:
    /**
     * @brief
     *This listens to the close event and overrides.
     * @param event -> takes in the QCloseEvent from the main GUI
     */
    void closeEvent(QCloseEvent* event) override;

public:
    /**
     * @brief
     *This is the main constructor of the class. This is where most of the ui and widgets are initiated
     * @param parent -> take in a nullptr as default
     */
    MainWindow(QWidget* parent = nullptr);

    /**
     * @brief
     *destructor for the main window
     */
    ~MainWindow();

private slots:
    /**
     * @brief
     *This method fetches the satellite information from the czml file download, to the positions, visual
     * and radio passes and tle
     */
    void on_getSatData_clicked();

    /**
     * @brief
     *When checked, this sets the datetime to the current datetime
     * @param checked -> state of the check button
     */
    void on_checkBox_toggled(bool checked);

    /**
     * @brief
     *Sets the current date time, formats it and displays it
     */
    void showTime();

    /**
     * @brief
     *Runs the webview and loads the html file to display the map
     */
    void webView();

    /**
     * @brief
     *This method gets the device location information based on the long and lat of the device.
     * It gets the information by sending an api request to a ipgeolocation services
     */
    void on_pushButton_5_clicked();

    /**
     * @brief
     *This method first gets the ip of the system using an api request,
     * then using that ip, constructs another end point for an api request to obtain the
     * Long and Lat of the user.
     */
    void on_pushButton_6_clicked();

    /**
     * @brief
     *This method downloads the required file from the http server api service of orbitalpredictor.
     * @param endpoint -> parameter is the api service endpoint to retrieve the file from
     */
    void getCZML(QString endpoint);

    /**
     * @brief
     *This method makes the api call to n2yo to get satellite details such as position,
     * visaul pass, radio pass and tle for each of the satellites
     * @param endpoint -> receives the endpoint list
     */
    void getSatDetails(QList<QString> endpoint);

    /**
     * @brief
     *This method gets the satellite position by calling the api to n2yo using the endpoint
     * @param endpoint -> api endpoint for the request to be made
     */
    void getSatPos(QString endpoint);

    /**
     * @brief
     *This method gets the satellite Visual Pass by calling the api to n2yo using the endpoint
     * @param endpoint -> api endpoint for the request to be made
     */
    void getSatVisPass(QString endpoint);

    /**
     * @brief
     *This method gets the satellite Radio Pass by calling the api to n2yo using the endpoint
     * @param endpoint -> api endpoint for the request to be made
     */
    void getSatRadPass(QString endpoint);

    /**
     * @brief
     *This method gets the satellite TLE by calling the api to n2yo using the endpoint
     * @param endpoint -> api endpoint for the request to be made
     */
    void getSatTLE(QString endpoint);

    /**
     * @brief
     *Creates the table view to display the data for each of the satellite detail. it passes
     * the models to the tableview.
     */
    void tables();

    /**
     * @brief
     *Updates and refreshes the table data and view
     */
    void updateTable();

    /**
     * @brief
     *clears the table data and view
     */
    void clearTable();

    /**
     * @brief
     *sets value to a changed table position
     * @param value -> the changed value
     */
    void setValue(QList<QString> value);

    /**
     * @brief
     *This is a timer for the table to get updated regularly
     */
    void tableTimer();

    /**
     * @brief
     *Toggles the server to start or stop depending the current configuration
     */
    void toggleStartServer();

    /**
     * @brief
     *logs the received data from the socket connection
     * @param msg -> the received information from the emitted signal
     */
    void logMessage(const QString& msg);

    /**
     * @brief
     *This is the qt resize event called to readjust the webview widget based on the change of the window size
     * @param event -> event from the event manager
     */
    void resizeEvent(QResizeEvent* event) Q_DECL_OVERRIDE;

    /**
     * @brief
     *Listens to the change on the combo box selection and updates the selected value
     * @param arg1 -> the index of the selected option
     */
    void on_sat_currentIndexChanged(const QString& arg1);

    /**
     * @brief
     *Tries to make a socket connection to the specified ip and port
     */
    void attemptConnection();

    /**
     * @brief
     *This is executed when there is a successful socket connection
     */
    void connectedToServer();

    /**
     * @brief
     *This logs a user in with the specified name
     *
     * @param userName -> gets the username or device name to be added
     */
    void attemptLogin(const QString& userName);

    /**
     * @brief
     *once we successully log in we enable the ui to display and send messages
     */
    void loggedIn();

    /**
     * @brief
     *the server rejected the login attempt. display the reason for the rejection in a message box
     * @param reason
     */
    void loginFailed(const QString& reason);

    /**
     * @brief
     *Once a message is received, we get the name of the person that sends it and the message itself
     * @param sender -> the sender of the message
     * @param text -> the message itself
     */
    void messageReceived(const QString& sender, const QString& text);

    /**
     * @brief
     *This is the method that handles the sending of the message itself.
     * we use the client to send the message that the user typed
     */
    void sendMessage();

    /**
     * @brief
     *if the client loses connection to the server
     *comunicate the event to the user via a message box
     */
    void disconnectedFromServer();

    /**
     * @brief
     *Alerts the network of a new user joining in with the name
     * @param username -> the new user or device that just joined the network
     */
    void userJoined(const QString& username);

    /**
     * @brief
     *Alerts the network for when a user leaves with the name
     * @param username -> the user or device that just left the network
     */
    void userLeft(const QString& username);

    /**
     * @brief
     *This handles the error of the socket connection
     * @param socketError -> the error received
     */
    void error(QAbstractSocket::SocketError socketError);

    /**
     * @brief
     *Sends the information of the satellite to be tracked automatically
     */
    void on_sendTrack_clicked();

    /**
     * @brief
     *This is part of the menu items to open files
     */
    void open();

    /**
     * @brief
     *This is part of the menu items to save file
     */
    void save();

    /**
     * @brief
     *This is part of the menu items to change the color of the tracking pen
     */
    void penColor();

    /**
     * @brief
     *This is part of the menu items to change the with/thickness of the pen
     */
    void penWidth();

    /**
     * @brief
     *This is part of the menu items that talks about satrot itself
     */
    void about();

    /**
     * @brief
     *This helps clears the radar so you can have clean screen
     */
    void clearRadar();

    /**
     * @brief
     *This is a slot method that helps get the logged angles
     * @param QMap<QString -> mapping values
     * @param angles -> the Az and El angles calculated based on the mouse positions
     */
    void logAngles(QMap<QString, double>& angles);

    /**
     * @brief
     *This is event driven slider that gets the position of the Azimuth angle
     * @param position -> returned value of Az position on event change
     */
    void on_horizontalSlider_sliderMoved(int position);

    /**
     * @brief
     *This is event driven slider that gets the position of the Elevation angle
     * @param position -> returned value of El position on event change
     */
    void on_verticalSlider_sliderMoved(int position);

private:
    Ui::MainWindow* ui; /**< TODO: describe */
    TCPServer* m_TCPServer;; /**< TODO: describe */
    TCPClient* m_TCPClient; /**< TODO: describe */

    /***********TCPClient***********/
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
    QAction* documentationAct; /**< TODO: describe */

    QString radarFileName = ":/img/img/radar.png"; /**< TODO: describe */

    QString downloadDirectoryPath; /**< TODO: describe */
    QString m_url; /**< TODO: describe */


    /**
     * @brief
     *This creates the actions in the menu for the application on top
     */
    void createActions();

    /**
     * @brief
     *This is the method that handles the menu creation
     */
    void createMenus();

    /**
     * @brief
     *This is for the dialog that promps the user if they want to save their map
     * @return bool -> true saves the map and false discards it
     */
    bool maybeSave();

    /**
     * @brief
     *This is the method that actively save the map
     * @param fileFormat -> selected file format they want to save it to
     * @return bool -> true successfully saves it and false failed
     */
    bool saveFile(const QByteArray& fileFormat);

    /**
     * @brief
     *This is the menu item that displays the documentation of the application
     */
    void documentation();

signals:
    /**
     * @brief
     *signal that is emitted when there is a value cahnge to the table items
     */
    void valueChanged();

};
#endif // MAINWINDOW_H
