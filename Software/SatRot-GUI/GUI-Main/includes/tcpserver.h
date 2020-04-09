#ifndef TCPSERVER_H
#define TCPSERVER_H


#include <QStringList>
#include <QTcpServer>
#include <QDataStream>
#include <QMessageBox>
#include <QNetworkInterface>
//! [0]
class TCPServer : public QTcpServer
{
    Q_OBJECT

public:
    TCPServer(QObject *parent = 0);
    //void sendMsg(qintptr socketDescriptor, QString msg);


protected:
    void incomingConnection(qintptr socketDescriptor) override;

private:
    QStringList tcp_lines;
    QDataStream in;
    qintptr sDescriptor;

//server
    QTcpServer  _server;
    //QTcpSocket *_socket = nullptr;
    QList<QTcpSocket*>  _sockets;

private slots:
//    void onNewConnection();
    void onReadyRead();
    void onSocketStateChanged(QAbstractSocket::SocketState socketState);

};

#endif // TCPSERVER_H
