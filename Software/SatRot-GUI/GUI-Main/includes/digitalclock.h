#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <QTime>
#include <QTimer>
#include <QLCDNumber>

/**
 * @brief
 *
 */
class DigitalClock : public QLCDNumber
{
    Q_OBJECT

public:
    /**
     * @brief
     *
     * @param QWidget
     */
    DigitalClock(QWidget);

private slots:
    /**
     * @brief
     *
     */
    void showTime();
};
#endif // DIGITALCLOCK_H
