#-------------------------------------------------
#
# Project created by QtCreator 2014-10-08T13:44:48
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HelloWorlds
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    charactertab.cpp \
    attributeform.cpp \
    abilityform.cpp \
    core.cpp \
    xml.cpp \
    latex.cpp

HEADERS  += mainwindow.h \
    charactertab.h \
    attributeform.h \
    abilityform.h \
    core.h \
    xml.h \
    latex.h

FORMS    += mainwindow.ui \
    charactertab.ui \
    attributeform.ui \
    abilityform.ui
