#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>
#include <QTcpSocket>

class QHostAddress;
class QJsonDocument;

/**
 * @brief
 *
 */
class TCPClient : public QObject
{
    Q_OBJECT
    /**
     * @brief
     *
     * @param
     */
    Q_DISABLE_COPY(TCPClient)
public:
    /**
     * @brief
     *
     * @param parent
     */
    explicit TCPClient(QObject* parent = nullptr);
public slots:
    /**
     * @brief
     *
     * @param address
     * @param port
     */
    void connectToServer(const QHostAddress& address, quint16 port);
    /**
     * @brief
     *
     * @param userName
     */
    void login(const QString& userName);
    /**
     * @brief
     *
     * @param text
     */
    void sendMessage(const QString& text);
    /**
     * @brief
     *
     */
    void disconnectFromHost();
    /**
     * @brief
     *
     * @param text
     * @param satDataType
     * @param mode
     */
    void sendTrackingDetails(QJsonObject& text, QString satDataType, bool mode = true);
private slots:
    /**
     * @brief
     *
     */
    void onReadyRead();
signals:
    /**
     * @brief
     *
     */
    void connected();
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
    void loginError(const QString& reason);
    /**
     * @brief
     *
     */
    void disconnected();
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
     * @param socketError
     */
    void error(QAbstractSocket::SocketError socketError);
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
private:
    QTcpSocket* m_clientSocket; /**< TODO: describe */
    bool m_loggedIn; /**< TODO: describe */
    /**
     * @brief
     *
     * @param doc
     */
    void jsonReceived(const QJsonObject& doc);
};

#endif // TCPCLIENT_H
