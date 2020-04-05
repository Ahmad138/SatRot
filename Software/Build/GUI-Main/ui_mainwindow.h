/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
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
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QGridLayout *gridLayout_9;
    QLabel *label_2;
    QFrame *line_2;
    QListView *satView;
    QGridLayout *gridLayout_6;
    QLabel *label_4;
    QDateTimeEdit *stopDateTime;
    QLabel *label_3;
    QDateTimeEdit *startDateTime;
    QCheckBox *checkBox;
    QFrame *line;
    QPushButton *getSatData;
    QFrame *line_3;
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
    QGridLayout *gridLayout_8;
    QFrame *frame_2;
    QGridLayout *gridLayout_10;
    QHBoxLayout *horizontalLayout_3;
    QLabel *logo;
    QFrame *line_7;
    QVBoxLayout *verticalLayout;
    QLabel *myDateTime;
    QFrame *line_4;
    QLabel *label_8;
    QFrame *line_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QDoubleSpinBox *latBox;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_6;
    QDoubleSpinBox *longBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_6;
    QFrame *line_6;
    QGridLayout *gridLayout_11;
    QLabel *city;
    QLabel *region;
    QLabel *country;
    QLabel *zone;
    QLabel *latTxT;
    QLabel *longTxT;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QTabWidget *tabWidget_2;
    QWidget *tab_4;
    QWidget *tab_5;
    QWidget *tab_6;
    QWidget *tab_7;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QFrame *frame;
    QGridLayout *gridLayout_7;
    QWidget *widget;
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
        MainWindow->resize(2027, 1124);
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
        gridLayout_9 = new QGridLayout(tab_3);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        label_2 = new QLabel(tab_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(0, 50));
        label_2->setWordWrap(true);

        gridLayout_9->addWidget(label_2, 1, 0, 1, 1);

        line_2 = new QFrame(tab_3);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_9->addWidget(line_2, 4, 0, 1, 1);

        satView = new QListView(tab_3);
        satView->setObjectName(QString::fromUtf8("satView"));

        gridLayout_9->addWidget(satView, 5, 0, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_4 = new QLabel(tab_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_6->addWidget(label_4, 1, 1, 1, 1);

        stopDateTime = new QDateTimeEdit(tab_3);
        stopDateTime->setObjectName(QString::fromUtf8("stopDateTime"));
        stopDateTime->setDate(QDate(2020, 1, 1));

        gridLayout_6->addWidget(stopDateTime, 2, 1, 1, 1);

        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_6->addWidget(label_3, 1, 0, 1, 1);

        startDateTime = new QDateTimeEdit(tab_3);
        startDateTime->setObjectName(QString::fromUtf8("startDateTime"));
        startDateTime->setDate(QDate(2020, 1, 1));
        startDateTime->setCurrentSection(QDateTimeEdit::DaySection);

        gridLayout_6->addWidget(startDateTime, 2, 0, 1, 1);

        checkBox = new QCheckBox(tab_3);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        gridLayout_6->addWidget(checkBox, 3, 0, 1, 1);

        line = new QFrame(tab_3);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_6->addWidget(line, 0, 0, 1, 2);


        gridLayout_9->addLayout(gridLayout_6, 2, 0, 1, 1);

        getSatData = new QPushButton(tab_3);
        getSatData->setObjectName(QString::fromUtf8("getSatData"));

        gridLayout_9->addWidget(getSatData, 3, 0, 1, 1);

        line_3 = new QFrame(tab_3);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_9->addWidget(line_3, 0, 0, 1, 1);

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
        gridLayout_8 = new QGridLayout(groupBox_4);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        frame_2 = new QFrame(groupBox_4);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_10 = new QGridLayout(frame_2);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        logo = new QLabel(frame_2);
        logo->setObjectName(QString::fromUtf8("logo"));
        logo->setMinimumSize(QSize(0, 0));
        logo->setMaximumSize(QSize(110, 16777215));
        logo->setPixmap(QPixmap(QString::fromUtf8("../res/img/SatRot logo2.png")));

        horizontalLayout_3->addWidget(logo);

        line_7 = new QFrame(frame_2);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_7);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        myDateTime = new QLabel(frame_2);
        myDateTime->setObjectName(QString::fromUtf8("myDateTime"));
        myDateTime->setTextFormat(Qt::AutoText);
        myDateTime->setAlignment(Qt::AlignCenter);
        myDateTime->setWordWrap(true);

        verticalLayout->addWidget(myDateTime);

        line_4 = new QFrame(frame_2);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_4);

        label_8 = new QLabel(frame_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_8);

        line_5 = new QFrame(frame_2);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout->addWidget(label_5);

        latBox = new QDoubleSpinBox(frame_2);
        latBox->setObjectName(QString::fromUtf8("latBox"));
        latBox->setDecimals(6);
        latBox->setMinimum(-180.000000000000000);
        latBox->setMaximum(180.000000000000000);
        latBox->setSingleStep(0.000001000000000);

        horizontalLayout->addWidget(latBox);

        horizontalSpacer_2 = new QSpacerItem(50, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout->addWidget(label_6);

        longBox = new QDoubleSpinBox(frame_2);
        longBox->setObjectName(QString::fromUtf8("longBox"));
        longBox->setDecimals(6);
        longBox->setMinimum(-180.000000000000000);
        longBox->setMaximum(180.000000000000000);
        longBox->setSingleStep(0.000001000000000);

        horizontalLayout->addWidget(longBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_5 = new QPushButton(frame_2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        horizontalLayout_2->addWidget(pushButton_5);

        horizontalSpacer = new QSpacerItem(50, 5, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_6 = new QPushButton(frame_2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        horizontalLayout_2->addWidget(pushButton_6);


        verticalLayout->addLayout(horizontalLayout_2);

        line_6 = new QFrame(frame_2);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_6);

        gridLayout_11 = new QGridLayout();
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        city = new QLabel(frame_2);
        city->setObjectName(QString::fromUtf8("city"));
        city->setWordWrap(true);

        gridLayout_11->addWidget(city, 0, 0, 1, 1);

        region = new QLabel(frame_2);
        region->setObjectName(QString::fromUtf8("region"));
        region->setWordWrap(true);

        gridLayout_11->addWidget(region, 0, 1, 1, 1);

        country = new QLabel(frame_2);
        country->setObjectName(QString::fromUtf8("country"));
        country->setWordWrap(true);

        gridLayout_11->addWidget(country, 1, 0, 1, 1);

        zone = new QLabel(frame_2);
        zone->setObjectName(QString::fromUtf8("zone"));
        zone->setWordWrap(true);

        gridLayout_11->addWidget(zone, 1, 1, 1, 1);

        latTxT = new QLabel(frame_2);
        latTxT->setObjectName(QString::fromUtf8("latTxT"));
        latTxT->setWordWrap(true);

        gridLayout_11->addWidget(latTxT, 2, 0, 1, 1);

        longTxT = new QLabel(frame_2);
        longTxT->setObjectName(QString::fromUtf8("longTxT"));
        longTxT->setWordWrap(true);

        gridLayout_11->addWidget(longTxT, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_11);


        horizontalLayout_3->addLayout(verticalLayout);


        gridLayout_10->addLayout(horizontalLayout_3, 0, 0, 1, 1);


        gridLayout_8->addWidget(frame_2, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_4, 2, 2, 1, 1);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMaximumSize(QSize(16777215, 500));
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
        groupBox->setMinimumSize(QSize(1280, 0));
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        frame = new QFrame(groupBox);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_7 = new QGridLayout(frame);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        widget = new QWidget(frame);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(1236, 509));

        gridLayout_7->addWidget(widget, 0, 0, 1, 1);


        gridLayout_5->addWidget(frame, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 2, 2);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 2027, 39));
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

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "SatRot", nullptr));
        actionView->setText(QApplication::translate("MainWindow", "View", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Controls", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Checkbox satellite(s), set start and stop datetime and get the telemetry", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Stop", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Start", nullptr));
        checkBox->setText(QApplication::translate("MainWindow", "Current datetime", nullptr));
        getSatData->setText(QApplication::translate("MainWindow", "Get Satellite Telemetry", nullptr));
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
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Ground Station", nullptr));
        logo->setText(QString());
        myDateTime->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600;\">Current Local Date-Time</span></p></body></html>", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Set your Ground Station coordinates", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Lat", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Long", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "Set Manually", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow", "Set Automatically", nullptr));
        city->setText(QApplication::translate("MainWindow", "City: ", nullptr));
        region->setText(QApplication::translate("MainWindow", "Region:", nullptr));
        country->setText(QApplication::translate("MainWindow", "Country:", nullptr));
        zone->setText(QApplication::translate("MainWindow", "Zone:", nullptr));
        latTxT->setText(QApplication::translate("MainWindow", "Lat: ", nullptr));
        longTxT->setText(QApplication::translate("MainWindow", "Long:", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Satellite Details", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("MainWindow", "Position", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("MainWindow", "Visual Pass", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_6), QApplication::translate("MainWindow", "Radio Pass", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_7), QApplication::translate("MainWindow", "TLE", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Map", nullptr));
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