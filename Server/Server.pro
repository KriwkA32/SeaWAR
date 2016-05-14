#-------------------------------------------------
#
# Project created by QtCreator 2016-05-12T17:28:42
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Server
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    myserver.cpp

HEADERS  += mainwindow.h \
    myserver.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Game/release/ -lGame
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Game/debug/ -lGame
else:unix: LIBS += -L$$OUT_PWD/../Game/ -lGame

INCLUDEPATH += $$PWD/../Game
DEPENDPATH += $$PWD/../Game
