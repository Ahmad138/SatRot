#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <QTime>
#include <QTimer>
#include <QLCDNumber>

class DigitalClock : public QLCDNumber
{
    Q_OBJECT

public:
    DigitalClock(QWidget);

private slots:
    void showTime();
};
#endif // DIGITALCLOCK_H
