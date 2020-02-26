#-------------------------------------------------
#
# Project created by QtCreator 2018-10-12T11:58:46
#
#-------------------------------------------------

QT       += core gui concurrent

CONFIG +=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UIProject
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
        mainwindow.cpp \
    page1.cpp \
    page2.cpp \
    page3.cpp \
    setting.cpp \
    page4.cpp \
    facewindow.cpp \
    myfacerecognizer.cpp

HEADERS  += mainwindow.h \
    page1.h \
    page2.h \
    page3.h \
    setting.h \
    page4.h \
    facewindow.h \
    myfacerecognizer.h

FORMS    += mainwindow.ui \
    page1.ui \
    page2.ui \
    page3.ui \
    setting.ui \
    page4.ui \
    facewindow.ui

RESOURCES += \
    picture.qrc

LIBS += -lwiringPi

INCLUDEPATH +=/usr/local/include \
              /usr/include/opencv\
              /usr/include/opencv2


LIBS +=/usr/local/lib/*.so
