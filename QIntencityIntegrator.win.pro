#-------------------------------------------------
#
# Project created by QtCreator 2013-02-18T21:49:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QIntencityIntegrator
TEMPLATE = app

QMAKE_CXXFLAGS += -std=gnu++11
INCLUDEPATH += C:\MinGW\msys\1.0\home\okada\boost_1_52_0
LIBS += -LC:\MinGW\lib \
    -LC:\MinGW\msys\1.0\home\okada\boost_1_52_0\stage\lib \
    -lboost_filesystem-mgw47-mt-sd-1_52 -lboost_date_time-mgw47-mt-sd-1_52 -lboost_iostreams-mgw47-mt-sd-1_52 \
    -lboost_serialization-mgw47-mt-sd-1_52 -lcrypto -lboost_thread-mgw47-mt-sd-1_52 -lpthread -lboost_system-mgw47-mt-sd-1_52
SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    IntencityIntegrator/IntensityIntegrator.h

FORMS    += mainwindow.ui
