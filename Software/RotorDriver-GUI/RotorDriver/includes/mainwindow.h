#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
//#include "includes/blink.h"
#include "includes/stepperdriver.h"
#include "includes/tcpserver.h"
#include "includes/tcpclient.h"
#include "includes/customdialog.h"
#include "includes/timekeeperworker.h"

#include <QMessageBox>
#include <QNetworkInterface>
#include <QHostInfo>

/***********TCPClient***********/
#include <QAbstractSocket>
class TCPClient;
class QStandardItemModel;
/***********TCPClient***********/

#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>

#include <QDateTime>
#include <QThread>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
 //   void on_pushButton_toggled(bool checked);

//    void on_pushButton_2_clicked();

//    void on_pushButton_3_clicked();
    void toggleStartServer();
    void logMessage(const QString &msg);
    void logData(const QJsonObject &doc);

    /**
     * @brief
     *
     * @param event
     */

    //void on_sat_currentIndexChanged(const QString &arg1);

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

    void setSatToTrack(const QJsonObject &doc);

private:
    Ui::MainWindow *ui;
    TCPServer *m_TCPServer; /**< TODO: describe */
    TCPClient *m_TCPClient; /**< TODO: describe */

    /***********TCPClient***********/
    QStandardItemModel *m_chatModel;
    QString m_lastUserName;
    /***********TCPClient***********/

    QString url;

    stepperDriver *AzDriver = new stepperDriver(0, 2, 3, 12, 13, 14);
    stepperDriver *ElDriver = new stepperDriver(1, 4, 5, 6, 10, 11);
};

#endif // MAINWINDOW_H
