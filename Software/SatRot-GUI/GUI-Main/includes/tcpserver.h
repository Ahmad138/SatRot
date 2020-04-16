#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>
#include <QVector>

class QThread;
class ServerThread;
class QJsonObject;

/**
 * @brief
 *
 */
class TCPServer : public QTcpServer
{
    Q_OBJECT
    /**
     * @brief
     *
     * @param
     */
    Q_DISABLE_COPY(TCPServer)
public:
    /**
     * @brief
     *
     * @param parent
     */
    explicit TCPServer(QObject* parent = nullptr);
    /**
     * @brief
     *
     */
    ~TCPServer();
protected:
    /**
     * @brief
     *
     * @param socketDescriptor
     */
    void incomingConnection(qintptr socketDescriptor) override;
private:
    const int m_idealThreadCount; /**< TODO: describe */
    QVector<QThread*> m_availableThreads;  /**< TODO: describe */
    QVector<int> m_threadsLoad; /**< TODO: describe */
    QVector<ServerThread*> m_clients;  /**< TODO: describe */
private slots:
    /**
     * @brief
     *
     * @param message
     * @param exclude
     */
    void broadcast(const QJsonObject& message, ServerThread* exclude);
    /**
     * @brief
     *
     * @param sender
     * @param doc
     */
    void jsonReceived(ServerThread* sender, const QJsonObject& doc);
    /**
     * @brief
     *
     * @param sender
     * @param threadIdx
     */
    void userDisconnected(ServerThread* sender, int threadIdx);
    /**
     * @brief
     *
     * @param sender
     */
    void userError(ServerThread* sender);
public slots:
    /**
     * @brief
     *
     */
    void stopServer();
private:
    /**
     * @brief
     *
     * @param sender
     * @param doc
     */
    void jsonFromLoggedOut(ServerThread* sender, const QJsonObject& doc);
    /**
     * @brief
     *
     * @param sender
     * @param doc
     */
    void jsonFromLoggedIn(ServerThread* sender, const QJsonObject& doc);
    /**
     * @brief
     *
     * @param destination
     * @param message
     */
    void sendJson(ServerThread* destination, const QJsonObject& message);
signals:
    /**
     * @brief
     *
     * @param msg
     */
    void logMessage(const QString& msg);
    /**
     * @brief
     *
     */
    void stopAllClients();
};

#endif // TCPSERVER_H
