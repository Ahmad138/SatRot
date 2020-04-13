#include "includes/mainwindow.h"
#include "ui_mainwindow.h"

/***********TCPClient***********/
#include <QStandardItemModel>
#include <QInputDialog>
#include <QMessageBox>
#include <QHostAddress>
/***********TCPClient***********/

//Manual Scribble
#include "includes/manualscribble.h"
#include <QColorDialog>
#include <QFileDialog>
#include <QImageWriter>
#include <QMenuBar>
#include <QCloseEvent>

/**
 * @brief
 *
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_TCPServer(new TCPServer(this)) // create the network server
    , m_TCPClient(new TCPClient(this)) // create the network client
    , m_chatModel(new QStandardItemModel(this)) // create the model to hold the messages
    , MScribble(new ManualScribble(this))
{
    ui->setupUi(this);

    QString downloadDirectory = QStandardPaths::writableLocation(QStandardPaths::TempLocation);

    if (downloadDirectory.isEmpty() || !QFileInfo(downloadDirectory).isDir())
        downloadDirectory = QDir::currentPath();
    downloadDirectoryPath = QDir::toNativeSeparators(downloadDirectory);

    QFile::copy(":/web/web/index.html" , downloadDirectoryPath+"/index.html");

    ui->statusbar->setEnabled(true);
    ui->statusbar->showMessage("Loading");

    createActions();
    createMenus();

    MScribble->setMinimumSize(500, 500);
    MScribble->setMaximumSize(500, 500);
    //
    ui->horizontalLayout_10->addWidget(MScribble);

    MScribble->openImage(radarFileName);

    //init Sliders
    ui->Az->setNum(0);
    ui->El->setNum(0);

    //init labels
    ui->Az->setText("Az: 0.00°");
    ui->El->setText("El: 0.00°");

    QImage logo(":/img/img/logo.png");
    ui->logo->setPixmap(QPixmap::fromImage(logo));

    ui->sat->addItems(sl.getList());

    tables();

    webView();

    //server function connections
    connect(ui->startStopButton, &QPushButton::clicked, this, &MainWindow::toggleStartServer);
    connect(m_TCPServer, &TCPServer::logMessage, this, &MainWindow::logMessage);

    //client function connections
    /***********TCPClient***********/
    ui->chatView->setModel(m_chatModel);
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

    //connect Calculated Manual angle to slot
    connect(MScribble, &ManualScribble::logAngles, this, &MainWindow::logAngles);

    // disable the ui to send and display messages
    ui->sendButton->setEnabled(false);
    ui->messageEdit->setEnabled(false);
    ui->chatView->setEnabled(false);
    // enable the button to connect to the server again
    ui->connectButton->setEnabled(true);
    // reset the last printed username
    m_lastUserName.clear();
    ui->clientView->setEnabled(false);
    /***********TCPClient***********/

    ui->latTxT->setStyleSheet("font-size: 9pt;");
    ui->longTxT->setStyleSheet("font-size: 9pt;");
    ui->city->setStyleSheet("font-size: 9pt;");
    ui->region->setStyleSheet("font-size: 9pt;");
    ui->country->setStyleSheet("font-size: 9pt;");
    ui->zone->setStyleSheet("font-size: 9pt;");

//    QWebEngineView *view = new QWebEngineView(parent);
//        view->load(QUrl("http://qt-project.org/"));
//        view->show();

//     using std::chrono::system_clock;
//     std::time_t tt = system_clock::to_time_t (system_clock::now());

//     struct std::tm * ptm = std::localtime(&tt);
//     std::cout << "Current time: " << std::put_time(ptm,"%X") << '\n';

//     std::cout << "Waiting for the next minute to begin...\n";
//     ++ptm->tm_min; ptm->tm_sec=0;
//     std::this_thread::sleep_until (system_clock::from_time_t (mktime(ptm)));

//     std::cout << std::put_time(ptm,"%X") << " reached!\n";

    //connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(on_pushButton_4_clicked()));

        ui->satView->setModel(model);
        model->setStringList(sl.getList());

//        QDateTime now = QDateTime::currentDateTime();
//        ui->myDateTime->setText(now.toString("ddd dd-MMM-yyyy hh:mm:ss"));

        QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
        timer->start(250);

//        showTime();
        on_pushButton_6_clicked();
        on_checkBox_toggled(true);

        connect(this, SIGNAL(valueChanged()), this, SLOT(updateTable()));

//        QDateTime UTC(QDateTime::currentDateTimeUtc());
//        //QDateTime local(UTC.toLocalTime());
//        qDebug()<<UTC.toSecsSinceEpoch();

        QTimer *timerT = new QTimer(this);
        connect(timerT, SIGNAL(timeout()), this, SLOT(tableTimer()));
        timerT->start(250);


}

/**
 * @brief
 *
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief
 *
 */
