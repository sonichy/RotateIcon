QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RotateIconApp
TEMPLATE = app

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        item.cpp \
    rotateicon.cpp

HEADERS += \
        mainwindow.h \
    item.h \
    rotateicon.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    res.qrc