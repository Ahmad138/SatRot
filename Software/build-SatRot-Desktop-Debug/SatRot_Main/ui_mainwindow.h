/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *clickMe;
    QLabel *displayText;
    QRadioButton *radioButton;
    QLabel *ledStatus;
    QSlider *azSlider;
    QSlider *elSlider;
    QProgressBar *progressBar;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1613, 1290);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        clickMe = new QPushButton(centralWidget);
        clickMe->setObjectName(QStringLiteral("clickMe"));
        clickMe->setGeometry(QRect(350, 100, 170, 48));
        displayText = new QLabel(centralWidget);
        displayText->setObjectName(QStringLiteral("displayText"));
        displayText->setGeometry(QRect(350, 50, 1000, 34));
        displayText->setWordWrap(true);
        radioButton = new QRadioButton(centralWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(360, 190, 251, 31));
        ledStatus = new QLabel(centralWidget);
        ledStatus->setObjectName(QStringLiteral("ledStatus"));
        ledStatus->setGeometry(QRect(410, 230, 141, 21));
        azSlider = new QSlider(centralWidget);
        azSlider->setObjectName(QStringLiteral("azSlider"));
        azSlider->setGeometry(QRect(450, 1040, 731, 111));
        azSlider->setOrientation(Qt::Horizontal);
        elSlider = new QSlider(centralWidget);
        elSlider->setObjectName(QStringLiteral("elSlider"));
        elSlider->setGeometry(QRect(279, 429, 81, 681));
        elSlider->setOrientation(Qt::Vertical);
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(560, 630, 771, 36));
        progressBar->setValue(24);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1613, 39));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(elSlider, SIGNAL(valueChanged(int)), progressBar, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "SatRot - Taking everyone to space", nullptr));
        clickMe->setText(QApplication::translate("MainWindow", "OK", nullptr));
        displayText->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        radioButton->setText(QApplication::translate("MainWindow", "Toggle to Blink", nullptr));
        ledStatus->setText(QApplication::translate("MainWindow", "Led Status", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
