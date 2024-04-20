#-------------------------------------------------
#
# Project created by QtCreator 2024-03-11T16:38:48
#
#-------------------------------------------------
QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.15
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11, sdk_no_version_check

TARGET = ChoiceFile
TEMPLATE = app


SOURCES += main.cpp\
        dialogeditname.cpp \
        dialogpic.cpp \
        mainwindow.cpp \
        memberInfo.cpp

HEADERS  += mainwindow.h \
    dialogeditname.h \
    dialogpic.h \
    memberInfo.h

FORMS    += mainwindow.ui \
    dialogeditname.ui \
    dialogpic.ui

RESOURCES += \
    MyResource.qrc
