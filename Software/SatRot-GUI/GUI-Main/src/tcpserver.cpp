#include "includes/tcpserver.h"
#include "includes/tcpthread.h"

#include <QRandomGenerator>

#include <stdlib.h>

//! [0]
TCPServer::TCPServer(QObject *parent)
    : QTcpServer(parent)
{
    //in.setDevice(_socket);
    in.setVersion(QDataStream::Qt_4_0);

    tcp_lines << tr("You've been leading a dog's life. Stay off the furniture.")
             << tr("You've got to think about tomorrow.")
             << tr("You will be surprised by a loud noise.")
             << tr("You will feel hungry again in another hour.")
             << tr("You might have mail.")
             << tr("You cannot kill time without injuring eternity.")
             << tr("Computers are not intelligent. They only think they are.");

    if (!_server.listen()) {
//        QMessageBox::critical(this, tr("Rotator Server"),
//                              tr("Unable to start the server: %1.")
//                                  .arg(_server.errorString()));
        qDebug()<<"Unable to start the server";

    }

    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address()) {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }
    // if we did not find one, use IPv4 localhost
    if (ipAddress.isEmpty())
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
    qDebug()<<(tr("The server is running on\n\nIP: %1\nport: %2\n\n"
                        "Run the SatRot Controller Software Client now and connect.")
                         .arg(ipAddress).arg(_server.serverPort()));

}
//! [0]

//! [1]
//void TCPServer::incomingConnection(qintptr socketDescriptor)
//{
//    //QString tcp_lines = tcp_lines.at(QRandomGenerator::global()->bounded(tcp_lines.size()));
//    QString tcp_lines = "send my name is Ahmad";

////    TCPThread *thread = new TCPThread(socketDescriptor, tcp_lines, this);
////    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
////    thread->start();
//}


void TCPServer::incomingConnection(qintptr socketDescriptor)
{
    QString fortune = tcp_lines.at(QRandomGenerator::global()->bounded(tcp_lines.size()));
    TCPThread *thread = new TCPThread(socketDescriptor, fortune, this);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}

void TCPServer::onSocketStateChanged(QAbstractSocket::SocketState socketState)
{
    if (socketState == QAbstractSocket::UnconnectedState)
    {
        QTcpSocket* sender = static_cast<QTcpSocket*>(QObject::sender());
        _sockets.removeOne(sender);
    }
}

void TCPServer::onReadyRead()
{
    QTcpSocket* sender = static_cast<QTcpSocket*>(QObject::sender());
    QByteArray datas = sender->readAll();
    for (QTcpSocket* socket : _sockets) {
        if (socket != sender)
            socket->write(QByteArray::fromStdString(sender->peerAddress().toString().toStdString() + ": " + datas.toStdString()));
    }
}
