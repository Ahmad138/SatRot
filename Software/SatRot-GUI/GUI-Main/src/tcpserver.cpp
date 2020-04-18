#include "../includes/tcpserver.h"
#include "../includes/serverthread.h"

#include <QThread>
#include <functional>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QTimer>

TCPServer::TCPServer(QObject* parent)
    : QTcpServer(parent)
    , m_idealThreadCount(qMax(QThread::idealThreadCount(), 1))
{
    m_availableThreads.reserve(m_idealThreadCount);
    m_threadsLoad.reserve(m_idealThreadCount);
}

TCPServer::~TCPServer()
{
    for (QThread* singleThread : m_availableThreads)
    {
        singleThread->quit();
        singleThread->wait();
    }
}
void TCPServer::incomingConnection(qintptr socketDescriptor)
{
    ServerThread* worker = new ServerThread;
    if (!worker->setSocketDescriptor(socketDescriptor))
    {
        worker->deleteLater();
        return;
    }
    int threadIdx = m_availableThreads.size();
    if (threadIdx < m_idealThreadCount)   //we can add a new thread
    {
        m_availableThreads.append(new QThread(this));
        m_threadsLoad.append(1);
        m_availableThreads.last()->start();
    }
    else
    {
        // find the thread with the least amount of clients and use it
        threadIdx = std::distance(m_threadsLoad.cbegin(), std::min_element(m_threadsLoad.cbegin(), m_threadsLoad.cend()));
        ++m_threadsLoad[threadIdx];
    }
    worker->moveToThread(m_availableThreads.at(threadIdx));
    connect(m_availableThreads.at(threadIdx), &QThread::finished, worker, &QObject::deleteLater);
    connect(worker, &ServerThread::disconnectedFromClient, this, std::bind(&TCPServer::userDisconnected, this, worker, threadIdx));
    connect(worker, &ServerThread::error, this, std::bind(&TCPServer::userError, this, worker));
    connect(worker, &ServerThread::jsonReceived, this, std::bind(&TCPServer::jsonReceived, this, worker, std::placeholders::_1));
    connect(this, &TCPServer::stopAllClients, worker, &ServerThread::disconnectFromClient);
    m_clients.append(worker);
    emit logMessage("New client Connected");
}
void TCPServer::sendJson(ServerThread* destination, const QJsonObject& message)
{
    Q_ASSERT(destination);
    QTimer::singleShot(0, destination, std::bind(&ServerThread::sendJson, destination, message));
}
void TCPServer::broadcast(const QJsonObject& message, ServerThread* exclude)
{
    for (ServerThread* worker : m_clients)
    {
        Q_ASSERT(worker);
        if (worker == exclude)
            continue;
        sendJson(worker, message);
    }
}

void TCPServer::jsonReceived(ServerThread* sender, const QJsonObject& json)
{
    Q_ASSERT(sender);
    emit logMessage("JSON received " + QString::fromUtf8(QJsonDocument(json).toJson()));
    if (sender->userName().isEmpty())
        return jsonFromLoggedOut(sender, json);
    jsonFromLoggedIn(sender, json);
}

void TCPServer::userDisconnected(ServerThread* sender, int threadIdx)
{
    --m_threadsLoad[threadIdx];
    m_clients.removeAll(sender);
    const QString userName = sender->userName();
    if (!userName.isEmpty())
    {
        QJsonObject disconnectedMessage;
        disconnectedMessage["type"] = QStringLiteral("userdisconnected");
        disconnectedMessage["username"] = userName;
        broadcast(disconnectedMessage, nullptr);
        emit logMessage(userName + " disconnected");
    }
    sender->deleteLater();
}

void TCPServer::userError(ServerThread* sender)
{
    Q_UNUSED(sender)
    emit logMessage("Error from " + sender->userName());
}

void TCPServer::stopServer()
{
    emit stopAllClients();
    close();
}

void TCPServer::jsonFromLoggedOut(ServerThread* sender, const QJsonObject& docObj)
{
    Q_ASSERT(sender);
    const QJsonValue typeVal = docObj.value(QLatin1String("type"));
    if (typeVal.isNull() || !typeVal.isString())
        return;
    if (typeVal.toString().compare(QLatin1String("login"), Qt::CaseInsensitive) != 0)
        return;
    const QJsonValue usernameVal = docObj.value(QLatin1String("username"));
    if (usernameVal.isNull() || !usernameVal.isString())
        return;
    const QString newUserName = usernameVal.toString().simplified();
    if (newUserName.isEmpty())
        return;
    for (ServerThread* worker : qAsConst(m_clients))
    {
        if (worker == sender)
            continue;
        if (worker->userName().compare(newUserName, Qt::CaseInsensitive) == 0)
        {
            QJsonObject message;
            message["type"] = QStringLiteral("login");
            message["success"] = false;
            message["reason"] = QStringLiteral("duplicate username");
            sendJson(sender, message);
            return;
        }
    }
    sender->setUserName(newUserName);
    QJsonObject successMessage;
    successMessage["type"] = QStringLiteral("login");
    successMessage["success"] = true;
    sendJson(sender, successMessage);
    QJsonObject connectedMessage;
    connectedMessage["type"] = QStringLiteral("newuser");
    connectedMessage["username"] = newUserName;
    broadcast(connectedMessage, sender);
}

void TCPServer::jsonFromLoggedIn(ServerThread* sender, const QJsonObject& docObj)
{
    Q_ASSERT(sender);
    const QJsonValue typeVal = docObj.value(QLatin1String("type"));
    if (typeVal.isNull() || !typeVal.isString())
        return;
    if (typeVal.toString().compare(QLatin1String("message"), Qt::CaseInsensitive) != 0)
        return;
    const QJsonValue textVal = docObj.value(QLatin1String("text"));
    if (textVal.isNull() || !textVal.isString())
        return;
    const QString text = textVal.toString().trimmed();
    if (text.isEmpty())
        return;
    QJsonObject message;
    message["type"] = QStringLiteral("message");
    message["text"] = text;
    message["sender"] = sender->userName();
    broadcast(message, sender);
}



