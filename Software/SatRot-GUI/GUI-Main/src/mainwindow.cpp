#include "includes/mainwindow.h"
#include "ui_mainwindow.h"

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


    webView();

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

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    float val = value*0.05;
    QString s = QString::number(val);
    ui->Az->setText("Az: "+ s + "°");
}


void MainWindow::on_verticalSlider_valueChanged(int value)
{
    float val = value*0.05;
    QString s = QString::number(val);
    ui->El->setText("El: "+ s + "°");
}

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

void MainWindow::on_webView_loadStarted()
{

}

void MainWindow::on_pushButton_2_clicked()
{
    client.show();
}

void MainWindow::on_pushButton_3_clicked()
{
    if (!server.listen()) {
            QMessageBox::critical(this, tr("Rotator Serevr"),
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
                                "Run the SatRot Controller Software Client now.")
                             .arg(ipAddress).arg(server.serverPort()));
}


void MainWindow::on_getSatData_clicked()
{
    startDate = ui->startDateTime->dateTime().toString("yyyy-MM-dd_hh:mm:ss");
    stopDate = ui->stopDateTime->dateTime().toString("yyyy-MM-dd_hh:mm:ss");
    norad = this->model->getNORAD();

   QString urlCZML = "http://www.orbitalpredictor.com/api/predict_orbit/?sats="+norad+"&start="+startDate+"&end="+stopDate+"&format=czml&type=orbit";
   QString urln2yo = "";

   getCZML(urlCZML);
}

void MainWindow::on_checkBox_toggled(bool checked)
{
    if(checked){
        QDateTime now = QDateTime::currentDateTime();
        ui->startDateTime->setDateTime(now.currentDateTime());
        ui->stopDateTime->setDateTime(now.currentDateTime());
    }else{
//        QDateTime def_DateTime(QDate(2020, 01, 01), QTime(0, 0, 0));
//        ui->startDateTime->setDateTime(def_DateTime);
//        ui->stopDateTime->setDateTime(def_DateTime);
    }
}


void MainWindow::showTime()
{
    QDateTime now = QDateTime::currentDateTime();
    ui->myDateTime->setStyleSheet("font-weight: bold; font-size: 12pt;");
    ui->myDateTime->setText(now.toString("ddd dd-MMM-yyyy hh:mm:ss"));
}

void MainWindow::on_pushButton_5_clicked()
{
    double lat = ui->latBox->value();
    double lon = ui->longBox->value();
    QString latt = QString::number(lat,'f', 6);
    QString longg = QString::number(lon,'f', 6);

    latitude = latt;
    longitude = longg;

    ui->latBox->setValue(lat);
    ui->longBox->setValue(lon);
    ui->latTxT->setText("Lat: "+latt);
    ui->longTxT->setText("Long: "+longg);

    api *a = new api(this);

   QString url = "geocode.xyz/"+latt+","+longg+"?json=1";
   a->initRequester(url, 80, nullptr);

   api::handleFunc getData = [this](const QJsonObject &o) {
       //cout << "Got data " << endl;

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


void MainWindow::getCZML(QString endpoint)
{
    auto czml = new HttpWindow(this);

    czml->urlSpec = endpoint;
    czml->downloadFile();

    webView();

}

void MainWindow::webView(){
    view = new QWebEngineView(ui->widget);

    //view->resize(1024, 746);
    //const QRect availableSize = ui->frame->geometry();
    //view->resize(availableSize.width() * 15, availableSize.height() * 35);
    //view->setGeometry(ui->widget->geometry());

    qDebug()<< ui->groupBox->size();
//    view->setMaximumSize(ui->frame->size());
//    view->resize(ui->frame->size());
    //connect(view, &QWebEngineView::loadFinished, [this]() {this->ui->webView->resize(this->ui->frame->size());});

    view->load(QUrl("file:///home/ahmad/Documents/UofG/Semester 2/Real Time Embedded Programming/satRot/Software/SatRot-GUI/GUI-Main/third/index.html"));
    view->show();

}

void MainWindow::resizeEvent(QResizeEvent* event)
{
   QMainWindow::resizeEvent(event);
   // Your code here.
   //qDebug()<< ui->frame->size();
   view->resize(ui->widget->size());
}
