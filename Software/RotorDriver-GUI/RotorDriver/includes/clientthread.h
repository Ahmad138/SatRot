#ifndef CLIENTTHREAD_H
#define CLIENTTHREAD_H

#include "includes/tcpclient.h"

#include <QObject>
#include <QAbstractSocket>

class ChatClient;
class QStandardItemModel;

class ClientThread : public QObject
{
    Q_OBJECT
public:
    explicit ClientThread(QObject *parent = nullptr);
    ~ClientThread();

private:
    TCPClient *m_TCPClient;
    QStandardItemModel *m_chatModel;
    QString m_lastUserName;

private slots:
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

signals:

};

#endif // CLIENTTHREAD_H
