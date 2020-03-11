#ifndef TCPSOCKETS_H
#define TCPSOCKETS_H

#include <QObject>
#include <QAbstractSocket>
#include <QDebug>
#include <QHostAddress>
#include <QMessageBox>
#include <QMetaType>
#include <QString>
#include <QTcpSocket>

class TCPsockets
{
public:
    TCPsockets();
signals:
    void newMessage(QString);
private slots:
    void readSocket();
    QString discardSocket();

    void displayMessage(const QString& str);
    void on_pushButton_sendMessage_clicked();
private:    

    QTcpSocket* socket;
};

#endif // TCPSOCKETS_H
