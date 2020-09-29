#ifndef TCPC_H
#define TCPC_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>

/**
 * @brief
 *
 */
class TCPc : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief
     *
     * @param parent
     */
    explicit TCPc(QObject* parent = nullptr);

signals:

public slots:
    /**
     * @brief
     *
     */
    void onReadyRead();
    /**
     * @brief
     *
     */
    void send();

private:
    QTcpSocket  _socket; /**< TODO: describe */
    QByteArray msg; /**< TODO: describe */
};

#endif // TCPC_H
