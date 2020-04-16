#include "includes/clientthread.h"

#include <QStandardItemModel>
#include <QInputDialog>
#include <QMessageBox>
#include <QHostAddress>

/**
 * @brief
 *
 * @param parent
 */
ClientThread::ClientThread(QObject* parent) : QObject(parent)
    , m_TCPClient(new TCPClient(this)) // create the chat client
    , m_chatModel(new QStandardItemModel(this)) // create the model to hold the messages
{
    // the model for the messages will have 1 column
    m_chatModel->insertColumn(0);

    /*******************************************move to mainwindow****************************//*
    // set the model as the data source vor the list view
    ui->chatView->setModel(m_chatModel);
    *//*******************************************move to mainwindow****************************/

    // connect the signals from the chat client to the slots in this ui
    connect(m_TCPClient, &TCPClient::connected, this, &ClientThread::connectedToServer);
    connect(m_TCPClient, &TCPClient::loggedIn, this, &ClientThread::loggedIn);
    connect(m_TCPClient, &TCPClient::loginError, this, &ClientThread::loginFailed);
    connect(m_TCPClient, &TCPClient::messageReceived, this, &ClientThread::messageReceived);
    connect(m_TCPClient, &TCPClient::disconnected, this, &ClientThread::disconnectedFromServer);
    connect(m_TCPClient, &TCPClient::error, this, &ClientThread::error);
    connect(m_TCPClient, &TCPClient::userJoined, this, &ClientThread::userJoined);
    connect(m_TCPClient, &TCPClient::userLeft, this, &ClientThread::userLeft);

    /*******************************************move to mainwindow****************************//*
    // connect the connect button to a slot that will attempt the connection
    connect(ui->connectButton, &QPushButton::clicked, this, &ClientThread::attemptConnection);
    // connect the click of the "send" button and the press of the enter while typing to the slot that sends the message
    connect(ui->sendButton, &QPushButton::clicked, this, &ClientThread::sendMessage);
    connect(ui->messageEdit, &QLineEdit::returnPressed, this, &ClientThread::sendMessage);
    *//*******************************************move to mainwindow****************************/
}

ClientThread::~ClientThread()
{

}

/**
 * @brief
 *
 */
void ClientThread::attemptConnection()
{
    /*******************************************move to mainwindow****************************//*
    // We ask the user for the address of the server, we use 127.0.0.1 (aka localhost) as default
    const QString hostAddress = QInputDialog::getText(
      this
      , tr("Chose Server")
          , tr("Server Address")
          , QLineEdit::Normal
      , QStringLiteral("127.0.0.1")
      );
    if (hostAddress.isEmpty())
      return; // the user pressed cancel or typed nothing
    // disable the connect button to prevent the user clicking it again
    ui->connectButton->setEnabled(false);
    *//*******************************************move to mainwindow****************************/

    // tell the client to connect to the host using the port 1967
    //m_TCPClient->connectToServer(QHostAddress(hostAddress), 1967);
}

/**
 * @brief
 *
 */
void ClientThread::connectedToServer()
{
    /*******************************************move to mainwindow****************************//*
    // once we connected to the server we ask the user for what username they would like to use
    const QString newUsername = QInputDialog::getText(this, tr("Chose Username"), tr("Username"));
    if (newUsername.isEmpty()){
        // if the user clicked cancel or typed nothing, we just disconnect from the server
        return m_TCPClient->disconnectFromHost();
    }
    *//*******************************************move to mainwindow****************************/
    // try to login with the given username
    //attemptLogin(newUsername);
}

/**
 * @brief
 *
 * @param userName
 */
void ClientThread::attemptLogin(const QString& userName)
{
    // use the client to attempt a log in with the given username
    m_TCPClient->login(userName);
}

/**
 * @brief
 *
 */
void ClientThread::loggedIn()
{
    /*******************************************move to mainwindow****************************//*
    // once we successully log in we enable the ui to display and send messages
    ui->sendButton->setEnabled(true);
    ui->messageEdit->setEnabled(true);
    ui->chatView->setEnabled(true);
    *//*******************************************move to mainwindow****************************/
    // clear the user name record
    m_lastUserName.clear();
}

/**
 * @brief
 *
 * @param reason
 */
