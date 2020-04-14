#-------------------------------------------------
#
# Project created by QtCreator 2020-03-11T00:03:39
#
#-------------------------------------------------

QT += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = RotorDriver
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++14

# So wiringPi include files can be found during compile
INCLUDEPATH    += /usr/local/include

# To link the wiringPi library when making the executable
LIBS += -L/usr/local/lib -lwiringPi

SOURCES += \
        src/main.cpp \
        src/mainwindow.cpp \
    	src/tcpsockets.cpp \
	src/api.cpp \
        src/stepperdriver.cpp \
        src/raspgpio.cpp \
#        src/blink.cpp \
        src/helper.cpp \
	src/tcpclient.cpp \
	src/tcpserver.cpp \
        src/tcpthread.cpp \
        src/serverthread.cpp \
        src/clientthread.cpp \
        src/customdialog.cpp \
    src/timekeeperworker.cpp

HEADERS += \
        includes/mainwindow.h \
    	includes/tcpsockets.h \
	includes/api.h \
        includes/stepperdriver.h \
        includes/raspgpio.h \
#        includes/blink.h \
        includes/helper.h \
	includes/tcpclient.h \
	includes/tcpserver.h \
        includes/tcpthread.h \
        includes/serverthread.h \
        includes/clientthread.h \
        includes/customdialog.h \
        includes/CppThread.h \
    includes/timekeeperworker.h


FORMS += \
        forms/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
