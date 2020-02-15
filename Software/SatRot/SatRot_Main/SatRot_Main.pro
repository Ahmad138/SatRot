#-------------------------------------------------
#
# Project created by QtCreator 2020-02-08T00:22:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SatRot_Main
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

CONFIG += c++11

# So wiringPi include files can be found during compile
INCLUDEPATH    += /usr/local/include

# To link the wiringPi library when making the executable
LIBS += -L/usr/local/lib -lwiringPi

SOURCES += \
        Sources/main.cpp \
        Sources/mainwindow.cpp \
        Sources/api.cpp \
        Sources/stepperdriver.cpp \
        Sources/raspgpio.cpp \
        Sources/blink.cpp \
        Sources/helper.cpp

HEADERS += \
        Headers/mainwindow.h \
        Headers/api.h \
        Headers/stepperdriver.h \
        Headers/raspgpio.h \
        Headers/blink.h \
        Headers/helper.h

FORMS += \
        Forms/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
