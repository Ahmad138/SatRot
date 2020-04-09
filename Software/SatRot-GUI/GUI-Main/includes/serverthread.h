#ifndef SERVERTHREAD_H
#define SERVERTHREAD_H

#include <QObject>

class ServerThread : public QObject
{
    Q_OBJECT
public:
    explicit ServerThread(QObject *parent = nullptr);

signals:

};

#endif // SERVERTHREAD_H