void MainWindow::on_pushButton_clicked()
{
     api *a = new api(this);

    QString url = "jsonplaceholder.typicode.com/users/3";
    a->initRequester(url, 80, nullptr);

    api::handleFunc getData = [this](const QJsonObject &o) {
        //cout << "Got data " << endl;
        QString r= o.value("company")["name"].toString();
        ui->label->setText(r);
     };

    api::handleFunc errData = [this](const QJsonObject &o) {
        //cout << "Error: connection dropped";
        QString r= o.value("company")["name"].toString();
        ui->label->setText("Error: connection dropped");
    };

    a->sendRequest(url, getData, errData);

}


/**
 * @brief
 *
 */
void MainWindow::on_getSatData_clicked()
{
    startDate = ui->startDateTime->dateTime().toString("yyyy-MM-dd_hh:mm:ss");
    stopDate = ui->stopDateTime->dateTime().toString("yyyy-MM-dd_hh:mm:ss");
    norad = this->model->getNORAD();
    noradL = this->model->getNORADObj();

   QString urlCZML = "http://www.orbitalpredictor.com/api/predict_orbit/?sats="+norad+"&start="+startDate+"&end="+stopDate+"&format=czml&type=orbit";
   QString urln2yo = "";

   getCZML(urlCZML);
   getSatDetails(noradL);

}

/**
 * @brief
 *
 * @param checked
 */
void MainWindow::on_checkBox_toggled(bool checked)
{
    if(checked){
        QDateTime now = QDateTime::currentDateTime();
        ui->startDateTime->setDateTime(now.currentDateTime());
        ui->stopDateTime->setDateTime(now.currentDateTime().addDays(1));
    }else{
//        QDateTime def_DateTime(QDate(2020, 01, 01), QTime(0, 0, 0));
//        ui->startDateTime->setDateTime(def_DateTime);
//        ui->stopDateTime->setDateTime(def_DateTime);
    }
}


/**
 * @brief
 *
 */
void MainWindow::showTime()
{
    QDateTime now = QDateTime::currentDateTime();
    ui->myDateTime->setStyleSheet("font-weight: bold; font-size: 9pt;");
    ui->myDateTime->setText(now.toString("ddd dd-MMM-yyyy hh:mm:ss"));
}

/**
 * @brief
 *
 */
void MainWindow::on_pushButton_5_clicked()
{
    double lat = ui->latBox->value();
    double lon = ui->longBox->value();
    QString latt = QString::number(lat,'f', 6);
    QString longg = QString::number(lon,'f', 6);

    latitude = latt;
    longitude = longg;

//    ui->latTxT->setStyleSheet("font-size: 9pt;");
//    ui->longTxT->setStyleSheet("font-size: 9pt;");

    ui->latBox->setValue(lat);
    ui->longBox->setValue(lon);
    ui->latTxT->setText("Lat: "+latt);
    ui->longTxT->setText("Long: "+longg);

    api *a = new api(this);

   QString url = "geocode.xyz/"+latt+","+longg+"?json=1";
   a->initRequester(url, 80, nullptr);

   api::handleFunc getData = [this](const QJsonObject &o) {
       //cout << "Got data " << endl;

//       ui->city->setStyleSheet("font-size: 9pt;");
//       ui->region->setStyleSheet("font-size: 9pt;");
//       ui->country->setStyleSheet("font-size: 9pt;");
//       ui->zone->setStyleSheet("font-size: 9pt;");

       ui->city->setText("City: "+o.value("city").toString());
       ui->region->setText("Region: "+o.value("region").toString());
       ui->country->setText("Country: "+o.value("country").toString());
       ui->zone->setText("Zone: "+o.value("timezone").toString());

    };

   api::handleFunc errData = [](const QJsonObject &o) {
       //cout << "Error: connection dropped";
       QJsonObject x = o;
       QString r = "Error: connection dropped";
       qDebug()<< r;
   };

   a->sendRequest(url, getData, errData);
}

/**
 * @brief
 *
 */
