#-------------------------------------------------
#
# Project created by QtCreator 2017-06-08T12:48:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Lab3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    graphtable.cpp \
    point.cpp \
    coordinateslist.cpp \
    drawwindow.cpp \
    calcthread.cpp \
    inputdata.cpp \
    progressevent.cpp

HEADERS  += mainwindow.h \
    graphtable.h \
    point.h \
    coordinateslist.h \
    drawwindow.h \
    calcthread.h \
    inputdata.h \
    progressevent.h

FORMS    += mainwindow.ui
