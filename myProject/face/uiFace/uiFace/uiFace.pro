#-------------------------------------------------
#
# Project created by QtCreator 2019-03-11T19:44:55
#
#-------------------------------------------------

QT       += core gui concurrent

CONFIG +=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = uiFace
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        facewindow.cpp \
    facethread.cpp

HEADERS  += facewindow.h \
    facethread.h

FORMS    += facewindow.ui

INCLUDEPATH +=/usr/local/include \
              /usr/include/opencv\
              /usr/include/opencv2


LIBS +=/usr/local/lib/*.so