void MainWindow::on_pushButton_6_clicked()
{
    api *b = new api(this);

   QString url = "api.ipify.org?format=json";

   b->initRequester(url, 80, nullptr);

   api::handleFunc getData = [this](const QJsonObject &o) {
       //cout << "Got data " << endl;
       QString r= o.value("ip").toString();
       //std::cout<<r.toUtf8().constData();

       api *c = new api(this);
       QString url2 = "ip-api.com/json/"+r;
//       qDebug()<<url2;
       c->initRequester(url2, 80, nullptr);

       api::handleFunc getData2 = [this](const QJsonObject &o) {
           //cout << "Got data " << endl;
//           QString r2= o.value("city").toString();
           double lat = o.value("lat").toDouble();
           double lon = o.value("lon").toDouble();
           QString latt = QString::number(lat,'f', 6);
           QString longg = QString::number(lon,'f', 6);

           ui->city->setText("City: "+o.value("city").toString());
           ui->region->setText("Region: "+o.value("regionName").toString());
           ui->country->setText("Country: "+o.value("country").toString());
           ui->zone->setText("Zone: "+o.value("timezone").toString());

           ui->latBox->setValue(lat);
           ui->longBox->setValue(lon);
           ui->latTxT->setText("Lat: "+latt);
           ui->longTxT->setText("Long: "+longg);

           latitude = latt;
           longitude = longg;

//           qDebug()<< f;
//           ui->label_7->setText(r2);
        };

       api::handleFunc errData2 = [](const QJsonObject &o) {
           //cout << "Error: connection dropped";
           QJsonObject x = o;
           QString r2 = "Error: connection dropped";
           qDebug()<< r2;
       };

       c->sendRequest(url2, getData2, errData2);

    };

   api::handleFunc errData = [](const QJsonObject &o) {
       //cout << "Error: connection dropped";
       QJsonObject x = o;
       QString r = "Error: connection dropped";
       qDebug()<< r;
   };

   b->sendRequest(url, getData, errData);
}


/**
 * @brief
 *
 * @param endpoint
 */
void MainWindow::getCZML(QString endpoint)
{
    auto czml = new HttpWindow(this);

    czml->urlSpec = endpoint;
    czml->downloadFile();

    webView();

}

void MainWindow::getSatDetails(QList<QString> endpoint)
{
    QString var;

    positions.clear();
    clearTable();
    updateTable();

    foreach (var, endpoint) {
        getSatTLE(var);
        getSatPos(var);
        getSatVisPass(var);
        getSatRadPass(var);
    }

    emit valueChanged();
}

void MainWindow::getSatPos(QString endpoint)
{
   api *a = new api(this);

   QString url = "www.n2yo.com/rest/v1/satellite/positions/"+endpoint+"/"+latitude+"/"+longitude+"/"+alt+"/"+predictSecs+"/&apiKey="+apikey;
   //qDebug()<<url;
   a->initRequester(url, 80, nullptr);

   api::handleFunc getData = [this](const QJsonObject &o) {
       //cout << "Got data " << endl;
       positions.append(o);
       satPDetails = o;

       QString a = QString::number(o.value("info")["satid"].toInt());
       QString b = o.value("info")["satname"].toString();

       QString c = QString::number(o.value("positions")[0]["satlatitude"].toDouble());
       QString d = QString::number(o.value("positions")[0]["satlongitude"].toDouble());
       QString e = QString::number(o.value("positions")[0]["sataltitude"].toDouble());
       QString f = QString::number(o.value("positions")[0]["azimuth"].toDouble());
       QString g = QString::number(o.value("positions")[0]["elevation"].toDouble());
       QString h = QString::number(o.value("positions")[0]["ra"].toDouble());
       QString i = QString::number(o.value("positions")[0]["dec"].toDouble());
       QString j = QString::number(o.value("positions")[0]["timestamp"].toInt());

       tm_satidPos.append(a);
       tm_satnamePos.append(b);
       tm_satlatitude.append(c);
       tm_satlongitude.append(d);
       tm_sataltitude.append(e);
       tm_azimuth.append(f);
       tm_elevation.append(g);
       tm_ra.append(h);
       tm_dec.append(i);
       tm_timestamp.append(j);

       PositionM->addItem(a, b, c, d, e, f, g, h, i, j);

       emit valueChanged();
    };

   api::handleFunc errData = [](const QJsonObject &o) {
       //cout << "Error: connection dropped";
       QJsonObject x = o;
       QString r = "Error: connection dropped";
       qDebug()<< r;
   };

   a->sendRequest(url, getData, errData);

}

