#include "includes/mainwindow.h"
#include "ui_mainwindow.h"

/**
 * @brief
 *
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);    

    //init Sliders
    ui->Az->setNum(0);
    ui->El->setNum(0);

    //init labels
    ui->Az->setText("Az: 0.00°");
    ui->El->setText("El: 0.00°");

    QImage logo("/home/ahmad/Documents/UofG/Semester 2/Real Time Embedded Programming/satRot/Software/SatRot-GUI/GUI-Main/res/img/SatRot logo2.png");
    ui->logo->setPixmap(QPixmap::fromImage(logo));

    ui->comboBox->addItems(sl.getList());

    tables();

    webView();

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

        //c.send();
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
 * @param value
 */
void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    float val = value*0.05;
    QString s = QString::number(val);
    ui->Az->setText("Az: "+ s + "°");
}


/**
 * @brief
 *
 * @param value
 */
void MainWindow::on_verticalSlider_valueChanged(int value)
{
    float val = value*0.05;
    QString s = QString::number(val);
    ui->El->setText("El: "+ s + "°");
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
void MainWindow::on_webView_loadStarted()
{

}

/**
 * @brief
 *
 */
void MainWindow::on_pushButton_2_clicked()
{
    client.show();
}

/**
 * @brief
 *
 */
void MainWindow::on_pushButton_3_clicked()
{
    if (!server.listen()) {
            QMessageBox::critical(this, tr("Rotator Server"),
                                  tr("Unable to start the server: %1.")
                                  .arg(server.errorString()));
        }

        QString ipAddress;
        QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
        // use the first non-localhost IPv4 address
        for (int i = 0; i < ipAddressesList.size(); ++i) {
            if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
                ipAddressesList.at(i).toIPv4Address()) {
                ipAddress = ipAddressesList.at(i).toString();
                break;
            }
        }
        // if we did not find one, use IPv4 localhost
        if (ipAddress.isEmpty())
            ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
        ui->msg->setText(tr("The server is running on\n\nIP: %1\nport: %2\n\n"
                                "Run the SatRot Controller Software Client now and connect.")
                             .arg(ipAddress).arg(server.serverPort()));
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

   api::handleFunc errData = [this](const QJsonObject &o) {
       //cout << "Error: connection dropped";
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

       api::handleFunc errData2 = [this](const QJsonObject &o) {
           //cout << "Error: connection dropped";
           QString r2 = "Error: connection dropped";
           qDebug()<< r2;
       };

       c->sendRequest(url2, getData2, errData2);

    };

   api::handleFunc errData = [this](const QJsonObject &o) {
       //cout << "Error: connection dropped";
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

   api::handleFunc errData = [this](const QJsonObject &o) {
       //cout << "Error: connection dropped";
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

   api::handleFunc errData = [this](const QJsonObject &o) {
       //cout << "Error: connection dropped";
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

   api::handleFunc errData = [this](const QJsonObject &o) {
       //cout << "Error: connection dropped";
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

   api::handleFunc errData = [this](const QJsonObject &o) {
       //cout << "Error: connection dropped";
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

    view->load(QUrl("file:///home/ahmad/Documents/UofG/Semester 2/Real Time Embedded Programming/satRot/Software/SatRot-GUI/GUI-Main/third/index.html"));
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
   // Your code here.
   view->resize(ui->widget->size());
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    qDebug()<<arg1;
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
}

void MainWindow::on_pushButton_4_clicked()
{
    //server.sendMsg(server.socketDescriptor(),"hello from the other side!!");

}
