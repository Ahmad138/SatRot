#ifndef TCPC_H
#define TCPC_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>

class TCPc : public QObject
{
    Q_OBJECT
public:
    explicit TCPc(QObject *parent = nullptr);

signals:

public slots:
    void onReadyRead();
    void send();

private:
    QTcpSocket  _socket;
    QByteArray msg;
};

#endif // TCPC_H
