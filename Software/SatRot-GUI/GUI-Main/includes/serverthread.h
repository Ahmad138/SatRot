#ifndef SERVERTHREAD_H
#define SERVERTHREAD_H

#include <QObject>
#include <QTcpSocket>
#include <QReadWriteLock>

class QJsonObject;

/**
 * @brief
 *
 */
class ServerThread : public QObject
{
    Q_OBJECT
    /**
     * @brief
     *
     * @param
     */
    Q_DISABLE_COPY(ServerThread)
public:
    /**
     * @brief
     *
     * @param parent
     */
    explicit ServerThread(QObject* parent = nullptr);
    /**
     * @brief
     *
     * @param socketDescriptor
     * @return bool
     */
    virtual bool setSocketDescriptor(qintptr socketDescriptor);
    /**
     * @brief
     *
     * @return QString
     */
    QString userName() const;
    /**
     * @brief
     *
     * @param userName
     */
    void setUserName(const QString& userName);
    /**
     * @brief
     *
     * @param json
     */
    void sendJson(const QJsonObject& json);
public slots:
    /**
     * @brief
     *
     */
    void disconnectFromClient();
private slots:
    /**
     * @brief
     *
     */
    void receiveJson();
signals:
    /**
     * @brief
     *
     * @param jsonDoc
     */
    void jsonReceived(const QJsonObject& jsonDoc);
    /**
     * @brief
     *
     */
    void disconnectedFromClient();
    /**
     * @brief
     *
     */
    void error();
    /**
     * @brief
     *
     * @param msg
     */
    void logMessage(const QString& msg);
private:
    QTcpSocket* m_serverSocket; /**< TODO: describe */
    QString m_userName; /**< TODO: describe */
    mutable QReadWriteLock m_userNameLock; /**< TODO: describe */
};


#endif // SERVERTHREAD_H
