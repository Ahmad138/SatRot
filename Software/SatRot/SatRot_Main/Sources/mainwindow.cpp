#include "Headers/mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_clickMe_clicked()
{
    ui->displayText->clear();
    ui->displayText->setText("Welcome to satrot everyone");
}

void MainWindow::on_radioButton_toggled(bool checked)
{
    //blink b;
    stepperDriver AzDriver(0, 1, 2, 3, 4, 5);

    if(checked){
        //b.ledOn();
        //ui->ledStatus->setText("Led is ON");
        AzDriver.setDirection(CW);
        AzDriver.stepDegrees(360);
    }else {
        //b.ledOff();
        //ui->ledStatus->setText("Led is OFF");
        AzDriver.setDirection(CCW);
        AzDriver.stepDegrees(360);
    }
}
