#ifndef HTTPWINDOW_H
#define HTTPWINDOW_H

#include <QtNetwork/QNetworkAccessManager>
#include <QUrl>

#include <memory>

QT_BEGIN_NAMESPACE
class QFile;
class QNetworkReply;
QT_END_NAMESPACE

/**
 * @brief
 * This class is used to download file from the api orbitalpredictor.com provides.
 * This has the czml data that has the orbital parameters of satellites attached to them.
 *
 * @author Ahmad Muhammad (https://github.com/Ahmad138)
 */
class HttpWindow : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief
     *The constructor checks for the path to the temporary location to save the downloaded file to.
     * @param parent
     */
    explicit HttpWindow(QObject* parent = 0);

    /**
     * @brief
     *This is the destructor for the class
     */
    ~HttpWindow();


    QString urlSpec = ""; /**< TODO: describe */
    /**
     * @brief
     *Instanciates the download of the file into the specified directory.
     * sets the file name, check if the file exists and overrides it.
     */
    void downloadFile();


private slots:
    /**
     * @brief
     * This is called to start the request of the download.
     *
     * @param requestedUrl -> takes in the endpoint to download the file from
     */
    void startRequest(const QUrl& requestedUrl);

    /**
     * @brief
     * Used to cancel the download of the file.
     */
    void cancelDownload();

    /**
     * @brief
     * This is called when the download has finished and if it downloaded successfully, sets the file name and closes it.
     * If it failed, it will display the error and clean the memory of any fragment of data.
     */
    void httpFinished();

    /**
     * @brief
     * This slot gets called every time the QNetworkReply has new data.
     * We read all of its new data and write it into the file.
     * That way we use less RAM than when reading it at the finished()
     * signal of the QNetworkReply
     */
    void httpReadyRead();

#ifndef QT_NO_SSL
    /**
     * @brief
     * This handles the ssl errors that occur during the transaction
     * @param
     * @param errors
     */
    void sslErrors(QNetworkReply*, const QList<QSslError>& errors);
#endif

private:
    /**
     * @brief
     * Get the file opened for writing the downloaded data
     * @param fileName -> pass in the file name as a pointer
     * @return std::unique_ptr<QFile>
     */
    std::unique_ptr<QFile> openFileForWrite(const QString& fileName);

    QString downloadDirectoryPath = ""; /**< TODO: describe */
    QString fileName = "satellites.czml"; /**< TODO: describe */

    QUrl url; /**< TODO: describe */
    QNetworkAccessManager qnam; /**< TODO: describe */
    QNetworkReply* reply; /**< TODO: describe */
    std::unique_ptr<QFile> file; /**< TODO: describe */
    bool httpRequestAborted; /**< TODO: describe */
};

#endif
