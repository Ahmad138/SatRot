#include "../includes/serverthread.h"

#include "../includes/serverthread.h"
#include <QDataStream>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>

ServerThread::ServerThread(QObject* parent)
    : QObject(parent)
    , m_serverSocket(new QTcpSocket(this))
{
    connect(m_serverSocket, &QTcpSocket::readyRead, this, &ServerThread::receiveJson);
    connect(m_serverSocket, &QTcpSocket::disconnected, this, &ServerThread::disconnectedFromClient);
    connect(m_serverSocket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error), this, &ServerThread::error);
}


bool ServerThread::setSocketDescriptor(qintptr socketDescriptor)
{
    return m_serverSocket->setSocketDescriptor(socketDescriptor);
}

void ServerThread::sendJson(const QJsonObject& json)
{
    const QByteArray jsonData = QJsonDocument(json).toJson();
    emit logMessage("Sending to " + userName() + " - " + QString::fromUtf8(jsonData));
    QDataStream socketStream(m_serverSocket);
    socketStream.setVersion(QDataStream::Qt_5_7);
    socketStream << jsonData;
}

void ServerThread::disconnectFromClient()
{
    m_serverSocket->disconnectFromHost();
}

QString ServerThread::userName() const
{
    m_userNameLock.lockForRead();
    const QString result = m_userName;
    m_userNameLock.unlock();
    return result;
}

void ServerThread::setUserName(const QString& userName)
{
    m_userNameLock.lockForWrite();
    m_userName = userName;
    m_userNameLock.unlock();
}

void ServerThread::receiveJson()
{
    QByteArray jsonData;
    QDataStream socketStream(m_serverSocket);
    socketStream.setVersion(QDataStream::Qt_5_7);
    for (;;)
    {
        socketStream.startTransaction();
        socketStream >> jsonData;
        if (socketStream.commitTransaction())
        {
            QJsonParseError parseError;
            const QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &parseError);
            if (parseError.error == QJsonParseError::NoError)
            {
                if (jsonDoc.isObject())
                    emit jsonReceived(jsonDoc.object());
                else
                    emit logMessage("Invalid message: " + QString::fromUtf8(jsonData));
            }
            else
            {
                emit logMessage("Invalid message: " + QString::fromUtf8(jsonData));
            }
        }
        else
        {
            break;
        }
    }
}


