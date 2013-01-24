#-------------------------------------------------
#
# Project created by QtCreator 2013-01-22T15:46:19
#
#-------------------------------------------------

QT       += core gui network

TARGET = FreelanceHelper
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    settings.cpp \
    currencyconverter.cpp \
    optionsdialog.cpp \
    json.cpp \
    uniqueapp.cpp \
    maintablemodel.cpp \
    workermonth.cpp

HEADERS  += mainwindow.h \
    settings.h \
    currencyconverter.h \
    optionsdialog.h \
    json.h \
    uniqueapp.h \
    maintablemodel.h \
    workermonth.h

FORMS    += mainwindow.ui \
    optionsdialog.ui

INCLUDEPATH += d:/dev/boost/boost-current
LIBS += -Ld:/dev/boost/boost-current/stage/lib
