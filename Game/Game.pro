#-------------------------------------------------
#
# Project created by QtCreator 2016-05-14T15:22:17
#
#-------------------------------------------------

QT       += core

TARGET = Game
TEMPLATE = lib

DEFINES += GAME_LIBRARY

SOURCES += game.cpp \
    field.cpp

HEADERS += game.h\
        game_global.h \
    field.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
