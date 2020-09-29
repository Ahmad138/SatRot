#include <QtTest>
#include <QCoreApplication>

// add necessary includes here
#include "../GUI-Main/includes/httpwindow.h"

class fileDownloadTest : public QObject
{
    Q_OBJECT

public:
    fileDownloadTest();
    ~fileDownloadTest();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

private:
    HttpWindow* file = new HttpWindow;

};

fileDownloadTest::fileDownloadTest()
{
    file->urlSpec = "http://www.orbitalpredictor.com/api/predict_orbit/?sats=39159,39634&start=2018-02-26_15:00:00&end=2018-02-27_15:00:00&format=czml&type=orbit";
}

fileDownloadTest::~fileDownloadTest()
{

}

void fileDownloadTest::initTestCase()
{

}

void fileDownloadTest::cleanupTestCase()
{

}

void fileDownloadTest::test_case1()
{
    file->downloadFile();
    QTest::qWait(100);
    QCOMPARE(QFile::exists("/tmp/satellites.czml"), true);

}

QTEST_APPLESS_MAIN(fileDownloadTest)

#include "tst_filedownloadtest.moc"
