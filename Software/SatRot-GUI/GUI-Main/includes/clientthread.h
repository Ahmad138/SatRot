#ifndef CLIENTTHREAD_H
#define CLIENTTHREAD_H

#include <QObject>

class ClientThread : public QObject
{
    Q_OBJECT
public:
    explicit ClientThread(QObject *parent = nullptr);

signals:

};

#endif // CLIENTTHREAD_H
