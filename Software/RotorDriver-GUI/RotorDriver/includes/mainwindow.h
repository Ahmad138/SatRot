#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "includes/blink.h"
#include "includes/stepperdriver.h"
#include "includes/tcpserver.h"
#include "includes/tcpclient.h"

#include <QMessageBox>
#include <QNetworkInterface>
#include <QHostInfo>

/***********TCPClient***********/
#include <QAbstractSocket>
class TCPClient;
class QStandardItemModel;
/***********TCPClient***********/



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
    void on_pushButton_toggled(bool checked);

//    void on_pushButton_2_clicked();

//    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    TCPServer *m_TCPServer; /**< TODO: describe */
    TCPClient *m_TCPClient; /**< TODO: describe */

    /***********TCPClient***********/
    QStandardItemModel *m_chatModel;
    QString m_lastUserName;
    /***********TCPClient***********/

};

#endif // MAINWINDOW_H
