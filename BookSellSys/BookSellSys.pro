#-------------------------------------------------
#
# Project created by QtCreator 2017-03-09T00:12:23
#
#-------------------------------------------------

QT       += core gui
QT+=sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BookSellSys
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    userform.cpp \
    cashier.cpp \
    manager.cpp \
    changepsw.cpp \
    salerec.cpp \
    purchaserec.cpp \
    selldb.cpp \
    datesearch.cpp

HEADERS  += mainwindow.h \
    userform.h \
    cashier.h \
    manager.h \
    changepsw.h \
    salerec.h \
    purchaserec.h \
    selldb.h \
    datesearch.h

FORMS    += mainwindow.ui \
    userform.ui \
    cashier.ui \
    manager.ui \
    changepsw.ui \
    salerec.ui \
    purchaserec.ui \
    datesearch.ui

DISTFILES +=
