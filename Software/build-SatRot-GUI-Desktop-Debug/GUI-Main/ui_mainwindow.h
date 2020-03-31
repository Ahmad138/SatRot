/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWebKitWidgets/QWebView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionView;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QTabWidget *tabWidget_2;
    QWidget *tab_4;
    QWidget *tab_5;
    QWidget *tab_6;
    QWidget *tab_7;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QWidget *widget;
    QGridLayout *gridLayout_6;
    QWebView *webView;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QWidget *tab_8;
    QPushButton *pushButton_2;
    QLabel *statusBar;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *msg;
    QWidget *tab;
    QPushButton *pushButton;
    QLabel *label;
    QWidget *tab_2;
    QSlider *horizontalSlider;
    QSlider *verticalSlider;
    QLabel *Az;
    QLabel *El;
    QGroupBox *groupBox_4;
    QLabel *logo;
    QMenuBar *menubar;
    QMenu *menu_File;
    QMenu *menu_View;
    QMenu *menu_Help;
    QMenu *menu_Edit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1813, 1124);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../Documents/Images/Logo/SatRot logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionView = new QAction(MainWindow);
        actionView->setObjectName(QString::fromUtf8("actionView"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMaximumSize(QSize(16777215, 350));
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        tabWidget_2 = new QTabWidget(groupBox_3);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tabWidget_2->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        tabWidget_2->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        tabWidget_2->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        tabWidget_2->addTab(tab_7, QString());

        gridLayout_4->addWidget(tabWidget_2, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_3, 2, 0, 1, 2);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        widget = new QWidget(groupBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_6 = new QGridLayout(widget);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        webView = new QWebView(widget);
        webView->setObjectName(QString::fromUtf8("webView"));
        webView->setUrl(QUrl(QString::fromUtf8("https://www.google.com/?gws_rd=ssl")));

        gridLayout_6->addWidget(webView, 0, 0, 1, 1);


        gridLayout_5->addWidget(widget, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 2);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(800, 16777215));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        tabWidget = new QTabWidget(groupBox_2);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMaximumSize(QSize(16777215, 16777215));
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tabWidget->addTab(tab_3, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QString::fromUtf8("tab_8"));
        pushButton_2 = new QPushButton(tab_8);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(70, 60, 170, 48));
        statusBar = new QLabel(tab_8);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setGeometry(QRect(330, 70, 129, 34));
        pushButton_3 = new QPushButton(tab_8);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(70, 190, 170, 48));
        pushButton_4 = new QPushButton(tab_8);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(80, 310, 170, 48));
        msg = new QLabel(tab_8);
        msg->setObjectName(QString::fromUtf8("msg"));
        msg->setGeometry(QRect(270, 210, 461, 331));
        tabWidget->addTab(tab_8, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(170, 220, 170, 48));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 150, 461, 34));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        horizontalSlider = new QSlider(tab_2);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(80, 480, 611, 41));
        horizontalSlider->setMaximum(7200);
        horizontalSlider->setSingleStep(1);
        horizontalSlider->setPageStep(4);
        horizontalSlider->setOrientation(Qt::Horizontal);
        verticalSlider = new QSlider(tab_2);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setGeometry(QRect(40, 20, 41, 461));
        verticalSlider->setMaximum(3600);
        verticalSlider->setOrientation(Qt::Vertical);
        Az = new QLabel(tab_2);
        Az->setObjectName(QString::fromUtf8("Az"));
        Az->setGeometry(QRect(250, 510, 271, 34));
        El = new QLabel(tab_2);
        El->setObjectName(QString::fromUtf8("El"));
        El->setGeometry(QRect(90, 200, 171, 34));
        tabWidget->addTab(tab_2, QString());

        gridLayout_3->addWidget(tabWidget, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_2, 0, 2, 1, 1);

        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        logo = new QLabel(groupBox_4);
        logo->setObjectName(QString::fromUtf8("logo"));
        logo->setGeometry(QRect(10, 60, 100, 198));
        logo->setPixmap(QPixmap(QString::fromUtf8("../res/img/SatRot logo2.png")));

        gridLayout->addWidget(groupBox_4, 2, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1813, 39));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        menu_View = new QMenu(menubar);
        menu_View->setObjectName(QString::fromUtf8("menu_View"));
        menu_Help = new QMenu(menubar);
        menu_Help->setObjectName(QString::fromUtf8("menu_Help"));
        menu_Edit = new QMenu(menubar);
        menu_Edit->setObjectName(QString::fromUtf8("menu_Edit"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu_File->menuAction());
        menubar->addAction(menu_Edit->menuAction());
        menubar->addAction(menu_View->menuAction());
        menubar->addAction(menu_Help->menuAction());

        retranslateUi(MainWindow);

        tabWidget_2->setCurrentIndex(0);
        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "SatRot", nullptr));
        actionView->setText(QApplication::translate("MainWindow", "View", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Satellite Details", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("MainWindow", "Position", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("MainWindow", "Visual Pass", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_6), QApplication::translate("MainWindow", "Radio Pass", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_7), QApplication::translate("MainWindow", "TLE", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Map", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Controls", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Satellites", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "client", nullptr));
        statusBar->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "server", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "send", nullptr));
        msg->setText(QApplication::translate("MainWindow", "msg", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_8), QApplication::translate("MainWindow", "Rotator", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        label->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Automatic", nullptr));
        Az->setText(QApplication::translate("MainWindow", "Az", nullptr));
        El->setText(QApplication::translate("MainWindow", "El", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Manual", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Home Base", nullptr));
        logo->setText(QString());
        menu_File->setTitle(QApplication::translate("MainWindow", "&File", nullptr));
        menu_View->setTitle(QApplication::translate("MainWindow", "&View", nullptr));
        menu_Help->setTitle(QApplication::translate("MainWindow", "&Help", nullptr));
        menu_Edit->setTitle(QApplication::translate("MainWindow", "&Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
