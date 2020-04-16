#ifndef TCPTHREAD_H
#define TCPTHREAD_H

#include <QThread>
#include <QTcpSocket>

//! [0]
/**
 * @brief
 *
 */
class TCPThread : public QThread
{
    Q_OBJECT

public:
    /**
     * @brief
     *
     * @param socketDescriptor
     * @param tcp_line
     * @param parent
     */
    TCPThread(int socketDescriptor, const QString& tcp_line, QObject* parent);

    /**
     * @brief
     *
     */
    void run() override;

signals:
    /**
     * @brief
     *
     * @param socketError
     */
    void error(QTcpSocket::SocketError socketError);

private:
    int socketDescriptor; /**< TODO: describe */
    QString text; /**< TODO: describe */
};
//! [0]


#endif // TCPTHREAD_H
