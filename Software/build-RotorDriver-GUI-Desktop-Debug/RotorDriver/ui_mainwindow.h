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
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionView;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QWidget *widget;
    QLabel *label;
    QPushButton *pushButton;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *statusbar;
    QGroupBox *groupBox_5;
    QGroupBox *groupBox_4;
    QLabel *logo;
    QMenuBar *menubar;
    QMenu *menu_File;
    QMenu *menu_View;
    QMenu *menu_Help;
    QMenu *menu_Edit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(700, 500);
        QIcon icon;
        icon.addFile(QStringLiteral("../../../../Documents/Images/Logo/SatRot logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionView = new QAction(MainWindow);
        actionView->setObjectName(QStringLiteral("actionView"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(800, 16777215));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));

        gridLayout->addWidget(groupBox_2, 0, 2, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        widget = new QWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(100, 300));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 70, 141, 51));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 140, 170, 51));

        gridLayout_5->addWidget(widget, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 2);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setMaximumSize(QSize(16777215, 350));
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        scrollArea = new QScrollArea(groupBox_3);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 309, 73));
        statusbar = new QLabel(scrollAreaWidgetContents);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        statusbar->setGeometry(QRect(90, 10, 151, 31));
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_4->addWidget(scrollArea, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_3, 2, 0, 1, 2);

        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));

        gridLayout->addWidget(groupBox_5, 0, 3, 1, 1);

        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        logo = new QLabel(groupBox_4);
        logo->setObjectName(QStringLiteral("logo"));
        logo->setGeometry(QRect(10, 90, 100, 198));
        logo->setPixmap(QPixmap(QString::fromUtf8("../res/img/SatRot logo2.png")));

        gridLayout->addWidget(groupBox_4, 2, 2, 1, 2);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 700, 28));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        menu_View = new QMenu(menubar);
        menu_View->setObjectName(QStringLiteral("menu_View"));
        menu_Help = new QMenu(menubar);
        menu_Help->setObjectName(QStringLiteral("menu_Help"));
        menu_Edit = new QMenu(menubar);
        menu_Edit->setObjectName(QStringLiteral("menu_Edit"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menu_File->menuAction());
        menubar->addAction(menu_Edit->menuAction());
        menubar->addAction(menu_View->menuAction());
        menubar->addAction(menu_Help->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "SatRot", nullptr));
        actionView->setText(QApplication::translate("MainWindow", "View", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "IMU Data Stream", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Current Rotor Position", nullptr));
        label->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Status Bar", nullptr));
        statusbar->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Radio Control", nullptr));
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
