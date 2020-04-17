#include <QtTest>
#include <QCoreApplication>

// add necessary includes here
#include "../GUI-Main/includes/api.h"

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
    void test_case2();
    void test_case3();
    void test_case4();
    void test_case5();

private:
    int a;
    QString b, c, d, e;
    api* r = new api(this);
};

apiTestCase::apiTestCase()
{
    QString url = "jsonplaceholder.typicode.com/users/3";
    r->initRequester(url, 80, nullptr);

    api::handleFunc getData = [this](const QJsonObject & o)
    {
        a = o.value("id").toInt();
        b = o.value("company")["name"].toString();
        c = o.value("address")["city"]["geo"]["lat"].toString();
        d = o.value("company")["catchPhrase"].toString();
    };

    api::handleFunc errData = [this](const QJsonObject & o)
    {
        e = "Error: connection dropped";
    };

    r->sendRequest(url, getData, errData);
}

apiTestCase::~apiTestCase()
{

}

void apiTestCase::initTestCase()
{

}

void apiTestCase::cleanupTestCase()
{
    //delete api;
}

void apiTestCase::test_case1()
{
    QCOMPARE(a, 3);
}

void apiTestCase::test_case2()
{
    QCOMPARE(b, "Romaguera-Jacobson");
}

void apiTestCase::test_case3()
{
    QCOMPARE(c, "-68.6102");
}

void apiTestCase::test_case4()
{
    QCOMPARE(d, "Face to face bifurcated interface");
}

void apiTestCase::test_case5()
{
    QCOMPARE(e, "Error: connection dropped");
}


QTEST_MAIN(apiTestCase)

#include "tst_apitestcase.moc"
