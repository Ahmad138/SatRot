#ifndef TIMEKEEPERWORKER_H
#define TIMEKEEPERWORKER_H

#include <QObject>
#include "includes/CppThread.h"
#include "includes/api.h"
#include "includes/stepperdriver.h"

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

    stepperDriver AzDriver(0, 2, 3, 12, 13, 14);
    stepperDriver ElDriver(1, 4, 5, 6, 10, 11);

private slots:
    void Timer();

};

#endif // TIMEKEEPERWORKER_H
