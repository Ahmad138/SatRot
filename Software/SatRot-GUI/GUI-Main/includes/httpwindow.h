#ifndef HTTPWINDOW_H
#define HTTPWINDOW_H

#include <QProgressDialog>
#include <QNetworkAccessManager>
#include <QUrl>

#include <memory>

QT_BEGIN_NAMESPACE
class QFile;
class QLabel;
class QLineEdit;
class QPushButton;
class QSslError;
class QAuthenticator;
class QNetworkReply;
class QCheckBox;

QT_END_NAMESPACE

class HttpWindow : public QObject
{
    Q_OBJECT

public:
    explicit HttpWindow(QObject *parent = 0);
    ~HttpWindow();


    QString urlSpec = "";
    void downloadFile();


private slots:
    void startRequest(const QUrl &requestedUrl);
    void cancelDownload();
    void httpFinished();
    void httpReadyRead();
    void enableDownloadButton();
    void slotAuthenticationRequired(QNetworkReply *, QAuthenticator *authenticator);
#ifndef QT_NO_SSL
    void sslErrors(QNetworkReply *, const QList<QSslError> &errors);
#endif

private:
    std::unique_ptr<QFile> openFileForWrite(const QString &fileName);

    //QLabel *statusLabel;
    //QLineEdit *urlLineEdit;
    //QPushButton *downloadButton;
    //QCheckBox *launchCheckBox;
    QString downloadDirectoryPath = "";
    QString fileName = "satellites.czml";

    QUrl url;
    QNetworkAccessManager qnam;
    QNetworkReply *reply;
    std::unique_ptr<QFile> file;
    bool httpRequestAborted;
};

#endif
