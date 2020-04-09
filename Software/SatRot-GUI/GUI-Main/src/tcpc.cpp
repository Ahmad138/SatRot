#include "includes/tcpc.h"

TCPc::TCPc(QObject *parent) : QObject(parent)
{
    _socket.connectToHost(QHostAddress("127.0.0.1"), 4242);
    connect(&_socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));


}

void TCPc::onReadyRead()
{
    QByteArray datas = _socket.readAll();
    qDebug() << datas;
    _socket.write(QByteArray("received!"));
}

void TCPc::send(){
    //_socket.write(QByteArray("ok, here is me sending from client !\n"));
    _socket.abort();
    _socket.connectToHost(QHostAddress("127.0.0.1"), 4242);
    msg="ok, here is me sending from client \n";
    _socket.write(QByteArray(msg));
}
