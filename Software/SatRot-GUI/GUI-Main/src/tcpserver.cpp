#include "includes/tcpserver.h"
#include "includes/tcpthread.h"

#include <QRandomGenerator>

#include <stdlib.h>

//! [0]
TCPServer::TCPServer(QObject *parent)
    : QTcpServer(parent)
{
    tcp_lines << tr("You've been leading a dog's life. Stay off the furniture.")
             << tr("You've got to think about tomorrow.")
             << tr("You will be surprised by a loud noise.")
             << tr("You will feel hungry again in another hour.")
             << tr("You might have mail.")
             << tr("You cannot kill time without injuring eternity.")
             << tr("Computers are not intelligent. They only think they are.");
}
//! [0]

//! [1]
void TCPServer::incomingConnection(qintptr socketDescriptor)
{
    //QString tcp_lines = tcp_lines.at(QRandomGenerator::global()->bounded(tcp_lines.size()));
    QString tcp_lines = "send my name is Ahmad";

    TCPThread *thread = new TCPThread(socketDescriptor, tcp_lines, this);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}
