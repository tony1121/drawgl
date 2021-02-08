#-------------------------------------------------
#
# Project created by QtCreator 2021-02-08T10:46:43
#
#-------------------------------------------------

QT       += core gui
QT += opengl

LIBS += -lglut -lGLU

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = glgl
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp

HEADERS  += mainwindow.h \
    glwidget.h
