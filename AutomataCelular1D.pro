#-------------------------------------------------
#
# Project created by QtCreator 2016-09-05T10:10:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AutomataCelular1D
TEMPLATE = app
LIBS += -lGLU


SOURCES += main.cpp\
        mainwindow.cpp \
    automata.cpp \
    frecuencia.cpp \
    worker.cpp \
    universescanner.cpp

HEADERS  += mainwindow.h \
    automata.h \
    frecuencia.h \
    worker.h \
    universescanner.h

FORMS    += mainwindow.ui

DISTFILES +=

RESOURCES += \
    resources.qrc
