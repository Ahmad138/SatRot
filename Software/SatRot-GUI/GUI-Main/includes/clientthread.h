#ifndef CLIENTTHREAD_H
#define CLIENTTHREAD_H

#include "../includes/tcpclient.h"

#include <QObject>
#include <QAbstractSocket>

class ChatClient;
class QStandardItemModel;

/**
 * @brief
 *
 */
class ClientThread : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief
     *
     * @param parent
     */
    explicit ClientThread(QObject* parent = nullptr);
    /**
     * @brief
     *
     */
    ~ClientThread();

private:
    TCPClient* m_TCPClient; /**< TODO: describe */
    QStandardItemModel* m_chatModel; /**< TODO: describe */
    QString m_lastUserName; /**< TODO: describe */

private slots:
    /**
     * @brief
     *
     */
    void attemptConnection();
    /**
     * @brief
     *
     */
    void connectedToServer();
    /**
     * @brief
     *
     * @param userName
     */
    void attemptLogin(const QString& userName);
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
    void loginFailed(const QString& reason);
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
     */
    void sendMessage();
    /**
     * @brief
     *
     */
    void disconnectedFromServer();
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
    /**
     * @brief
     *
     * @param socketError
     */
    void error(QAbstractSocket::SocketError socketError);

signals:

};

#endif // CLIENTTHREAD_H
