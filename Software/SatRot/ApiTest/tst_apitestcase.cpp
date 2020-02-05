#include <QtTest>
#include <QCoreApplication>

// add necessary includes here
#include "../src/appa.h"

class ApiTestCase : public QObject
{
    Q_OBJECT

public:
    ApiTestCase();
    ~ApiTestCase();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

ApiTestCase::ApiTestCase()
{

}

ApiTestCase::~ApiTestCase()
{

}

void ApiTestCase::initTestCase()
{
}

void ApiTestCase::cleanupTestCase()
{

}

void ApiTestCase::test_case1()
{
    appa a(0, 0);
    QVERIFY(a.GetA() == 0);
    QVERIFY(a.GetB() == 0);
}

QTEST_MAIN(ApiTestCase)

#include "tst_apitestcase.moc"
