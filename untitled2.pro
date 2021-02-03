#-------------------------------------------------
#
# Project created by QtCreator 2021-02-01T17:22:35
#
#-------------------------------------------------

QT       += core gui
QT += opengl

LIBS += -lglut -lGLU

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp

HEADERS  += mainwindow.h \
    glwidget.h

FORMS    += mainwindow.ui
