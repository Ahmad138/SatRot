#include "includes/mainwindow.h"

/***********TCPClient***********/
#include <QStandardItemModel>
#include <QInputDialog>
#include <QMessageBox>
#include <QHostAddress>
/***********TCPClient***********/

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
  , m_TCPServer(new TCPServer(this)) // create the network server
  , m_TCPClient(new TCPClient(this)) // create the network client
{
    ui->setupUi(this);

    ui->statusBar->setEnabled(true);
    ui->statusBar->showMessage("Loading");

    //server function connections
   connect(ui->startStopButton, &QPushButton::clicked, this, &MainWindow::toggleStartServer);
   connect(m_TCPServer, &TCPServer::logMessage, this, &MainWindow::logMessage);
   connect(m_TCPServer, &TCPServer::logData, this, &MainWindow::logData);

   //client function connections
   /***********TCPClient***********/
//   ui->chatView->setModel(m_chatModel);
   // connect the signals from the chat client to the slots in this ui
   connect(m_TCPClient, &TCPClient::connected, this, &MainWindow::connectedToServer);
   connect(m_TCPClient, &TCPClient::loggedIn, this, &MainWindow::loggedIn);
   connect(m_TCPClient, &TCPClient::loginError, this, &MainWindow::loginFailed);
   connect(m_TCPClient, &TCPClient::messageReceived, this, &MainWindow::messageReceived);
   connect(m_TCPClient, &TCPClient::disconnected, this, &MainWindow::disconnectedFromServer);
   connect(m_TCPClient, &TCPClient::error, this, &MainWindow::error);
   connect(m_TCPClient, &TCPClient::userJoined, this, &MainWindow::userJoined);
   connect(m_TCPClient, &TCPClient::userLeft, this, &MainWindow::userLeft);
   // connect the connect button to a slot that will attempt the connection
   connect(ui->connectButton, &QPushButton::clicked, this, &MainWindow::attemptConnection);
   // connect the click of the "send" button and the press of the enter while typing to the slot that sends the message
   connect(ui->sendButton, &QPushButton::clicked, this, &MainWindow::sendMessage);
   connect(ui->messageEdit, &QLineEdit::returnPressed, this, &MainWindow::sendMessage);

   ui->AzLcd->setDigitCount(8);
   ui->AzLcd->setStyleSheet( "color: red; font-size:20pt;" );
   ui->AzLcd->display("0.00'");

   ui->ElLcd->setDigitCount(8);
   ui->ElLcd->setStyleSheet( "color: blue; font-size:20pt;" );
   ui->ElLcd->display("0.00'");

   ui->trackingInfo->setPlainText("No tracking is scheduled yet");


   QTimer *timerT = new QTimer();
   connect(timerT, SIGNAL(timeout()), this, SLOT(Timer()));
   timerT->start(250);

}

MainWindow::~MainWindow()
{
    delete ui;
}
/*
void MainWindow::on_pushButton_toggled(bool checked)
{
    stepperDriver AzDriver(0, 2, 3, 12, 13, 14);

        helper hh;
        int i;
        if(checked){
            AzDriver.setDirection(CW);
            //AzDriver.stepDegrees(90);
            for(i = 0; i<360; i+=10){
                AzDriver.stepDegrees(i);
                hh.re_routeResources(1000);
            }

        }else {
            AzDriver.setDirection(CCW);
            //AzDriver.stepDegrees(180);
            for(i = 360; i>0; i-=10){
                AzDriver.stepDegrees(i);
                hh.re_routeResources(1000);
            }
        }
}

*/

