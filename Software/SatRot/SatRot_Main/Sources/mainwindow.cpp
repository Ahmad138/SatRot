#include "Headers/mainwindow.h"
#include "ui_mainwindow.h"
#include "Headers/blink.h"

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
    blink b;

    if(checked){
        b.ledOn();
        ui->ledStatus->setText("Led is ON");
    }else {
        b.ledOff();
        ui->ledStatus->setText("Led is OFF");
    }
}