void MainWindow::getSatVisPass(QString endpoint)
{
    api *a = new api(this);

   QString url = "www.n2yo.com/rest/v1/satellite/visualpasses/"+endpoint+"/"+latitude+"/"+longitude+"/"+alt+"/"+fordays+"/"+leastSecs+"/&apiKey="+apikey;
    //qDebug()<<url;
   a->initRequester(url, 80, nullptr);

   api::handleFunc getData = [this](const QJsonObject &o) {
       //cout << "Got data " << endl;       
//       VisualPasses.append(o);

       QJsonArray z = o.value("passes").toArray();
       QDateTime UTC(QDateTime::currentDateTimeUtc());
       QString mag;
       QDateTime myDateTime;

       if(z.size() > 0){
           QString a = QString::number(o.value("info")["satid"].toInt());
           QString b = o.value("info")["satname"].toString();
           QString c = QString::number(o.value("info")["passescount"].toInt());

           for (int x = 0; x < z.size(); x++) {

               myDateTime.setTime_t(o.value("passes")[x]["startUTC"].toInt());
               QString d = myDateTime.toString("ddd dd-MMM-yyyy hh:mm:ss");
               QString e = QString::number(o.value("passes")[x]["startAz"].toDouble())+"°";
               QString f = QString::number(o.value("passes")[x]["startEl"].toDouble())+"°";
               myDateTime.setTime_t(o.value("passes")[x]["maxUTC"].toInt());
               QString g = myDateTime.toString("ddd dd-MMM-yyyy hh:mm:ss");
               QString h = QString::number(o.value("passes")[x]["maxAz"].toDouble())+"°";
               QString i = QString::number(o.value("passes")[x]["maxEl"].toDouble())+"°";
               myDateTime.setTime_t(o.value("passes")[x]["endUTC"].toInt());
               QString j = myDateTime.toString("ddd dd-MMM-yyyy hh:mm:ss");
               QString k = QString::number(o.value("passes")[x]["endAz"].toDouble())+"°";
               QString l = QString::number(o.value("passes")[x]["endEl"].toDouble())+"°";
               QString m = o.value("passes")[x]["startAzCompass"].toString();
               QString n = o.value("passes")[x]["maxAzCompass"].toString();
               QString p = o.value("passes")[x]["endAzCompass"].toString();

               if(o.value("passes")[x]["mag"].toDouble() == 100000){
                   mag = "N/A";
               }else{
                   mag = QString::number(o.value("passes")[x]["mag"].toDouble());
               }
               QString q = mag;
               QString r = QString::number(o.value("passes")[x]["duration"].toInt());

               tm_satidVP.append(a);
               tm_satnameVP.append(b);
               tm_passescount.append(c);
               tm_startUTC.append(d);
               tm_startAz.append(e);
               tm_startEl.append(f);
               tm_maxUTC.append(g);
               tm_maxAz.append(h);
               tm_maxEl.append(i);
               tm_endUTC.append(j);
               tm_endAz.append(k);
               tm_endEl.append(l);
               tm_startAzCompass.append(m);
               tm_maxAzCompass.append(n);
               tm_endAzCompass.append(p);
               tm_mag.append(q);
               tm_duration.append(r);

               //qDebug()<<tm_satidVP;
               VisualPassM->addItem(a, b, c, d, e, f, g, h, i, j, k, l, m, n, p, q, r);
               //emit valueChanged();
           }
       }

    };

   api::handleFunc errData = [](const QJsonObject &o) {
       //cout << "Error: connection dropped";
       QJsonObject x = o;
       QString r = "Error: connection dropped";
       qDebug()<< r;
   };

   a->sendRequest(url, getData, errData);

}

void MainWindow::getSatRadPass(QString endpoint)
{
    api *a = new api(this);

   QString url = "www.n2yo.com/rest/v1/satellite/radiopasses/"+endpoint+"/"+latitude+"/"+longitude+"/"+alt+"/"+fordays+"/"+leastEl+"/&apiKey="+apikey;
    //qDebug()<<url;
   a->initRequester(url, 80, nullptr);

   api::handleFunc getData = [this](const QJsonObject &o) {
       //cout << "Got data " << endl;
//        RadioPasses.append(o);

       QJsonArray z = o.value("passes").toArray();
       QDateTime UTC(QDateTime::currentDateTimeUtc());
       QString mag;
       QDateTime myDateTime;

       if(z.size() > 0){
           QString a = QString::number(o.value("info")["satid"].toInt());
           QString b = o.value("info")["satname"].toString();
           QString c = QString::number(o.value("info")["passescount"].toInt());

           for (int x = 0; x < z.size(); x++) {

               myDateTime.setTime_t(o.value("passes")[x]["startUTC"].toInt());
               QString d = myDateTime.toString("ddd dd-MMM-yyyy hh:mm:ss");
               QString e = QString::number(o.value("passes")[x]["startAz"].toDouble())+"°";
               myDateTime.setTime_t(o.value("pes")[x]["maxUTC"].toInt());
               QString f = myDateTime.toString("ddd dd-MMM-yyyy hh:mm:ss");
               QString g = QString::number(o.value("passes")[x]["maxAz"].toDouble())+"°";
               QString h = QString::number(o.value("passes")[x]["maxEl"].toDouble())+"°";
               QString i = QString::number(o.value("passes")[x]["endAz"].toDouble())+"°";
               myDateTime.setTime_t(o.value("passes")[x]["endUTC"].toInt());
               QString j = myDateTime.toString("ddd dd-MMM-yyyy hh:mm:ss");
               QString k = o.value("passes")[x]["startAzCompass"].toString();
               QString l = o.value("passes")[x]["maxAzCompass"].toString();
               QString m = o.value("passes")[x]["endAzCompass"].toString();

               tm_satidR.append(a);
               tm_satnameR.append(b);
               tm_passescountR.append(c);
               tm_startUTCR.append(d);
               tm_startAzR.append(e);
               tm_maxUTCR.append(f);
               tm_maxAzR.append(g);
               tm_maxElR.append(h);
               tm_endAzR.append(i);
               tm_endUTCR.append(j);
               tm_startAzCompassR.append(k);
               tm_maxAzCompassR.append(l);
               tm_endAzCompassR.append(m);

               RadioPassM->addItem(a, b, c, d, e, f, g, h, i, j, k, l, m);

    //        emit valueChanged();
           }
       }

    };

   api::handleFunc errData = [](const QJsonObject &o) {
       //cout << "Error: connection dropped";
       QJsonObject x = o;
       QString r = "Error: connection dropped";
       qDebug()<< r;
   };

   a->sendRequest(url, getData, errData);

}

