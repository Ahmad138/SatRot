#ifndef TCPS_H
#define TCPS_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class TCPs : public QObject
{
    Q_OBJECT
public:
    explicit TCPs(QObject *parent = nullptr);

public slots:
    void onNewConnection();
    void onSocketStateChanged(QAbstractSocket::SocketState socketState);
    void onReadyRead();

signals:

private:
    QTcpServer  _server;
    QList<QTcpSocket*>  _sockets;
};

#endif // TCPS_H
