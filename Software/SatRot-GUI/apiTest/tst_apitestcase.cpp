#include <QtTest>
#include <QCoreApplication>

// add necessary includes here

class apiTestCase : public QObject
{
    Q_OBJECT

public:
    apiTestCase();
    ~apiTestCase();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

apiTestCase::apiTestCase()
{

}

apiTestCase::~apiTestCase()
{

}

void apiTestCase::initTestCase()
{

}

void apiTestCase::cleanupTestCase()
{

}

void apiTestCase::test_case1()
{

}

QTEST_MAIN(apiTestCase)

#include "tst_apitestcase.moc"
