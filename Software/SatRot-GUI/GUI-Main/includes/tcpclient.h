#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QDataStream>
#include <QDialog>
#include <QTcpSocket>
#include <QtWidgets>
#include <QtNetwork>

QT_BEGIN_NAMESPACE
class QComboBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QTcpSocket;
class QNetworkSession;
QT_END_NAMESPACE

//! [0]
class TCPClient : public QDialog
{
    Q_OBJECT

public:
    explicit TCPClient(QWidget *parent = nullptr);

private slots:
    void requestNewFortune();
    void readFortune();
    void displayError(QAbstractSocket::SocketError socketError);
    void enableGetFortuneButton();
    void sessionOpened();

private:
    QComboBox *hostCombo = nullptr;
    QLineEdit *portLineEdit = nullptr;
    QLabel *statusLabel = nullptr;
    QPushButton *getFortuneButton = nullptr;

    QTcpSocket *tcpSocket = nullptr;
    QDataStream in;
    QString currentFortune;

    QNetworkSession *networkSession = nullptr;
};
//! [0]
//!
#endif // TCPCLIENT_H
