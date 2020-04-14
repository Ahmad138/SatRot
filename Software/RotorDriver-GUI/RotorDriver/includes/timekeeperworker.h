#ifndef TIMEKEEPERWORKER_H
#define TIMEKEEPERWORKER_H

#include <QObject>
#include "includes/CppThread.h"
#include "includes/api.h"

#include <iostream>
#include <ctime>
#include <chrono>
#include <QTimer>
#include <QDateTime>
#include <QJsonArray>
#include <QJsonObject>
#include <math.h>

class TimeKeeperWorker : public QObject
{
    Q_OBJECT
public:
    explicit TimeKeeperWorker(QObject *parent = nullptr, QString url="", int start=0, int stop=0);
    void getSatPos();

signals:

private:


private:
    int m_start;
    int m_stop;
    int count;
    QJsonObject positions;
    QString url;

private slots:
    void Timer();

};

#endif // TIMEKEEPERWORKER_H
