#include "Headers/mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //api a;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_clickMe_clicked()
{
    ui->displayText->clear();
    ui->displayText->setText("Welcome to satrot everyone");
    //a.apiHello();
}

void MainWindow::on_radioButton_toggled(bool checked)
{
    //blink b;
    stepperDriver AzDriver(0, 1, 2, 3, 4, 5);

    helper hh;
    int i;
    if(checked){
        AzDriver.setDirection(CW);
        AzDriver.stepDegrees(90);
        //b.ledOn();
        //ui->ledStatus->setText("Led is ON");
        //AzDriver.setDirection(CW);
        //for(i = 0; i<360; i+=10){
            //AzDriver.stepDegrees(i);
            //hh.re_routeResources(10000);
        //}

    }else {
        AzDriver.setDirection(CCW);
        AzDriver.stepDegrees(180);
        //b.ledOff();
        //ui->ledStatus->setText("Led is OFF");
        //AzDriver.setDirection(CCW);
        //for(i = 360; i>0; i-=10){
         //   AzDriver.stepDegrees(i);
         //   hh.re_routeResources(10000);
       // }
    }
}