void MainWindow::getSatTLE(QString endpoint)
{
    api *a = new api(this);

   QString url = "www.n2yo.com/rest/v1/satellite/tle/"+endpoint+"&apiKey="+apikey;
   a->initRequester(url, 80, nullptr);

   api::handleFunc getData = [this](const QJsonObject &o) {
       //cout << "Got data " << endl;

       QString a = QString::number(o.value("info")["satid"].toInt());
       QString b = o.value("info")["satname"].toString();
       QString c = o.value("tle").toString();

       tm_satid.append(a);
       tm_satname.append(b);
       tm_tle.append(c);

       TLEM->addItem(a, b, c);

       //emit valueChanged();

//       setValue(tm_tle);
    };

   api::handleFunc errData = [](const QJsonObject &o) {
       //cout << "Error: connection dropped";
       QJsonObject x = o;
       QString r = "Error: connection dropped";
       qDebug()<< r;
   };

   a->sendRequest(url, getData, errData);

}
/**
 * @brief
 *
 */
void MainWindow::webView(){
    view = new QWebEngineView(ui->widget);

    view->load(QUrl("file://"+downloadDirectoryPath+"/index.html"));
    view->show();
    view->resize(ui->widget->size());
}

/**
 * @brief
 *
 * @param event
 */
void MainWindow::resizeEvent(QResizeEvent* event)
{
   QMainWindow::resizeEvent(event);

   view->resize(ui->widget->size());
}

void MainWindow::on_sat_currentIndexChanged(const QString &arg1)
{
    if(arg1 != "Satellite Name - NORAD Id" && arg1 != "------------------------------------"){
        const std::string z = arg1.toStdString();

        unsigned first = z.find("[");
        unsigned last = z.find("]");
        const std::string str = z.substr (first+1,(last-1)-first);

        QString strNew = QString::fromStdString(str);

        //qDebug() << strNew;

        getSatTLE(strNew);
        getSatPos(strNew);
        getSatVisPass(strNew);
        getSatRadPass(strNew);

        emit valueChanged();
    }
}

void MainWindow::tables()
{
    // Connect model to table view:
    ui->tableViewPosition->setModel(PositionM);
    ui->tableViewVisualPass->setModel(VisualPassM);
    ui->tableViewRadioPass->setModel(RadioPassM);
    ui->tableViewTLE->setModel(TLEM);

    // Make table header visible and display table:
    ui->tableViewPosition->horizontalHeader()->setVisible(true);
    ui->tableViewVisualPass->horizontalHeader()->setVisible(true);
    ui->tableViewRadioPass->horizontalHeader()->setVisible(true);
    ui->tableViewTLE->horizontalHeader()->setVisible(true);

    ui->tableViewPosition->show();
    ui->tableViewVisualPass->show();
    ui->tableViewRadioPass->show();
    ui->tableViewTLE->show();
}

void MainWindow::updateTable()
{
    //update tle table data
    TLEM->populateData(tm_satid,
                       tm_satname,
                       tm_tle);

    //update Position table data
    PositionM->populateData(tm_satidPos,
                            tm_satnamePos,
                            tm_satlatitude,
                            tm_satlongitude,
                            tm_sataltitude,
                            tm_azimuth,
                            tm_elevation,
                            tm_ra,
                            tm_dec,
                            tm_timestamp);

    //update Visual Pass table data
    VisualPassM->populateData(tm_satidVP,
                              tm_satnameVP,
                              tm_passescount,
                              tm_startUTC,
                              tm_startAz,
                              tm_startEl,
                              tm_maxUTC,
                              tm_maxAz,
                              tm_maxEl,
                              tm_endUTC,
                              tm_endAz,
                              tm_endEl,
                              tm_startAzCompass,
                              tm_maxAzCompass,
                              tm_endAzCompass,
                              tm_mag,
                              tm_duration);

    //update Radio Pass table data
    RadioPassM->populateData(tm_satidR,
                             tm_satnameR,
                             tm_passescountR,
                             tm_startUTCR,
                             tm_startAzR,
                             tm_maxUTCR,
                             tm_maxAzR,
                             tm_maxElR,
                             tm_endAzR,
                             tm_endUTCR,
                             tm_startAzCompassR,
                             tm_maxAzCompassR,
                             tm_endAzCompassR);


    ui->tableViewTLE->viewport()->update();
    ui->tableViewPosition->viewport()->update();
    ui->tableViewVisualPass->viewport()->update();
    ui->tableViewRadioPass->viewport()->update();
//    ui->tableViewTLE->viewport()->repaint();

}

