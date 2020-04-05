#include "includes/httpwindow.h"

#include <QtWidgets>
#include <QtNetwork>
#include <QUrl>

HttpWindow::HttpWindow(QObject *parent)
    : QObject(parent)
{

    connect(&qnam, &QNetworkAccessManager::authenticationRequired,
            this, &HttpWindow::slotAuthenticationRequired);
#ifndef QT_NO_SSL
    connect(&qnam, &QNetworkAccessManager::sslErrors,
            this, &HttpWindow::sslErrors);
#endif

    QString downloadDirectory = QStandardPaths::writableLocation(QStandardPaths::TempLocation);
    if (downloadDirectory.isEmpty() || !QFileInfo(downloadDirectory).isDir())
        downloadDirectory = QDir::currentPath();
    downloadDirectoryPath = QDir::toNativeSeparators(downloadDirectory);
    //downloadFile();

}

HttpWindow::~HttpWindow()
{
}

void HttpWindow::startRequest(const QUrl &requestedUrl)
{
    url = requestedUrl;
    httpRequestAborted = false;

    reply = qnam.get(QNetworkRequest(url));
    //qDebug()<< reply->readAll();
    connect(reply, &QNetworkReply::finished, this, &HttpWindow::httpFinished);
    connect(reply, &QIODevice::readyRead, this, &HttpWindow::httpReadyRead);
    //httpFinished();
    //httpReadyRead();
    qDebug()<<tr("Downloading %1...").arg(url.toString());
}

void HttpWindow::downloadFile()
{
    if (urlSpec.isEmpty())
        return;

    const QUrl newUrl = QUrl::fromUserInput(urlSpec);
    if (!newUrl.isValid()) {
//        QMessageBox::information(this, tr("Error"),
//                                 tr("Invalid URL: %1: %2").arg(urlSpec, newUrl.errorString()));
        return;
    }

    QString downloadDirectory = QDir::cleanPath(downloadDirectoryPath);
    bool useDirectory = !downloadDirectory.isEmpty() && QFileInfo(downloadDirectory).isDir();
    if (useDirectory)
        fileName.prepend(downloadDirectory + '/');
    if (QFile::exists(fileName)) {
//        if (QMessageBox::question(this, tr("Overwrite Existing File"),
//                                  tr("There already exists a file called %1%2."
//                                     " Overwrite?")
//                                     .arg(fileName,
//                                          useDirectory
//                                           ? QString()
//                                           : QStringLiteral(" in the current directory")),
//                                     QMessageBox::Yes | QMessageBox::No,
//                                     QMessageBox::No)
//            == QMessageBox::No) {
//            return;
//        }
        QFile::remove(fileName);
    }

    file = openFileForWrite(fileName);
    if (!file)
        return;


    // schedule the request
    startRequest(newUrl);
}

std::unique_ptr<QFile> HttpWindow::openFileForWrite(const QString &fileName)
{
    std::unique_ptr<QFile> file(new QFile(fileName));
    if (!file->open(QIODevice::WriteOnly)) {
//        QMessageBox::information(this, tr("Error"),
//                                 tr("Unable to save the file %1: %2.")
//                                 .arg(QDir::toNativeSeparators(fileName),
//                                      file->errorString()));
        return nullptr;
    }
    return file;
}

void HttpWindow::cancelDownload()
{
    qDebug() <<"Download canceled.";
    httpRequestAborted = true;
    reply->abort();
}

void HttpWindow::httpFinished()
{
    //qDebug() << "hereeeeeeeeeee";
    QFileInfo fi;
    if (file) {
        fi.setFile(file->fileName());
        file->close();
        file.reset();
    }

    if (httpRequestAborted) {
        reply->deleteLater();
        reply = nullptr;
        return;
    }

    if (reply->error()) {
        QFile::remove(fi.absoluteFilePath());
        qDebug() << tr("Download failed:\n%1.").arg(reply->errorString());

        reply->deleteLater();
        reply = nullptr;
        return;
    }

    const QVariant redirectionTarget = reply->attribute(QNetworkRequest::RedirectionTargetAttribute);

    reply->deleteLater();
    reply = nullptr;

    if (!redirectionTarget.isNull()) {
        const QUrl redirectedUrl = url.resolved(redirectionTarget.toUrl());
//        if (QMessageBox::question(this, tr("Redirect"),
//                                  tr("Redirect to %1 ?").arg(redirectedUrl.toString()),
//                                  QMessageBox::Yes | QMessageBox::No) == QMessageBox::No) {
//            QFile::remove(fi.absoluteFilePath());

//            qDebug() << tr("Download failed:\nRedirect rejected.");
//            return;
//        }
        file = openFileForWrite(fi.absoluteFilePath());
        if (!file) {

            return;
        }
        startRequest(redirectedUrl);
        return;
    }

    qDebug() << tr("Downloaded %1 bytes to %2\nin\n%3")
                         .arg(fi.size()).arg(fi.fileName(), QDir::toNativeSeparators(fi.absolutePath()));

}

void HttpWindow::httpReadyRead()
{
    // this slot gets called every time the QNetworkReply has new data.
    // We read all of its new data and write it into the file.
    // That way we use less RAM than when reading it at the finished()
    // signal of the QNetworkReply
    //qDebug()<<"ready....";
    if (file)
        file->write(reply->readAll());
}

void HttpWindow::enableDownloadButton()
{
    //downloadButton->setEnabled(!urlLineEdit->text().isEmpty());
}

void HttpWindow::slotAuthenticationRequired(QNetworkReply *, QAuthenticator *authenticator)
{

}

#ifndef QT_NO_SSL
void HttpWindow::sslErrors(QNetworkReply *, const QList<QSslError> &errors)
{
    QString errorString;
    for (const QSslError &error : errors) {
        if (!errorString.isEmpty())
            errorString += '\n';
        errorString += error.errorString();
    }

//    if (QMessageBox::warning(this, tr("SSL Errors"),
//                             tr("One or more SSL errors has occurred:\n%1").arg(errorString),
//                             QMessageBox::Ignore | QMessageBox::Abort) == QMessageBox::Ignore) {
//        reply->ignoreSslErrors();
//    }
}
#endif