void MainWindow::toggleStartServer()
{
    if (m_TCPServer->isListening()) {
        m_TCPServer->stopServer();
        ui->startStopButton->setText(tr("Start Server"));
        logMessage(QStringLiteral("Server Stopped"));
    } else {

        QString ipAddress;
        QHostAddress ip;
        QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
        // use the first non-localhost IPv4 address
        for (int i = 0; i < ipAddressesList.size(); ++i) {
            if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
                ipAddressesList.at(i).toIPv4Address()) {
                ipAddress = ipAddressesList.at(i).toString();
                ip = ipAddressesList.at(i);
                break;
            }
        }
        // if we did not find one, use IPv4 localhost
        if (ipAddress.isEmpty()){
            ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
            ip = QHostAddress::LocalHost;
        }
        if (!m_TCPServer->listen(ip, 1967)) {
            QMessageBox::critical(this, tr("Error"), tr("Unable to start the server"));
            return;
        }

        logMessage(QStringLiteral("The server is running on\n\nIP: %1\nport: %2\n\n"
                                  "Run the SatRot Controller Software Client now and connect.")
                       .arg(ipAddress).arg(m_TCPServer->serverPort()));

        ui->startStopButton->setText(tr("Stop Server"));
    }
}

void MainWindow::logMessage(const QString &msg)
{
    ui->logEditor->appendPlainText(msg + '\n');
}

void MainWindow::logData(const QJsonObject &doc)
{
    if(doc.value("type") == "message"){
        ui->mode->setText(doc.value("mode").toString());

        if(doc.value("mode") == "Manual" || doc.value("satDataType") == "M"){
            ui->AzLcd->display(doc.value("Az").toString()+"'");
            ui->ElLcd->display(doc.value("El").toString()+"'");
        }else if (doc.value("mode") == "Automatic"){
            setSatToTrack(doc);
        }
    }
}

void MainWindow::setSatToTrack(const QJsonObject &doc){
    if(doc.value("satDataType") == "RP"){
        QDateTime UTC(QDateTime::currentDateTimeUtc());
        QDateTime myDateTime;

        if(doc.value("info")["passescount"].toInt() != 0){
            QString a = QString::number(doc.value("info")["satid"].toInt());
            QString b = doc.value("info")["satname"].toString();

            myDateTime.setTime_t(doc.value("passes")[0]["startUTC"].toInt());
            QString d = myDateTime.toString("ddd dd-MMM-yyyy hh:mm:ss");
            QString e = QString::number(doc.value("passes")[0]["startAz"].toDouble())+"°";
            myDateTime.setTime_t(doc.value("passes")[0]["maxUTC"].toInt());
            QString f = myDateTime.toString("ddd dd-MMM-yyyy hh:mm:ss");
            QString g = QString::number(doc.value("passes")[0]["maxAz"].toDouble())+"°";
            QString h = QString::number(doc.value("passes")[0]["maxEl"].toDouble())+"°";
            QString i = QString::number(doc.value("passes")[0]["endAz"].toDouble())+"°";
            myDateTime.setTime_t(doc.value("passes")[0]["endUTC"].toInt());
            QString j = myDateTime.toString("ddd dd-MMM-yyyy hh:mm:ss");
            QString k = doc.value("passes")[0]["startAzCompass"].toString();
            QString l = doc.value("passes")[0]["maxAzCompass"].toString();
            QString m = doc.value("passes")[0]["endAzCompass"].toString();

            ui->trackingInfo->setPlainText("Scheduled to track satellite: "
                                           +b+" ["+a+"] starting at "
                                           +d+" (Az: "+e+"° & El: 0°)["+k+"], max at "+f+" (Az: "+g+"° & El: "+h+"°)["+l+"] and end at "+j+
                                           " (Az: "+i+"° & El: 0°)["+m+"] \n "
                                           );

            url = doc.value("url").toString();
            QThread *TimeKeeperThread = new QThread; // First thread
            TimeKeeperThread->start();

            TimeKeeperWorker *autoTrack = new TimeKeeperWorker(nullptr, url, doc.value("passes")[0]["startUTC"].toInt(), doc.value("passes")[0]["endUTC"].toInt());
            autoTrack->moveToThread(TimeKeeperThread);

        }
    }
}