void MainWindow::clearTable()
{
    //clear tle table data
    tm_satid.clear();
    tm_satname.clear();
    tm_tle.clear();

    //clear position table data
    tm_satidPos.clear();
    tm_satnamePos.clear();
    tm_satlatitude.clear();
    tm_satlongitude.clear();
    tm_azimuth.clear();
    tm_elevation.clear();
    tm_ra.clear();
    tm_dec.clear();
    tm_timestamp.clear();

    //clear Visual Pass table data
    tm_satidVP.clear();
    tm_satnameVP.clear();
    tm_passescount.clear();
    tm_startUTC.clear();
    tm_startAz.clear();
    tm_startEl.clear();
    tm_maxUTC.clear();
    tm_maxAz.clear();
    tm_maxEl.clear();
    tm_endUTC.clear();
    tm_endAz.clear();
    tm_endEl.clear();
    tm_startAzCompass.clear();
    tm_maxAzCompass.clear();
    tm_endAzCompass.clear();
    tm_mag.clear();
    tm_duration.clear();

    //clear Radio Pass table data
    tm_satidR.clear();
    tm_satnameR.clear();
    tm_passescountR.clear();
    tm_startUTCR.clear();
    tm_startAzR.clear();
    tm_maxUTCR.clear();
    tm_maxAzR.clear();
    tm_maxElR.clear();
    tm_endAzR.clear();
    tm_endUTCR.clear();
    tm_startAzCompassR.clear();
    tm_maxAzCompassR.clear();
    tm_endAzCompassR.clear();
}

void MainWindow::setValue(QList<QString> value)
{
    if (value != m_value) {
        m_value = value;
        emit valueChanged();
    }
}

void MainWindow::tableTimer(){
    QJsonObject var;
    QJsonArray l;
    QDateTime UTC(QDateTime::currentDateTimeUtc());
    QDateTime myDateTime;

    tm_satidPos.clear();
    tm_satnamePos.clear();
    tm_satlatitude.clear();
    tm_satlongitude.clear();
    tm_sataltitude.clear();
    tm_azimuth.clear();
    tm_elevation.clear();
    tm_ra.clear();
    tm_dec.clear();
    tm_timestamp.clear();

    foreach (var, positions) {
        l = var.value("positions").toArray();

        for (int i = 1; i < l.size(); i++) {
            if(var.value("positions")[i]["timestamp"].toInt() == UTC.toSecsSinceEpoch()){

                QString a = QString::number(var.value("info")["satid"].toInt());
                QString b = var.value("info")["satname"].toString();

                QString c = QString::number(var.value("positions")[i]["satlatitude"].toDouble())+"°";
                QString d = QString::number(var.value("positions")[i]["satlongitude"].toDouble())+"°";
                QString e = QString::number(var.value("positions")[i]["sataltitude"].toDouble())+" Km";
                QString f = QString::number(var.value("positions")[i]["azimuth"].toDouble())+"°";
                QString g = QString::number(var.value("positions")[i]["elevation"].toDouble())+"°";
                QString h = QString::number(var.value("positions")[i]["ra"].toDouble())+"°";
                QString j = QString::number(var.value("positions")[i]["dec"].toDouble())+"°";

                myDateTime.setTime_t(var.value("positions")[i]["timestamp"].toInt());
                QString k = myDateTime.toString("ddd dd-MMM-yyyy hh:mm:ss");

                tm_satidPos.append(a);
                tm_satnamePos.append(b);
                tm_satlatitude.append(c);
                tm_satlongitude.append(d);
                tm_sataltitude.append(e);
                tm_azimuth.append(f);
                tm_elevation.append(g);
                tm_ra.append(h);
                tm_dec.append(j);
                tm_timestamp.append(k);

            }
        }
    }
    PositionM->populateData(tm_satidPos,
                            tm_satnamePos,
                            tm_satlatitude,
                            tm_satlongitude,
                            tm_sataltitude,
                            tm_azimuth,
                            tm_elevation,
                            tm_ra,
                            tm_dec,
                            tm_timestamp);
    //qDebug()<<tm_satidPos;
    ui->tableViewPosition->viewport()->update();

    if(!positions.isEmpty()){
        int lm = positions[0].value("positions").toArray().size();
        if(UTC.toSecsSinceEpoch() > (positions[0].value("positions")[lm-1]["timestamp"].toInt() + 0)){
            getSatDetails(noradL);
        }
    }
}

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