void ClientThread::loginFailed(const QString& reason)
{
    /*******************************************move to mainwindow****************************//*
    // the server rejected the login attempt
    // display the reason for the rejection in a message box
    QMessageBox::critical(this, tr("Error"), reason);
    *//*******************************************move to mainwindow****************************/

    // allow the user to retry, execute the same slot as when just connected
    connectedToServer();
}

/**
 * @brief
 *
 * @param sender
 * @param text
 */
void ClientThread::messageReceived(const QString& sender, const QString& text)
{
    // store the index of the new row to append to the model containing the messages
    int newRow = m_chatModel->rowCount();
    // we display a line containing the username only if it's different from the last username we displayed
    if (m_lastUserName != sender)
    {
        // store the last displayed username
        m_lastUserName = sender;
        // create a bold default font
        QFont boldFont;
        boldFont.setBold(true);
        // insert 2 row, one for the message and one for the username
        m_chatModel->insertRows(newRow, 2);
        // store the username in the model
        m_chatModel->setData(m_chatModel->index(newRow, 0), sender + ':');
        // set the alignment for the username
        m_chatModel->setData(m_chatModel->index(newRow, 0), int(Qt::AlignLeft | Qt::AlignVCenter), Qt::TextAlignmentRole);
        // set the for the username
        m_chatModel->setData(m_chatModel->index(newRow, 0), boldFont, Qt::FontRole);
        ++newRow;
    }
    else
    {
        // insert a row for the message
        m_chatModel->insertRow(newRow);
    }
    // store the message in the model
    m_chatModel->setData(m_chatModel->index(newRow, 0), text);
    // set the alignment for the message
    m_chatModel->setData(m_chatModel->index(newRow, 0), int(Qt::AlignLeft | Qt::AlignVCenter), Qt::TextAlignmentRole);
    /*******************************************move to mainwindow****************************//*
    // scroll the view to display the new message
    ui->chatView->scrollToBottom();
    *//*******************************************move to mainwindow****************************/
}

void ClientThread::sendMessage()
{
    /*******************************************move to mainwindow****************************//*
    // we use the client to send the message that the user typed
    m_TCPClient->sendMessage(ui->messageEdit->text());
    *//*******************************************move to mainwindow****************************/
    // now we add the message to the list
    // store the index of the new row to append to the model containing the messages
    const int newRow = m_chatModel->rowCount();
    // insert a row for the message
    m_chatModel->insertRow(newRow);
    /*******************************************move to mainwindow****************************//*
    // store the message in the model
    m_chatModel->setData(m_chatModel->index(newRow, 0), ui->messageEdit->text());
    *//*******************************************move to mainwindow****************************/
    // set the alignment for the message
    m_chatModel->setData(m_chatModel->index(newRow, 0), int(Qt::AlignRight | Qt::AlignVCenter), Qt::TextAlignmentRole);
    /*******************************************move to mainwindow****************************//*
    // clear the content of the message editor
    ui->messageEdit->clear();
    // scroll the view to display the new message
    ui->chatView->scrollToBottom();
    *//*******************************************move to mainwindow****************************/
    // reset the last printed username
    m_lastUserName.clear();
}

/**
 * @brief
 *
 */
void ClientThread::disconnectedFromServer()
{
    /*******************************************move to mainwindow****************************//*
    // if the client loses connection to the server
    // comunicate the event to the user via a message box
    QMessageBox::warning(this, tr("Disconnected"), tr("The host terminated the connection"));
    // disable the ui to send and display messages
    ui->sendButton->setEnabled(false);
    ui->messageEdit->setEnabled(false);
    ui->chatView->setEnabled(false);
    // enable the button to connect to the server again
    ui->connectButton->setEnabled(true);
    *//*******************************************move to mainwindow****************************/
    // reset the last printed username
    m_lastUserName.clear();
}

/**
 * @brief
 *
 * @param username
 */
