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

    QString url = "jsonplaceholder.typicode.com";
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


    QString url2 = "users/3";
    a->sendRequest(url2, getData, errData);

}

void MainWindow::on_webView_loadStarted()
{

}

void MainWindow::on_pushButton_2_clicked()
{
    QTcpSocket *socket = new QTcpSocket(this);

        connect(this,SIGNAL(newMessage(QString)),this,SLOT(displayMessage(QString)));
        connect(socket,SIGNAL(readyRead()),this,SLOT(readSocket()));
        connect(socket,SIGNAL(disconnected()),this,SLOT(discardSocket()));
        socket->connectToHost(QHostAddress::LocalHost,8080);
        if(socket->waitForConnected())
            this->ui->statusbar->showMessage("Connected to Server");
        else{
            QMessageBox::critical(this,"Connecting to Rotor", QString("The following error occurred: %1.").arg(socket->errorString()));
            //exit(EXIT_FAILURE);
        }
}