void MainWindow::attemptConnection()
{
    // We ask the user for the address of the server, we use 127.0.0.1 (aka localhost) as default
//    const QString hostAddress = QInputDialog::getText(
//        this
//        , tr("Choose Server")
//            , tr("Server Address")
//            , QLineEdit::Normal
//        , QStringLiteral("127.0.0.1")
//        );
    QString hostAddress;
    QStringList hosts;
//    QComboBox *hostCombo(new QComboBox);
//    hostCombo->setEditable(true);
    // find out name of this machine
    QString name = QHostInfo::localHostName();
    if (!name.isEmpty()) {
        hosts.append(name);
        QString domain = QHostInfo::localDomainName();
        if (!domain.isEmpty())
            hosts.append(name + QChar('.') + domain);
    }
    if (name != QLatin1String("localhost"))
        hosts.append(QString("localhost"));
    // find out IP addresses of this machine
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // add non-localhost addresses
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (!ipAddressesList.at(i).isLoopback())
           hosts.append(ipAddressesList.at(i).toString());
    }
    // add localhost addresses
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i).isLoopback())
            hosts.append(ipAddressesList.at(i).toString());
    }

    CustomDialog dialog(hosts);

    if (dialog.exec() == QDialog::Accepted)
    {
        // take proper action here
        hostAddress = dialog.comboBox()->currentText();
    }

    if (hostAddress.isEmpty())
        return; // the user pressed cancel or typed nothing
    // disable the connect button to prevent the user clicking it again
    ui->connectButton->setEnabled(false);
    // tell the client to connect to the host using the port 1967
    m_TCPClient->connectToServer(QHostAddress(hostAddress), 1967);
}

void MainWindow::connectedToServer()
{
    // once we connected to the server we ask the user for what username they would like to use
    const QString newUsername = QInputDialog::getText(this, tr("Set Device Name"), tr("Device name"));
    if (newUsername.isEmpty()){
        // if the user clicked cancel or typed nothing, we just disconnect from the server
        return m_TCPClient->disconnectFromHost();
    }
    // try to login with the given username
    attemptLogin(newUsername);
}

void MainWindow::attemptLogin(const QString &userName)
{
    // use the client to attempt a log in with the given username
    m_TCPClient->login(userName);
}

void MainWindow::loggedIn()
{
    // once we successully log in we enable the ui to display and send messages
    ui->sendButton->setEnabled(true);
    ui->messageEdit->setEnabled(true);
//    ui->chatView->setEnabled(true);
    // clear the user name record
    m_lastUserName.clear();
    ui->clientView->setEnabled(true);

    QString x ="";
    ui->clientView->appendPlainText("Connected to Server" + x +'\n');
}

void MainWindow::loginFailed(const QString &reason)
{
    // the server rejected the login attempt
    // display the reason for the rejection in a message box
    QMessageBox::critical(this, tr("Error"), reason);
    // allow the user to retry, execute the same slot as when just connected
    connectedToServer();
}

void MainWindow::messageReceived(const QString &sender, const QString &text)
{
    // store the index of the new row to append to the model containing the messages
//    int newRow = m_chatModel->rowCount();
    // we display a line containing the username only if it's different from the last username we displayed
    if (m_lastUserName != sender) {
        // store the last displayed username
        m_lastUserName = sender;
        // create a bold default font
        QFont boldFont;
        boldFont.setBold(true);
        // insert 2 row, one for the message and one for the username
//        m_chatModel->insertRows(newRow, 2);
//        // store the username in the model
//        m_chatModel->setData(m_chatModel->index(newRow, 0), sender + ':');
//        // set the alignment for the username
//        m_chatModel->setData(m_chatModel->index(newRow, 0), int(Qt::AlignLeft | Qt::AlignVCenter), Qt::TextAlignmentRole);
//        // set the for the username
//        m_chatModel->setData(m_chatModel->index(newRow, 0), boldFont, Qt::FontRole);
//        ++newRow;

        ui->clientView->appendPlainText(sender + ":" + '\n' + text + '\n');
    } else {
        // insert a row for the message
 //       m_chatModel->insertRow(newRow);

        ui->clientView->appendPlainText(text + '\n');
    }
    // store the message in the model
//    m_chatModel->setData(m_chatModel->index(newRow, 0), text);
//    // set the alignment for the message
//    m_chatModel->setData(m_chatModel->index(newRow, 0), int(Qt::AlignLeft | Qt::AlignVCenter), Qt::TextAlignmentRole);
    // scroll the view to display the new message
//    ui->chatView->scrollToBottom();

}

