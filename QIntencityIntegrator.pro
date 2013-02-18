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
LIBS += -lboost_filesystem -lboost_system

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    IntencityIntegrator/IntensityIntegrator.h

FORMS    += mainwindow.ui
