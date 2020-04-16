#ifndef API_H
#define API_H

#include <QObject>
#include <QBuffer>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <functional>

#include <iostream>

/**
 * @brief api class for api requests to api serves
 *
 */
class api : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief
     *
     */
    typedef std::function<void(const QJsonObject&)> handleFunc;
    /**
     * @brief
     *
     */
    typedef std::function<void()> finishFunc;

    static const QString KEY_QNETWORK_REPLY_ERROR; /**< TODO: describe */
    static const QString KEY_CONTENT_NOT_FOUND; /**< TODO: describe */

    /**
     * @brief
     *
     */
    enum class Type
    {
        POST,
        GET,
        PATCH,
        DELET
    };

    /**
     * @brief
     *
     * @param parent
     */
    explicit api(QObject* parent = 0);

    /**
     * @brief
     *
     * @param host
     * @param port
     * @param value
     */
    void initRequester(const QString& host, int port, QSslConfiguration* value);

    /**
     * @brief
     *
     * @param apiStr
     * @param funcSuccess
     * @param funcError
     * @param type
     * @param data
     */
    void sendRequest(const QString& apiStr,
                     const handleFunc& funcSuccess,
                     const handleFunc& funcError,
                     Type type = Type::GET,
                     const QVariantMap& data = QVariantMap());


    /**
     * @brief
     *
     * @param apiStr
     * @param funcSuccess
     * @param funcError
     * @param funcFinish
     */
    void sendMulishGetRequest(const QString& apiStr,
                              const handleFunc& funcSuccess,
                              const handleFunc& funcError,
                              const finishFunc& funcFinish);

    /**
     * @brief
     *
     * @return QString
     */
    QString getToken() const;
    /**
     * @brief
     *
     * @param value
     */
    void setToken(const QString& value);

private:
    static const QString httpTemplate; /**< TODO: describe */
    static const QString httpsTemplate; /**< TODO: describe */

    QString host; /**< TODO: describe */
    int port; /**< TODO: describe */
    QString token; /**< TODO: describe */
    QSslConfiguration* sslConfig; /**< TODO: describe */

    QString pathTemplate; /**< TODO: describe */

    /**
     * @brief
     *
     * @param data
     * @return QByteArray
     */
    QByteArray variantMapToJson(QVariantMap data);

    /**
     * @brief
     *
     * @param apiStr
     * @return QNetworkRequest
     */
    QNetworkRequest createRequest(const QString& apiStr);

    /**
     * @brief
     *
     * @param manager
     * @param request
     * @param type
     * @param data
     * @return QNetworkReply
     */
    QNetworkReply* sendCustomRequest(QNetworkAccessManager* manager,
                                     QNetworkRequest& request,
                                     const QString& type,
                                     const QVariantMap& data);

    /**
     * @brief
     *
     * @param reply
     * @return QJsonObject
     */
    QJsonObject parseReply(QNetworkReply* reply);

    /**
     * @brief
     *
     * @param reply
     * @return bool
     */
    bool onFinishRequest(QNetworkReply* reply);

    /**
     * @brief
     *
     * @param reply
     * @param obj
     */
    void handleQtNetworkErrors(QNetworkReply* reply, QJsonObject& obj);
    QNetworkAccessManager* manager; /**< TODO: describe */

signals:
    /**
     * @brief
     *
     */
    void networkError();


public slots:
};
#endif // API_H

