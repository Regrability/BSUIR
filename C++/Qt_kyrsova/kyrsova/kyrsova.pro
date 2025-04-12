#-------------------------------------------------
#
# Project created by QtCreator 2025-01-19T19:25:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = kyrsova
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Book.cpp \
    Bookstore.cpp

HEADERS  += mainwindow.h \
    Book.h \
    Bookstore.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc
