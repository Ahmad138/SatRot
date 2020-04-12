#include "includes/tcpsockets.h"

TCPsockets::TCPsockets()
{

}

void TCPsockets::readSocket()
{
    QByteArray block = socket->readAll();

    QDataStream in(&block, QIODevice::ReadOnly);
    in.setVersion(QDataStream::Qt_5_11);

    while (!in.atEnd())
    {
        QString receiveString;
        in >> receiveString;
        receiveString.prepend(QString("%1 :: ").arg(socket->socketDescriptor()));
        //emit newMessage(receiveString);
    }
}

QString TCPsockets::discardSocket()
{
    socket->deleteLater();
    socket=nullptr;

    //this->ui->statusBar->showMessage("Disconnected!");
    return "Disconnected!";
}

void TCPsockets::on_pushButton_sendMessage_clicked()
{
    if(socket)
    {
        if(socket->isOpen())
        {
            //QString str = this->ui->lineEdit_message->text();

            QByteArray block;
            QDataStream out(&block, QIODevice::WriteOnly);

            out.setVersion(QDataStream::Qt_5_11);
            //out << str;

            socket->write(block);

            //this->ui->lineEdit_message->clear();
        }
        else
            //QMessageBox::critical(this,"QTCPClient","Socket doesn't seem to be opened");
            int a; //dummy
    }
    else
        //QMessageBox::critical(this,"QTCPClient","Not connected");
        int b; //dummy
}

void TCPsockets::displayMessage(const QString& str)
{
    //this->ui->textBrowser_receivedMessages->append(str);
}
