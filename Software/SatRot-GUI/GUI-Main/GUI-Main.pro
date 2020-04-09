QT += core gui
QT += network

QT += webenginewidgets
#QT += webkit
#QT += webkitwidgets

#requires(qtConfig(combobox))

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14


# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
#DEFINES += "DBOOST_COROUTINE_NO_DEPRECATION_WARNING"
#DEFINES += "DBOOST_ALL_DYN_LINK"

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# So -lboost_log_setup include files can be found during compile
#INCLUDEPATH    += /usr/include
#INCLUDEPATH    += "/usr/local/include"

# To link the -lboost_log_setup library when making the executable
#LIBS += -L/usr/lib -lrestclient-cpp

SOURCES += \
    src/api.cpp \
    src/clientthread.cpp \
    src/digitalclock.cpp \
    src/getgeolocation.cpp \
    src/httpwindow.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/positionmodel.cpp \
    src/radiopassmodel.cpp \
    src/satellitelist.cpp \
    src/serverthread.cpp \
    src/tcpc.cpp \
    src/tcps.cpp \
    src/tcpserver.cpp \
    src/tcpthread.cpp \
    src/tcpclient.cpp \
    src/testmodel.cpp \
    src/customlistmodel.cpp \
    src/tlemodel.cpp \
    src/visualpassmodel.cpp

HEADERS += \
    includes/api.h \
    includes/clientthread.h \
    includes/digitalclock.h \
    includes/getgeolocation.h \
    includes/httpwindow.h \
    includes/mainwindow.h \
    includes/positionmodel.h \
    includes/radiopassmodel.h \
    includes/satellitelist.h \
    includes/serverthread.h \
    includes/tcpc.h \
    includes/tcps.h \
    includes/tcpserver.h \
    includes/tcpthread.h \
    includes/tcpclient.h \
    includes/testmodel.h \
    includes/customlistmodel.h \
    includes/tlemodel.h \
    includes/visualpassmodel.h

FORMS += \
    forms/mainwindow.ui

TRANSLATIONS += \
    lang/GUI-Main_en_GB.ts


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
