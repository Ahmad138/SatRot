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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionView;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_8;
    QLabel *label_4;
    QLCDNumber *lcdNumber;
    QGridLayout *gridLayout_7;
    QLabel *label_5;
    QLCDNumber *lcdNumber_2;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QLabel *label_6;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_4;
    QPlainTextEdit *plainTextEdit_3;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_5;
    QListWidget *listWidget;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_6;
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_2;
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButton_2;
    QLabel *label_3;
    QPlainTextEdit *plainTextEdit_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton_3;
    QMenuBar *menubar;
    QMenu *menu_File;
    QMenu *menu_View;
    QMenu *menu_Help;
    QMenu *menu_Edit;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(660, 475);
        QIcon icon;
        icon.addFile(QStringLiteral("../../../../Documents/Images/Logo/SatRot logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionView = new QAction(MainWindow);
        actionView->setObjectName(QStringLiteral("actionView"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_8 = new QGridLayout();
        gridLayout_8->setSpacing(6);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_8->addWidget(label_4, 0, 0, 1, 1);

        lcdNumber = new QLCDNumber(groupBox);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));

        gridLayout_8->addWidget(lcdNumber, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_8, 0, 0, 1, 1);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setTextFormat(Qt::RichText);

        gridLayout_7->addWidget(label_5, 0, 0, 1, 1);

        lcdNumber_2 = new QLCDNumber(groupBox);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));

        gridLayout_7->addWidget(lcdNumber_2, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_7, 1, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setMaximumSize(QSize(16777215, 60));
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMaximumSize(QSize(16777215, 50));

        gridLayout_2->addWidget(label_6, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setMinimumSize(QSize(0, 0));
        groupBox_4->setMaximumSize(QSize(16777215, 200));
        gridLayout_4 = new QGridLayout(groupBox_4);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        plainTextEdit_3 = new QPlainTextEdit(groupBox_4);
        plainTextEdit_3->setObjectName(QStringLiteral("plainTextEdit_3"));
        plainTextEdit_3->setMinimumSize(QSize(200, 0));
        plainTextEdit_3->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_4->addWidget(plainTextEdit_3, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_4);


        horizontalLayout_4->addLayout(verticalLayout_2);

        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setMinimumSize(QSize(200, 400));
        groupBox_5->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_5 = new QGridLayout(groupBox_5);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(2, 9, 2, 2);
        listWidget = new QListWidget(groupBox_5);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setMinimumSize(QSize(200, 0));
        listWidget->setMaximumSize(QSize(16777215, 16777215));
        listWidget->setLayoutDirection(Qt::LeftToRight);
        listWidget->setWordWrap(true);

        gridLayout_5->addWidget(listWidget, 0, 0, 1, 1);


        horizontalLayout_4->addWidget(groupBox_5);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(200, 400));
        groupBox_2->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_6 = new QGridLayout(groupBox_2);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setWordWrap(true);

        gridLayout_6->addWidget(label, 0, 0, 1, 1);

        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_6->addWidget(pushButton, 1, 0, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_6->addWidget(label_2, 2, 0, 1, 1);

        plainTextEdit = new QPlainTextEdit(groupBox_2);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setReadOnly(true);

        gridLayout_6->addWidget(plainTextEdit, 3, 0, 1, 1);

        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_6->addWidget(pushButton_2, 4, 0, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_6->addWidget(label_3, 5, 0, 1, 1);

        plainTextEdit_2 = new QPlainTextEdit(groupBox_2);
        plainTextEdit_2->setObjectName(QStringLiteral("plainTextEdit_2"));
        plainTextEdit_2->setReadOnly(true);

        gridLayout_6->addWidget(plainTextEdit_2, 6, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(pushButton_3);


        gridLayout_6->addLayout(horizontalLayout, 7, 0, 1, 1);


        horizontalLayout_4->addWidget(groupBox_2);


        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 660, 28));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        menu_View = new QMenu(menubar);
        menu_View->setObjectName(QStringLiteral("menu_View"));
        menu_Help = new QMenu(menubar);
        menu_Help->setObjectName(QStringLiteral("menu_Help"));
        menu_Edit = new QMenu(menubar);
        menu_Edit->setObjectName(QStringLiteral("menu_Edit"));
        MainWindow->setMenuBar(menubar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

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
        groupBox->setTitle(QApplication::translate("MainWindow", "Rotor Position", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:20pt; font-weight:600;\">Az</span></p></body></html>", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:20pt; font-weight:600;\">El</span></p></body></html>", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Mode:", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Automatic", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Tracking Info", nullptr));
        plainTextEdit_3->setPlainText(QApplication::translate("MainWindow", "//when scheduled to track\n"
"Scheduled to track satellite blabla @ UTC 2nd May, 2020 04:34:20.\n"
"\n"
"//when tracking\n"
" currently tracking blabla.", nullptr));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "IMU", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "TCP", nullptr));
        label->setText(QApplication::translate("MainWindow", "Start a TCP Server or connect to a TCP Client Rotator.", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Start TCP Server", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Server Log:", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Connect to a TCP Client", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Client Log:", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "Send", nullptr));
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
