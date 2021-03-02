#-------------------------------------------------
#
# Project created by QtCreator 2021-02-08T10:46:43
#
#-------------------------------------------------

QT       += core gui
QT += opengl

LIBS += -lglut -lGLU -lm

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = glgl
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    paint_graph.cpp \
    bezier_curves.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    paint_graph.h \
    bezier_curves.h \
    func_common.h

#RESOURCES += \
#    ico.qrc

#RC_ICONS = 020817121245_0auto.ico
#RCC_DIR = /home/rd/glgl/ico


DISTFILES += \
    ico.rc
#    020817121245_0auto.ico

RC_FILE = ico.rc

RESOURCES += \
    ico/ico.qrc
