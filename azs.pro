#-------------------------------------------------
#
# Project created by QtCreator 2015-05-31T20:00:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = azs
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    driver.cpp \
    queue.cpp \
    azs.cpp \
    cashbox.cpp \
    manqueue.cpp

HEADERS  += mainwindow.h \
    driver.h \
    queue.h \
    azs.h \
    cashbox.h \
    manqueue.h

FORMS    += mainwindow.ui
