#-------------------------------------------------
#
# Project created by QtCreator 2016-04-03T01:23:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11
TARGET = micamera
TEMPLATE = app

INCLUDEPATH += /usr/local/include/

LIBS += -I/usr/local/include/ -lraspicam -lraspicam_cv -lopencv_core -lopencv_highgui

SOURCES += main.cpp\
    gui.cpp \
    micamera.cpp \
    cvrecognize.cpp

HEADERS  += \
    gui.h \
    micamera.h \
    cvrecognize.h

FORMS    += \
    gui.ui

CONFIG += link_pkgconfig
PKGCONFIG += opencv


OTHER_FILES +=
