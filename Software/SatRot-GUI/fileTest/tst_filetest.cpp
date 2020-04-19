#include <QtTest>
#include <QCoreApplication>

// add necessary includes here
#include "../GUI-Main/includes/httpwindow.h"

class fileTest : public QObject
{
    Q_OBJECT

public:
    fileTest();
    ~fileTest();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();
};

fileTest::fileTest()
{

}

fileTest::~fileTest()
{

}

void fileTest::initTestCase()
{

}

void fileTest::cleanupTestCase()
{

}

void fileTest::test_case1()
{
//    HttpWindow* filew = new HttpWindow;
//    filew->urlSpec = "http://www.orbitalpredictor.com/api/predict_orbit/?sats=39159,39634&start=2018-02-26_15:00:00&end=2018-02-27_15:00:00&format=czml&type=orbit";
//    filew->downloadFile();
//    QTest::qWait(100);
//    QCOMPARE(QFile::exists("/tmp/satellites.czml"), true);
}

QTEST_MAIN(fileTest)

#include "tst_filetest.moc"
