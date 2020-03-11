#include <QtTest>
#include <QCoreApplication>

// add necessary includes here

class driverTestCase : public QObject
{
    Q_OBJECT

public:
    driverTestCase();
    ~driverTestCase();

private slots:
    void test_case1();

};

driverTestCase::driverTestCase()
{

}

driverTestCase::~driverTestCase()
{

}

void driverTestCase::test_case1()
{

}

QTEST_MAIN(driverTestCase)

#include "tst_drivertestcase.moc"
