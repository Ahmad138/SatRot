#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>
#include <QVector>

class QThread;
class ServerThread;
class QJsonObject;

class TCPServer : public QTcpServer
{
    Q_OBJECT
    Q_DISABLE_COPY(TCPServer)
public:
    explicit TCPServer(QObject *parent = nullptr);
    ~TCPServer();
protected:
    void incomingConnection(qintptr socketDescriptor) override;
private:
    const int m_idealThreadCount;
    QVector<QThread *> m_availableThreads;
    QVector<int> m_threadsLoad;
    QVector<ServerThread *> m_clients;
private slots:
    void broadcast(const QJsonObject &message, ServerThread *exclude);
    void jsonReceived(ServerThread *sender, const QJsonObject &doc);
    void userDisconnected(ServerThread *sender, int threadIdx);
    void userError(ServerThread *sender);
public slots:
    void stopServer();
private:
    void jsonFromLoggedOut(ServerThread *sender, const QJsonObject &doc);
    void jsonFromLoggedIn(ServerThread *sender, const QJsonObject &doc);
    void sendJson(ServerThread *destination, const QJsonObject &message);
signals:
    void logMessage(const QString &msg);
    void stopAllClients();
};

#endif // TCPSERVER_H
