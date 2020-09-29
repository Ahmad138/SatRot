#include "../includes/httpwindow.h"

#include <QtWidgets>
#include <QtNetwork>
#include <QUrl>

HttpWindow::HttpWindow(QObject* parent)
    : QObject(parent)
{
    QString downloadDirectory = QStandardPaths::writableLocation(QStandardPaths::TempLocation);
    if (downloadDirectory.isEmpty() || !QFileInfo(downloadDirectory).isDir())
        downloadDirectory = QDir::currentPath();
    downloadDirectoryPath = QDir::toNativeSeparators(downloadDirectory);
}

HttpWindow::~HttpWindow()
{
}

void HttpWindow::startRequest(const QUrl& requestedUrl)
{
    url = requestedUrl;
    httpRequestAborted = false;

    reply = qnam.get(QNetworkRequest(url));
    connect(reply, &QNetworkReply::finished, this, &HttpWindow::httpFinished);
    connect(reply, &QIODevice::readyRead, this, &HttpWindow::httpReadyRead);
}

void HttpWindow::downloadFile()
{
    if (urlSpec.isEmpty())
        return;

    const QUrl newUrl = QUrl::fromUserInput(urlSpec);
    if (!newUrl.isValid())
    {
        return;
    }

    QString downloadDirectory = QDir::cleanPath(downloadDirectoryPath);
    bool useDirectory = !downloadDirectory.isEmpty() && QFileInfo(downloadDirectory).isDir();
    if (useDirectory)
        fileName.prepend(downloadDirectory + '/');
    if (QFile::exists(fileName))
    {
        QFile::remove(fileName);
    }

    file = openFileForWrite(fileName);
    if (!file)
        return;

    // schedule the request
    startRequest(newUrl);
}

std::unique_ptr<QFile> HttpWindow::openFileForWrite(const QString& fileName)
{
    std::unique_ptr<QFile> file(new QFile(fileName));
    if (!file->open(QIODevice::WriteOnly))
    {
        return nullptr;
    }
    return file;
}

void HttpWindow::cancelDownload()
{
    qDebug() << "Download canceled.";
    httpRequestAborted = true;
    reply->abort();
}

void HttpWindow::httpFinished()
{
    QFileInfo fi;
    if (file)
    {
        fi.setFile(file->fileName());
        file->close();
        file.reset();
    }

    if (httpRequestAborted)
    {
        reply->deleteLater();
        reply = nullptr;
        return;
    }

    if (reply->error())
    {
        QFile::remove(fi.absoluteFilePath());
        qDebug() << tr("Download failed:\n%1.").arg(reply->errorString());

        reply->deleteLater();
        reply = nullptr;
        return;
    }

    const QVariant redirectionTarget = reply->attribute(QNetworkRequest::RedirectionTargetAttribute);

    reply->deleteLater();
    reply = nullptr;

    if (!redirectionTarget.isNull())
    {
        const QUrl redirectedUrl = url.resolved(redirectionTarget.toUrl());

        file = openFileForWrite(fi.absoluteFilePath());
        if (!file)
        {

            return;
        }
        startRequest(redirectedUrl);
        return;
    }
}

void HttpWindow::httpReadyRead()
{
    if (file)
        file->write(reply->readAll());
}


#ifndef QT_NO_SSL
void HttpWindow::sslErrors(QNetworkReply*, const QList<QSslError>& errors)
{
    QString errorString;
    for (const QSslError& error : errors)
    {
        if (!errorString.isEmpty())
            errorString += '\n';
        errorString += error.errorString();
    }
}
#endif
