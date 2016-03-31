#-------------------------------------------------
#
# Project created by QtCreator 2016-03-29T12:51:08
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CommunicationTester
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    superlabel.cpp \
    core.cpp \
    tcpsocket.cpp

HEADERS  += mainwindow.h \
    superlabel.h \
    core.h \
    tcpsocket.h \
    include/SPLStandardMessage.h

FORMS    += mainwindow.ui

INCLUDEPATH += include/