void MainWindow::clientInit(){

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
    ui->chatView->setEnabled(true);
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
    int newRow = m_chatModel->rowCount();
    // we display a line containing the username only if it's different from the last username we displayed
    if (m_lastUserName != sender) {
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

        ui->clientView->appendPlainText(sender + ":" + '\n' + text + '\n');
    } else {
        // insert a row for the message
        m_chatModel->insertRow(newRow);

        ui->clientView->appendPlainText(text + '\n');
    }
    // store the message in the model
    m_chatModel->setData(m_chatModel->index(newRow, 0), text);
    // set the alignment for the message
    m_chatModel->setData(m_chatModel->index(newRow, 0), int(Qt::AlignLeft | Qt::AlignVCenter), Qt::TextAlignmentRole);
    // scroll the view to display the new message
    ui->chatView->scrollToBottom();

}

void MainWindow::sendMessage()
{
    // we use the client to send the message that the user typed
    m_TCPClient->sendMessage(ui->messageEdit->text());
    // now we add the message to the list
    // store the index of the new row to append to the model containing the messages
    const int newRow = m_chatModel->rowCount();
    // insert a row for the message
    m_chatModel->insertRow(newRow);
    // store the message in the model
    m_chatModel->setData(m_chatModel->index(newRow, 0), ui->messageEdit->text());
    // set the alignment for the message
    m_chatModel->setData(m_chatModel->index(newRow, 0), int(Qt::AlignRight | Qt::AlignVCenter), Qt::TextAlignmentRole);

    ui->clientView->appendPlainText(ui->messageEdit->text() + '\n');
    // clear the content of the message editor
    ui->messageEdit->clear();

    // scroll the view to display the new message
    ui->chatView->scrollToBottom();
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
    ui->chatView->setEnabled(false);
    // enable the button to connect to the server again
    ui->connectButton->setEnabled(true);
    // reset the last printed username
    m_lastUserName.clear();
    ui->clientView->setEnabled(false);
}

void MainWindow::userJoined(const QString &username)
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
    // scroll the view to display the new message
    ui->chatView->scrollToBottom();
    // reset the last printed username
    m_lastUserName.clear();

    ui->clientView->appendPlainText("\"" + username + "\" Joined the network" + '\n');
}
void MainWindow::userLeft(const QString &username)
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
    // scroll the view to display the new message
    ui->chatView->scrollToBottom();
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
    ui->chatView->setEnabled(false);
    // reset the last printed username
    m_lastUserName.clear();
}

void MainWindow::on_sendTrack_clicked()
{
    //Mode of control, True if automatic and False if Manual
    m_TCPClient->sendTrackingDetails(satPDetails, "P", true);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (maybeSave())
        event->accept();
    else
        event->ignore();
}

void MainWindow::open()
{
    if (maybeSave()) {
        QString fileName = QFileDialog::getOpenFileName(this,
                                                        tr("Open File"), QDir::currentPath());
        if (!fileName.isEmpty())
            MScribble->openImage(fileName);
    }
}

void MainWindow::save()
{
    QAction *action = qobject_cast<QAction *>(sender());
    QByteArray fileFormat = action->data().toByteArray();
    saveFile(fileFormat);
}

void MainWindow::penColor()
{
    QColor newColor = QColorDialog::getColor(MScribble->penColor());
    if (newColor.isValid())
        MScribble->setPenColor(newColor);
}

void MainWindow::penWidth()
{
    bool ok;
    int newWidth = QInputDialog::getInt(this, tr("Manual Tracking"),
                                        tr("Select pen width:"),
                                        MScribble->penWidth(),
                                        1, 50, 1, &ok);
    if (ok)
        MScribble->setPenWidth(newWidth);
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About Satrot"),
                       tr("<p><b>Satrot</b> example shows how to use QMainWindow as the "
                          "base widget for an application, and how to reimplement some of "
                          "QWidget's event handlers to receive the events generated for "
                          "the application's widgets:</p><p> We reimplement the mouse event "
                          "handlers to facilitate drawing, the paint event handler to "
                          "update the application and the resize event handler to optimize "
                          "the application's appearance. In addition we reimplement the "
                          "close event handler to intercept the close events before "
                          "terminating the application.</p><p> The example also demonstrates "
                          "how to use QPainter to draw an image in real time, as well as "
                          "to repaint widgets.</p>"));
}

void MainWindow::documentation(){
    QMessageBox::information(this, tr("Satrot Documentation"),
                       tr("<p><b>Satrot</b> visit our gitub wiki page and website for full documantation."
                                "<a href=\"https://github.com/Ahmad138/SatRot/wiki\">Github Page</a>"
                                "<a href=\"#\">Website</a>"
                                ""
                                "</p>"));
}

