#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>
#include <QTcpSocket>

class QHostAddress;
class QJsonDocument;

class TCPClient : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(TCPClient)
public:
    explicit TCPClient(QObject *parent = nullptr);
public slots:
    void connectToServer(const QHostAddress &address, quint16 port);
    void login(const QString &userName);
    void sendMessage(const QString &text);
    void disconnectFromHost();
    void sendTrackingDetails(QJsonObject &text, QString satDataType, bool mode=true);
private slots:
    void onReadyRead();
signals:
    void connected();
    void loggedIn();
    void loginError(const QString &reason);
    void disconnected();
    void messageReceived(const QString &sender, const QString &text);
    void error(QAbstractSocket::SocketError socketError);
    void userJoined(const QString &username);
    void userLeft(const QString &username);
private:
    QTcpSocket *m_clientSocket;
    bool m_loggedIn;
    void jsonReceived(const QJsonObject &doc);
};

#endif // TCPCLIENT_H
