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

/**
 * @brief
 *
 */
class HttpWindow : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief
     *
     * @param parent
     */
    explicit HttpWindow(QObject* parent = 0);
    /**
     * @brief
     *
     */
    ~HttpWindow();


    QString urlSpec = ""; /**< TODO: describe */
    /**
     * @brief
     *
     */
    void downloadFile();


private slots:
    /**
     * @brief
     *
     * @param requestedUrl
     */
    void startRequest(const QUrl& requestedUrl);
    /**
     * @brief
     *
     */
    void cancelDownload();
    /**
     * @brief
     *
     */
    void httpFinished();
    /**
     * @brief
     *
     */
    void httpReadyRead();
    /**
     * @brief
     *
     */
    void enableDownloadButton();
    /**
     * @brief
     *
     * @param
     * @param authenticator
     */
    void slotAuthenticationRequired(QNetworkReply*, QAuthenticator* authenticator);
#ifndef QT_NO_SSL
    /**
     * @brief
     *
     * @param
     * @param errors
     */
    void sslErrors(QNetworkReply*, const QList<QSslError>& errors);
#endif

private:
    /**
     * @brief
     *
     * @param fileName
     * @return std::unique_ptr<QFile>
     */
    std::unique_ptr<QFile> openFileForWrite(const QString& fileName);

    //QLabel *statusLabel;
    //QLineEdit *urlLineEdit;
    //QPushButton *downloadButton;
    //QCheckBox *launchCheckBox;
    QString downloadDirectoryPath = ""; /**< TODO: describe */
    QString fileName = "satellites.czml"; /**< TODO: describe */

    QUrl url; /**< TODO: describe */
    QNetworkAccessManager qnam; /**< TODO: describe */
    QNetworkReply* reply; /**< TODO: describe */
    std::unique_ptr<QFile> file; /**< TODO: describe */
    bool httpRequestAborted; /**< TODO: describe */
};

#endif
