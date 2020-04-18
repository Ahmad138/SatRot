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
 * @brief
 * api class for api requests to api services. This will
 * allow us to make GET, POST request to api services such as NASA, N2YO, celestrak and orbitalpredictor
 *
 */
class api : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief
     *Lambda function type definition to handle request response
     *
     */
    typedef std::function<void(const QJsonObject&)> handleFunc;
    /**
     * @brief
     *Lambda function to handle finished response from multi request
     */
    typedef std::function<void()> finishFunc;

    static const QString KEY_QNETWORK_REPLY_ERROR; /**< TODO: describe */
    static const QString KEY_CONTENT_NOT_FOUND; /**< TODO: describe */

    /**
     * @brief
     *Enumerate the types of requests we want to handle
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
     *The api constructor takes in the parent as a QObject type from the main window
     * @param parent -> a pointer initialised to 0
     */
    explicit api(QObject* parent = 0);

    /**
     * @brief
     * Initialises a request that would be handled.
     *
     * @param host -> This is the host url/ip to fetch the data from
     * @param port -> This is the port of the request. e.g is 80 for web api
     * @param value -> If the request requires SSL configuration, it is inserted here, else, pass a nullptr
     */
    void initRequester(const QString& host, int port, QSslConfiguration* value);

    /**
     * @brief
     * This method handles the sending of the request to the network.
     *
     * @param apiStr -> sets the url endpoint for the request
     * @param funcSuccess -> This lambda function is called when the request receives a successful response
     * @param funcError -> This lambda function instead is called when an error occurs and there was a bad response
     * @param type -> The type of request. By default is set to a GET request
     * @param data -> The data is mapped to the appropriate type when it is received
     */
    void sendRequest(const QString& apiStr,
                     const handleFunc& funcSuccess,
                     const handleFunc& funcError,
                     Type type = Type::GET,
                     const QVariantMap& data = QVariantMap());


    /**
     * @brief
     *This similar to the sendRequest() method, but handle multiple requests at the same time.
     *
     * @param apiStr -> sets the url endpoint for the request
     * @param funcSuccess -> This lambda function is called when the request receives a successful response
     * @param funcError -> This lambda function instead is called when an error occurs and there was a bad response
     * @param type -> The type of request. By default is set to a GET request
     */
    void sendMulishGetRequest(const QString& apiStr,
                              const handleFunc& funcSuccess,
                              const handleFunc& funcError,
                              const finishFunc& funcFinish);

    /**
     * @brief
     *returns the value of the token that was set for requests that require token
     * @return QString
     */
    QString getToken() const;
    /**
     * @brief
     *Sets the value of token to the instance for requests that require tokens for access
     * @param value -> the token is sent as an argument to the method
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