void MainWindow::sendMessage()
{
    // we use the client to send the message that the user typed
    m_TCPClient->sendMessage(ui->messageEdit->text());
    // now we add the message to the list
    // store the index of the new row to append to the model containing the messages
//    const int newRow = m_chatModel->rowCount();
//    // insert a row for the message
//    m_chatModel->insertRow(newRow);
//    // store the message in the model
//    m_chatModel->setData(m_chatModel->index(newRow, 0), ui->messageEdit->text());
//    // set the alignment for the message
//    m_chatModel->setData(m_chatModel->index(newRow, 0), int(Qt::AlignRight | Qt::AlignVCenter), Qt::TextAlignmentRole);

    ui->clientView->appendPlainText(ui->messageEdit->text() + '\n');
    // clear the content of the message editor
    ui->messageEdit->clear();

    // scroll the view to display the new message
//    ui->chatView->scrollToBottom();
    // reset the last printed username
    m_lastUserName.clear();

}

void MainWindow::disconnectedFromServer()
{
    // if the client loses connection to the server
    // comunicate the event to the user via a message box
    QMessageBox::warning(this, tr("Disconnected"), tr("The host terminated the connection"));
    // disable the ui to send and display messages
    ui->sendButton->setEnabled(false);
    ui->messageEdit->setEnabled(false);
//    ui->chatView->setEnabled(false);
    // enable the button to connect to the server again
    ui->connectButton->setEnabled(true);
    // reset the last printed username
    m_lastUserName.clear();
    ui->clientView->setEnabled(false);
}

void MainWindow::userJoined(const QString &username)
{
    // store the index of the new row to append to the model containing the messages
//    const int newRow = m_chatModel->rowCount();
//    // insert a row
//    m_chatModel->insertRow(newRow);
//    // store in the model the message to comunicate a user joined
//    m_chatModel->setData(m_chatModel->index(newRow, 0), tr("%1 Joined the Chat").arg(username));
//    // set the alignment for the text
//    m_chatModel->setData(m_chatModel->index(newRow, 0), Qt::AlignCenter, Qt::TextAlignmentRole);
//    // set the color for the text
//    m_chatModel->setData(m_chatModel->index(newRow, 0), QBrush(Qt::blue), Qt::ForegroundRole);
    // scroll the view to display the new message
//    ui->chatView->scrollToBottom();
    // reset the last printed username
    m_lastUserName.clear();

    ui->clientView->appendPlainText("\"" + username + "\" Joined the network" + '\n');
}
void MainWindow::userLeft(const QString &username)
{
    // store the index of the new row to append to the model containing the messages
//    const int newRow = m_chatModel->rowCount();
//    // insert a row
//    m_chatModel->insertRow(newRow);
//    // store in the model the message to comunicate a user left
//    m_chatModel->setData(m_chatModel->index(newRow, 0), tr("%1 Left the Chat").arg(username));
//    // set the alignment for the text
//    m_chatModel->setData(m_chatModel->index(newRow, 0), Qt::AlignCenter, Qt::TextAlignmentRole);
//    // set the color for the text
//    m_chatModel->setData(m_chatModel->index(newRow, 0), QBrush(Qt::red), Qt::ForegroundRole);
    // scroll the view to display the new message
//    ui->chatView->scrollToBottom();
    // reset the last printed username
    m_lastUserName.clear();

    ui->clientView->appendPlainText("\"" + username + "\" Left the network" + '\n');
}

void MainWindow::error(QAbstractSocket::SocketError socketError)
{
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
//    ui->chatView->setEnabled(false);
    // reset the last printed username
    m_lastUserName.clear();
}

