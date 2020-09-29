QT += testlib
QT += core gui
QT += network

QT += webenginewidgets
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_apitestcase.cpp \
    ../GUI-Main/src/api.cpp \

HEADERS += \
    ../GUI-Main/includes/api.h \