void MainWindow::createActions()
{
//    openAct = new QAction(tr("&Open..."), this);
//    openAct->setShortcuts(QKeySequence::Open);
//    connect(openAct, &QAction::triggered, this, &MainWindow::open);

    const QList<QByteArray> imageFormats = QImageWriter::supportedImageFormats();
    for (const QByteArray &format : imageFormats) {
        QString text = tr("%1...").arg(QString::fromLatin1(format).toUpper());

        QAction *action = new QAction(text, this);
        action->setData(format);
        connect(action, &QAction::triggered, this, &MainWindow::save);
        saveAsActs.append(action);
    }

    printAct = new QAction(tr("&Print..."), this);
    connect(printAct, &QAction::triggered, MScribble, &ManualScribble::print);

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    connect(exitAct, &QAction::triggered, this, &MainWindow::close);

    penColorAct = new QAction(tr("&Pen Color..."), this);
    connect(penColorAct, &QAction::triggered, this, &MainWindow::penColor);

    penWidthAct = new QAction(tr("Pen &Width..."), this);
    connect(penWidthAct, &QAction::triggered, this, &MainWindow::penWidth);

    clearScreenAct = new QAction(tr("&Clear Screen"), this);
    clearScreenAct->setShortcut(tr("Ctrl+L"));
    connect(clearScreenAct, &QAction::triggered,
            this, &MainWindow::clearRadar);

    aboutAct = new QAction(tr("&About"), this);
    connect(aboutAct, &QAction::triggered, this, &MainWindow::about);

    documentationAct = new QAction(tr("&Documentation"), this);
    connect(documentationAct, &QAction::triggered, this, &MainWindow::documentation);

//    aboutQtAct = new QAction(tr("About &Qt"), this);
//    connect(aboutQtAct, &QAction::triggered, qApp, &QApplication::aboutQt);
}

void MainWindow::createMenus()

{
    saveAsMenu = new QMenu(tr("&Save As"), this);
    for (QAction *action : qAsConst(saveAsActs))
        saveAsMenu->addAction(action);

    fileMenu = new QMenu(tr("&File"), this);
    //fileMenu->addAction(openAct);
    fileMenu->addMenu(saveAsMenu);
    fileMenu->addAction(printAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    optionMenu = new QMenu(tr("&Options"), this);
    optionMenu->addAction(penColorAct);
    optionMenu->addAction(penWidthAct);
    optionMenu->addSeparator();
    optionMenu->addAction(clearScreenAct);

    helpMenu = new QMenu(tr("&Help"), this);
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(documentationAct);
    //helpMenu->addAction(aboutQtAct);

    menuBar()->addMenu(fileMenu);
    menuBar()->addMenu(optionMenu);
    menuBar()->addMenu(helpMenu);
}

bool MainWindow::maybeSave()
{
    if (MScribble->isModified()) {
        QMessageBox::StandardButton ret;
        ret = QMessageBox::warning(this, tr("SatRot"),
                                   tr("The image has been modified.\n"
                                      "Do you want to save your changes?"),
                                   QMessageBox::Save | QMessageBox::Discard
                                       | QMessageBox::Cancel);
        if (ret == QMessageBox::Save)
            return saveFile("png");
        else if (ret == QMessageBox::Cancel)
            return false;
    }
    return true;
}

bool MainWindow::saveFile(const QByteArray &fileFormat)
{
    QString initialPath = QDir::currentPath() + "/untitled." + fileFormat;

    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"),
                                                    initialPath,
                                                    tr("%1 Files (*.%2);;All Files (*)")
                                                        .arg(QString::fromLatin1(fileFormat.toUpper()))
                                                        .arg(QString::fromLatin1(fileFormat)));
    if (fileName.isEmpty())
        return false;
    return MScribble->saveImage(fileName, fileFormat.constData());
}

void MainWindow::clearRadar(){
    MScribble->clearImage();
    MScribble->openImage(radarFileName);
}

void MainWindow::logAngles(QMap<QString, double> &angles){
    //Az
    QString Az = QString::number(angles["Az"]);
    ui->Az->setText("Az: "+ Az + "°");
    ui->horizontalSlider->setValue(angles["Az"]/0.05);

    //El
    QString El = QString::number(angles["El"]);
    ui->El->setText("El: "+ El + "°");
    ui->verticalSlider->setValue(angles["El"]/0.05);

    AzEl["Az"] = Az;
    AzEl["El"] = El;
    m_TCPClient->sendTrackingDetails(AzEl, "M", false);
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    float val = position*0.05;
    QString s = QString::number(val);
    ui->Az->setText("Az: "+ s + "°");

    AzEl["Az"] = s;
    m_TCPClient->sendTrackingDetails(AzEl, "M", false);
}

void MainWindow::on_verticalSlider_sliderMoved(int position)
{
    float val = position*0.05;
    QString s = QString::number(val);
    ui->El->setText("El: "+ s + "°");

    AzEl["El"] = s;
    m_TCPClient->sendTrackingDetails(AzEl, "M", false);
}

