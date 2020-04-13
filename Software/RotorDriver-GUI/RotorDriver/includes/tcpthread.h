#ifndef TCPTHREAD_H
#define TCPTHREAD_H

#include <QThread>
#include <QTcpSocket>

//! [0]
class TCPThread : public QThread
{
    Q_OBJECT

public:
    TCPThread(int socketDescriptor, const QString &tcp_line, QObject *parent);

    void run() override;

signals:
    void error(QTcpSocket::SocketError socketError);

private:
    int socketDescriptor;
    QString text;
};
//! [0]


#endif // TCPTHREAD_H
