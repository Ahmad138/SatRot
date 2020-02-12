#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "Headers/blink.h"
#include "Headers/stepperdriver.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_clickMe_clicked();

    void on_radioButton_toggled(bool checked);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
