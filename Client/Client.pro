#-------------------------------------------------
#
# Project created by QtCreator 2016-05-12T17:27:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Client
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    seafield.cpp \
    shipplacement.cpp

HEADERS  += mainwindow.h \
    seafield.h \
    shipplacement.h

FORMS    += mainwindow.ui \
    shipplacement.ui

RESOURCES += \
    resource.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Game/release/ -lGame
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Game/debug/ -lGame
else:unix: LIBS += -L$$OUT_PWD/../Game/ -lGame

INCLUDEPATH += $$PWD/../Game
DEPENDPATH += $$PWD/../Game