void ClientThread::userJoined(const QString& username)
{
    // store the index of the new row to append to the model containing the messages
    const int newRow = m_chatModel->rowCount();
    // insert a row
    m_chatModel->insertRow(newRow);
    // store in the model the message to comunicate a user joined
    m_chatModel->setData(m_chatModel->index(newRow, 0), tr("%1 Joined the Chat").arg(username));
    // set the alignment for the text
    m_chatModel->setData(m_chatModel->index(newRow, 0), Qt::AlignCenter, Qt::TextAlignmentRole);
    // set the color for the text
    m_chatModel->setData(m_chatModel->index(newRow, 0), QBrush(Qt::blue), Qt::ForegroundRole);
    /*******************************************move to mainwindow****************************//*
    // scroll the view to display the new message
    ui->chatView->scrollToBottom();
    *//*******************************************move to mainwindow****************************/
    // reset the last printed username
    m_lastUserName.clear();
}
/**
 * @brief
 *
 * @param username
 */
void ClientThread::userLeft(const QString& username)
{
    // store the index of the new row to append to the model containing the messages
    const int newRow = m_chatModel->rowCount();
    // insert a row
    m_chatModel->insertRow(newRow);
    // store in the model the message to comunicate a user left
    m_chatModel->setData(m_chatModel->index(newRow, 0), tr("%1 Left the Chat").arg(username));
    // set the alignment for the text
    m_chatModel->setData(m_chatModel->index(newRow, 0), Qt::AlignCenter, Qt::TextAlignmentRole);
    // set the color for the text
    m_chatModel->setData(m_chatModel->index(newRow, 0), QBrush(Qt::red), Qt::ForegroundRole);
    /*******************************************move to mainwindow****************************//*
    // scroll the view to display the new message
    ui->chatView->scrollToBottom();
    *//*******************************************move to mainwindow****************************/
    // reset the last printed username
    m_lastUserName.clear();
}

/**
 * @brief
 *
 * @param socketError
 */
void ClientThread::error(QAbstractSocket::SocketError socketError)
{
    /*******************************************move to mainwindow****************************//*
    // show a message to the user that informs of what kind of error occurred
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
    case QAbstractSocket::ProxyConnectionClosedError:
        return; // handled by disconnectedFromServer
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::critical(this, tr("Error"), tr("The host refused the connection"));
        break;
    case QAbstractSocket::ProxyConnectionRefusedError:
        QMessageBox::critical(this, tr("Error"), tr("The proxy refused the connection"));
        break;
    case QAbstractSocket::ProxyNotFoundError:
        QMessageBox::critical(this, tr("Error"), tr("Could not find the proxy"));
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::critical(this, tr("Error"), tr("Could not find the server"));
        break;
    case QAbstractSocket::SocketAccessError:
        QMessageBox::critical(this, tr("Error"), tr("You don't have permissions to execute this operation"));
        break;
    case QAbstractSocket::SocketResourceError:
        QMessageBox::critical(this, tr("Error"), tr("Too many connections opened"));
        break;
    case QAbstractSocket::SocketTimeoutError:
        QMessageBox::warning(this, tr("Error"), tr("Operation timed out"));
        return;
    case QAbstractSocket::ProxyConnectionTimeoutError:
        QMessageBox::critical(this, tr("Error"), tr("Proxy timed out"));
        break;
    case QAbstractSocket::NetworkError:
        QMessageBox::critical(this, tr("Error"), tr("Unable to reach the network"));
        break;
    case QAbstractSocket::UnknownSocketError:
        QMessageBox::critical(this, tr("Error"), tr("An unknown error occured"));
        break;
    case QAbstractSocket::UnsupportedSocketOperationError:
        QMessageBox::critical(this, tr("Error"), tr("Operation not supported"));
        break;
    case QAbstractSocket::ProxyAuthenticationRequiredError:
        QMessageBox::critical(this, tr("Error"), tr("Your proxy requires authentication"));
        break;
    case QAbstractSocket::ProxyProtocolError:
        QMessageBox::critical(this, tr("Error"), tr("Proxy comunication failed"));
        break;
    case QAbstractSocket::TemporaryError:
    case QAbstractSocket::OperationError:
        QMessageBox::warning(this, tr("Error"), tr("Operation failed, please try again"));
        return;
    default:
        Q_UNREACHABLE();
    }
    // enable the button to connect to the server again
    ui->connectButton->setEnabled(true);
    // disable the ui to send and display messages
    ui->sendButton->setEnabled(false);
    ui->messageEdit->setEnabled(false);
    ui->chatView->setEnabled(false);
    *//*******************************************move to mainwindow****************************/
    // reset the last printed username
    m_lastUserName.clear();
}
