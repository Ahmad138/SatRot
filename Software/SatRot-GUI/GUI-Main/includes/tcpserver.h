#ifndef TCPSERVER_H
#define TCPSERVER_H


#include <QStringList>
#include <QTcpServer>

//! [0]
class TCPServer : public QTcpServer
{
    Q_OBJECT

public:
    TCPServer(QObject *parent = 0);

protected:
    void incomingConnection(qintptr socketDescriptor) override;

private:
    QStringList tcp_lines;
};

#endif // TCPSERVER_H
