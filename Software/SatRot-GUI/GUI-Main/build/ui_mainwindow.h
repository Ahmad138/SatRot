/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_7;
    QFrame *frame;
    QGridLayout *gridLayout_7;
    QWidget *widget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QPushButton *pushButton;
    QListView *chatView;
    QLabel *logo;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_5;
    QTabWidget *tabWidget_2;
    QWidget *tab_12;
    QGridLayout *gridLayout_22;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *myDateTime;
    QFrame *line_4;
    QGridLayout *gridLayout_11;
    QLabel *zone;
    QLabel *latTxT;
    QLabel *city;
    QLabel *longTxT;
    QLabel *country;
    QLabel *region;
    QWidget *tab_13;
    QGridLayout *gridLayout_23;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_8;
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
    QWidget *tab_4;
    QGridLayout *gridLayout_14;
    QTableView *tableViewPosition;
    QWidget *tab_5;
    QGridLayout *gridLayout_15;
    QTableView *tableViewVisualPass;
    QWidget *tab_6;
    QGridLayout *gridLayout_16;
    QTableView *tableViewRadioPass;
    QWidget *tab_7;
    QGridLayout *gridLayout_17;
    QTableView *tableViewTLE;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_6;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QGridLayout *gridLayout_9;
    QListView *satView;
    QGridLayout *gridLayout_6;
    QDateTimeEdit *stopDateTime;
    QLabel *label_3;
    QLabel *label_4;
    QDateTimeEdit *startDateTime;
    QFrame *line;
    QCheckBox *checkBox;
    QFrame *line_2;
    QLabel *label_2;
    QPushButton *getSatData;
    QFrame *line_3;
    QFrame *line_8;
    QWidget *tab_8;
    QGridLayout *gridLayout_12;
    QGridLayout *gridLayout_18;
    QLabel *msg;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *messageEdit;
    QPushButton *sendButton;
    QFrame *line_9;
    QPlainTextEdit *logEditor;
    QPushButton *connectButton;
    QPlainTextEdit *clientView;
    QLabel *label_11;
    QPushButton *startStopButton;
    QLabel *label_12;
    QWidget *tab;
    QGridLayout *gridLayout_13;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_7;
    QFrame *line_5;
    QComboBox *sat;
    QPushButton *sendTrack;
    QFrame *line_7;
    QLabel *label_9;
    QLabel *satDetails;
    QWidget *tab_2;
    QGridLayout *gridLayout_10;
    QGridLayout *gridLayout_21;
    QLabel *El;
    QLabel *Az;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_10;
    QSlider *horizontalSlider;
    QHBoxLayout *horizontalLayout_5;
    QSlider *verticalSlider;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *verticalSpacer;
    QWidget *tab_11;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1250, 750);
        MainWindow->setMinimumSize(QSize(0, 0));
        QIcon icon;
        icon.addFile(QStringLiteral("../../../../Documents/Images/Logo/SatRot logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(640, 330));
        groupBox->setMaximumSize(QSize(16777215, 16777215));
        groupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        verticalLayout_7 = new QVBoxLayout(groupBox);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(groupBox);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_7 = new QGridLayout(frame);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setContentsMargins(2, 0, 2, 2);
        widget = new QWidget(frame);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(768, 0));
        layoutWidget = new QWidget(widget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 30, 163, 112));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_4->addWidget(label);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_4->addWidget(pushButton);

        chatView = new QListView(widget);
        chatView->setObjectName(QStringLiteral("chatView"));
        chatView->setGeometry(QRect(230, 30, 171, 131));
        chatView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        logo = new QLabel(widget);
        logo->setObjectName(QStringLiteral("logo"));
        logo->setGeometry(QRect(470, 234, 100, 221));
        logo->setMinimumSize(QSize(0, 0));
        logo->setMaximumSize(QSize(110, 16777215));
        logo->setPixmap(QPixmap(QString::fromUtf8("../res/img/SatRot logo2.png")));

        gridLayout_7->addWidget(widget, 0, 0, 1, 1);


        verticalLayout_7->addWidget(frame);


        verticalLayout_6->addWidget(groupBox);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(0, 200));
        groupBox_3->setMaximumSize(QSize(16777215, 300));
        verticalLayout_5 = new QVBoxLayout(groupBox_3);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        tabWidget_2 = new QTabWidget(groupBox_3);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tab_12 = new QWidget();
        tab_12->setObjectName(QStringLiteral("tab_12"));
        gridLayout_22 = new QGridLayout(tab_12);
        gridLayout_22->setObjectName(QStringLiteral("gridLayout_22"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        myDateTime = new QLabel(tab_12);
        myDateTime->setObjectName(QStringLiteral("myDateTime"));
        myDateTime->setMaximumSize(QSize(16777215, 35));
        myDateTime->setTextFormat(Qt::AutoText);
        myDateTime->setAlignment(Qt::AlignCenter);
        myDateTime->setWordWrap(true);

        verticalLayout->addWidget(myDateTime);

        line_4 = new QFrame(tab_12);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_4);

        gridLayout_11 = new QGridLayout();
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        zone = new QLabel(tab_12);
        zone->setObjectName(QStringLiteral("zone"));
        zone->setWordWrap(true);

        gridLayout_11->addWidget(zone, 1, 1, 1, 1);

        latTxT = new QLabel(tab_12);
        latTxT->setObjectName(QStringLiteral("latTxT"));
        latTxT->setWordWrap(true);

        gridLayout_11->addWidget(latTxT, 2, 0, 1, 1);

        city = new QLabel(tab_12);
        city->setObjectName(QStringLiteral("city"));
        city->setWordWrap(true);

        gridLayout_11->addWidget(city, 0, 0, 1, 1);

        longTxT = new QLabel(tab_12);
        longTxT->setObjectName(QStringLiteral("longTxT"));
        longTxT->setWordWrap(true);

        gridLayout_11->addWidget(longTxT, 2, 1, 1, 1);

        country = new QLabel(tab_12);
        country->setObjectName(QStringLiteral("country"));
        country->setWordWrap(true);

        gridLayout_11->addWidget(country, 1, 0, 1, 1);

        region = new QLabel(tab_12);
        region->setObjectName(QStringLiteral("region"));
        region->setWordWrap(true);

        gridLayout_11->addWidget(region, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_11);


        horizontalLayout_3->addLayout(verticalLayout);


        gridLayout_22->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        tabWidget_2->addTab(tab_12, QString());
        tab_13 = new QWidget();
        tab_13->setObjectName(QStringLiteral("tab_13"));
        gridLayout_23 = new QGridLayout(tab_13);
        gridLayout_23->setObjectName(QStringLiteral("gridLayout_23"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_8 = new QLabel(tab_13);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMaximumSize(QSize(16777215, 40));
        label_8->setAlignment(Qt::AlignCenter);
        label_8->setWordWrap(true);

        verticalLayout_2->addWidget(label_8);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_5 = new QLabel(tab_13);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(16777215, 40));

        horizontalLayout->addWidget(label_5);

        latBox = new QDoubleSpinBox(tab_13);
        latBox->setObjectName(QStringLiteral("latBox"));
        latBox->setMaximumSize(QSize(16777215, 35));
        latBox->setWrapping(true);
        latBox->setDecimals(6);
        latBox->setMinimum(-180);
        latBox->setMaximum(180);
        latBox->setSingleStep(1e-6);

        horizontalLayout->addWidget(latBox);

        horizontalSpacer_2 = new QSpacerItem(50, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_6 = new QLabel(tab_13);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMaximumSize(QSize(16777215, 40));

        horizontalLayout->addWidget(label_6);

        longBox = new QDoubleSpinBox(tab_13);
        longBox->setObjectName(QStringLiteral("longBox"));
        longBox->setMaximumSize(QSize(16777215, 35));
        longBox->setDecimals(6);
        longBox->setMinimum(-180);
        longBox->setMaximum(180);
        longBox->setSingleStep(1e-6);

        horizontalLayout->addWidget(longBox);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_5 = new QPushButton(tab_13);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setMaximumSize(QSize(16777215, 40));

        horizontalLayout_2->addWidget(pushButton_5);

        horizontalSpacer = new QSpacerItem(30, 5, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_6 = new QPushButton(tab_13);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setMaximumSize(QSize(16777215, 40));

        horizontalLayout_2->addWidget(pushButton_6);


        verticalLayout_2->addLayout(horizontalLayout_2);


        gridLayout_23->addLayout(verticalLayout_2, 0, 0, 1, 1);

        tabWidget_2->addTab(tab_13, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        gridLayout_14 = new QGridLayout(tab_4);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        gridLayout_14->setContentsMargins(2, 2, 2, 2);
        tableViewPosition = new QTableView(tab_4);
        tableViewPosition->setObjectName(QStringLiteral("tableViewPosition"));

        gridLayout_14->addWidget(tableViewPosition, 0, 0, 1, 1);

        tabWidget_2->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        gridLayout_15 = new QGridLayout(tab_5);
        gridLayout_15->setObjectName(QStringLiteral("gridLayout_15"));
        gridLayout_15->setContentsMargins(2, 2, 2, 2);
        tableViewVisualPass = new QTableView(tab_5);
        tableViewVisualPass->setObjectName(QStringLiteral("tableViewVisualPass"));

        gridLayout_15->addWidget(tableViewVisualPass, 0, 0, 1, 1);

        tabWidget_2->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        gridLayout_16 = new QGridLayout(tab_6);
        gridLayout_16->setObjectName(QStringLiteral("gridLayout_16"));
        gridLayout_16->setContentsMargins(2, 2, 2, 2);
        tableViewRadioPass = new QTableView(tab_6);
        tableViewRadioPass->setObjectName(QStringLiteral("tableViewRadioPass"));

        gridLayout_16->addWidget(tableViewRadioPass, 0, 0, 1, 1);

        tabWidget_2->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        gridLayout_17 = new QGridLayout(tab_7);
        gridLayout_17->setObjectName(QStringLiteral("gridLayout_17"));
        gridLayout_17->setContentsMargins(2, 2, 2, 2);
        tableViewTLE = new QTableView(tab_7);
        tableViewTLE->setObjectName(QStringLiteral("tableViewTLE"));

        gridLayout_17->addWidget(tableViewTLE, 0, 0, 1, 1);

        tabWidget_2->addTab(tab_7, QString());

        verticalLayout_5->addWidget(tabWidget_2);


        verticalLayout_6->addWidget(groupBox_3);


        horizontalLayout_8->addLayout(verticalLayout_6);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(0, 630));
        groupBox_2->setMaximumSize(QSize(640, 16777215));
        horizontalLayout_6 = new QHBoxLayout(groupBox_2);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(groupBox_2);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMaximumSize(QSize(16777215, 16777215));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_9 = new QGridLayout(tab_3);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_9->setContentsMargins(2, 2, 2, 2);
        satView = new QListView(tab_3);
        satView->setObjectName(QStringLiteral("satView"));

        gridLayout_9->addWidget(satView, 5, 0, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        stopDateTime = new QDateTimeEdit(tab_3);
        stopDateTime->setObjectName(QStringLiteral("stopDateTime"));
        stopDateTime->setDate(QDate(2020, 1, 1));

        gridLayout_6->addWidget(stopDateTime, 3, 1, 1, 1);

        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_6->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(tab_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_6->addWidget(label_4, 2, 1, 1, 1);

        startDateTime = new QDateTimeEdit(tab_3);
        startDateTime->setObjectName(QStringLiteral("startDateTime"));
        startDateTime->setDate(QDate(2020, 1, 1));
        startDateTime->setCurrentSection(QDateTimeEdit::DaySection);

        gridLayout_6->addWidget(startDateTime, 3, 0, 1, 1);

        line = new QFrame(tab_3);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_6->addWidget(line, 0, 0, 1, 2);

        checkBox = new QCheckBox(tab_3);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout_6->addWidget(checkBox, 1, 0, 1, 1);


        gridLayout_9->addLayout(gridLayout_6, 2, 0, 1, 1);

        line_2 = new QFrame(tab_3);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_9->addWidget(line_2, 4, 0, 1, 1);

        label_2 = new QLabel(tab_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(0, 50));
        label_2->setWordWrap(true);

        gridLayout_9->addWidget(label_2, 1, 0, 1, 1);

        getSatData = new QPushButton(tab_3);
        getSatData->setObjectName(QStringLiteral("getSatData"));

        gridLayout_9->addWidget(getSatData, 7, 0, 1, 1);

        line_3 = new QFrame(tab_3);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_9->addWidget(line_3, 0, 0, 1, 1);

        line_8 = new QFrame(tab_3);
        line_8->setObjectName(QStringLiteral("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        gridLayout_9->addWidget(line_8, 6, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        gridLayout_12 = new QGridLayout(tab_8);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        gridLayout_12->setContentsMargins(2, 2, 2, 2);
        gridLayout_18 = new QGridLayout();
        gridLayout_18->setObjectName(QStringLiteral("gridLayout_18"));
        msg = new QLabel(tab_8);
        msg->setObjectName(QStringLiteral("msg"));
        msg->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        msg->setWordWrap(true);

        gridLayout_18->addWidget(msg, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        messageEdit = new QLineEdit(tab_8);
        messageEdit->setObjectName(QStringLiteral("messageEdit"));

        horizontalLayout_4->addWidget(messageEdit);

        sendButton = new QPushButton(tab_8);
        sendButton->setObjectName(QStringLiteral("sendButton"));

        horizontalLayout_4->addWidget(sendButton);


        gridLayout_18->addLayout(horizontalLayout_4, 8, 0, 1, 1);

        line_9 = new QFrame(tab_8);
        line_9->setObjectName(QStringLiteral("line_9"));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);

        gridLayout_18->addWidget(line_9, 4, 0, 1, 1);

        logEditor = new QPlainTextEdit(tab_8);
        logEditor->setObjectName(QStringLiteral("logEditor"));
        logEditor->setReadOnly(true);

        gridLayout_18->addWidget(logEditor, 3, 0, 1, 1);

        connectButton = new QPushButton(tab_8);
        connectButton->setObjectName(QStringLiteral("connectButton"));

        gridLayout_18->addWidget(connectButton, 5, 0, 1, 1);

        clientView = new QPlainTextEdit(tab_8);
        clientView->setObjectName(QStringLiteral("clientView"));
        clientView->setReadOnly(true);

        gridLayout_18->addWidget(clientView, 7, 0, 1, 1);

        label_11 = new QLabel(tab_8);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_18->addWidget(label_11, 2, 0, 1, 1);

        startStopButton = new QPushButton(tab_8);
        startStopButton->setObjectName(QStringLiteral("startStopButton"));

        gridLayout_18->addWidget(startStopButton, 1, 0, 1, 1);

        label_12 = new QLabel(tab_8);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_18->addWidget(label_12, 6, 0, 1, 1);


        gridLayout_12->addLayout(gridLayout_18, 0, 0, 1, 1);

        tabWidget->addTab(tab_8, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_13 = new QGridLayout(tab);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        gridLayout_13->setContentsMargins(2, 2, 2, 2);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_7 = new QLabel(tab);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMaximumSize(QSize(16777215, 40));
        label_7->setWordWrap(true);

        verticalLayout_3->addWidget(label_7);

        line_5 = new QFrame(tab);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_5);

        sat = new QComboBox(tab);
        sat->setObjectName(QStringLiteral("sat"));
        sat->setMaximumSize(QSize(16777215, 50));

        verticalLayout_3->addWidget(sat);

        sendTrack = new QPushButton(tab);
        sendTrack->setObjectName(QStringLiteral("sendTrack"));
        sendTrack->setEnabled(false);
        sendTrack->setMaximumSize(QSize(225, 50));
        sendTrack->setLayoutDirection(Qt::RightToLeft);

        verticalLayout_3->addWidget(sendTrack);

        line_7 = new QFrame(tab);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_7);

        label_9 = new QLabel(tab);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMinimumSize(QSize(0, 0));
        label_9->setMaximumSize(QSize(16777215, 40));
        label_9->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_9->setWordWrap(true);

        verticalLayout_3->addWidget(label_9);

        satDetails = new QLabel(tab);
        satDetails->setObjectName(QStringLiteral("satDetails"));
        satDetails->setMinimumSize(QSize(0, 200));
        satDetails->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_3->addWidget(satDetails);


        gridLayout_13->addLayout(verticalLayout_3, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_10 = new QGridLayout(tab_2);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        gridLayout_10->setContentsMargins(2, 2, 2, 2);
        gridLayout_21 = new QGridLayout();
        gridLayout_21->setObjectName(QStringLiteral("gridLayout_21"));
        El = new QLabel(tab_2);
        El->setObjectName(QStringLiteral("El"));
        El->setMinimumSize(QSize(40, 0));
        El->setWordWrap(true);

        gridLayout_21->addWidget(El, 0, 0, 1, 1);

        Az = new QLabel(tab_2);
        Az->setObjectName(QStringLiteral("Az"));
        Az->setAlignment(Qt::AlignCenter);

        gridLayout_21->addWidget(Az, 3, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(50, 0));

        horizontalLayout_7->addWidget(label_10);

        horizontalSlider = new QSlider(tab_2);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMaximum(7200);
        horizontalSlider->setSingleStep(1);
        horizontalSlider->setPageStep(4);
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(horizontalSlider);


        gridLayout_21->addLayout(horizontalLayout_7, 2, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalSlider = new QSlider(tab_2);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        verticalSlider->setMaximumSize(QSize(23, 500));
        verticalSlider->setMaximum(1800);
        verticalSlider->setOrientation(Qt::Vertical);

        horizontalLayout_5->addWidget(verticalSlider);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));

        horizontalLayout_5->addLayout(horizontalLayout_10);


        gridLayout_21->addLayout(horizontalLayout_5, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_21->addItem(verticalSpacer, 4, 0, 1, 1);


        gridLayout_10->addLayout(gridLayout_21, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_11 = new QWidget();
        tab_11->setObjectName(QStringLiteral("tab_11"));
        tabWidget->addTab(tab_11, QString());

        horizontalLayout_6->addWidget(tabWidget);


        horizontalLayout_8->addWidget(groupBox_2);


        gridLayout_2->addLayout(horizontalLayout_8, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1250, 50));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        tabWidget_2->setCurrentIndex(0);
        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "SatRot", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Map", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        logo->setText(QString());
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Satellite Details", Q_NULLPTR));
        myDateTime->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:9pt; font-weight:600;\">Current Local Date-Time</span></p></body></html>", Q_NULLPTR));
        zone->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">Zone:</span></p></body></html>", Q_NULLPTR));
        latTxT->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">Lat: </span></p></body></html>", Q_NULLPTR));
        city->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">City: </span></p></body></html>", Q_NULLPTR));
        longTxT->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">Long:</span></p></body></html>", Q_NULLPTR));
        country->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">Country:</span></p></body></html>", Q_NULLPTR));
        region->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">Region:</span></p></body></html>", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_12), QApplication::translate("MainWindow", "My Location", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">Set your Ground Station coordinates</span></p></body></html>", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">Lat</span></p></body></html>", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">Long</span></p></body></html>", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "Set Manually", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindow", "Set Automatically", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_13), QApplication::translate("MainWindow", "Set Location", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("MainWindow", "Position", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("MainWindow", "Visual Pass", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_6), QApplication::translate("MainWindow", "Radio Pass", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_7), QApplication::translate("MainWindow", "TLE", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Controls", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Stop", Q_NULLPTR));
        checkBox->setText(QApplication::translate("MainWindow", "Current datetime", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Checkbox satellite(s), set start and stop datetime and get the telemetry", Q_NULLPTR));
        getSatData->setText(QApplication::translate("MainWindow", "Get Satellite Telemetry", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Satellites", Q_NULLPTR));
        msg->setText(QApplication::translate("MainWindow", "Start a TCP Server or connect to a TCP Client Rotator.", Q_NULLPTR));
        sendButton->setText(QApplication::translate("MainWindow", "Send", Q_NULLPTR));
        connectButton->setText(QApplication::translate("MainWindow", "Connect to a TCP Client (rock)", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Server Log:", Q_NULLPTR));
        startStopButton->setText(QApplication::translate("MainWindow", "Start TCP Server", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "Client Log:", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_8), QApplication::translate("MainWindow", "Rotator", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Select a satellite to track and send", Q_NULLPTR));
        sendTrack->setText(QApplication::translate("MainWindow", "Send and Track", Q_NULLPTR));
        label_9->setText(QString());
        satDetails->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Automatic", Q_NULLPTR));
        El->setText(QApplication::translate("MainWindow", "El", Q_NULLPTR));
        Az->setText(QApplication::translate("MainWindow", "Az", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "0,0", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Manual", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_11), QApplication::translate("MainWindow", "Radio", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
