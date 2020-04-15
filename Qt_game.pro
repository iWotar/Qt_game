#-------------------------------------------------
#
# Project created by QtCreator 2020-02-15T12:46:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Qt_game
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

INCLUDEPATH += $$PWD/src
DEPENDPATH += $$PWD/src

SOURCES += \
        src/collisionrect.cpp \
        src/enemy.cpp \
        src/environment.cpp \
        src/gameview.cpp \
        src/main.cpp \
        src/mainmenu.cpp \
        src/movableentity.cpp \
        src/pixmapbutton.cpp \
        src/player.cpp \
        src/scene_base.cpp \
        src/widget.cpp

HEADERS += \
        src/collisionrect.h \
        src/enemy.h \
        src/environment.h \
        src/gameview.h \
        src/mainmenu.h \
        src/movableentity.h \
        src/pixmapbutton.h \
        src/player.h \
        src/scene_base.h \
        src/widget.h

FORMS += \
        src/widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res/res.qrc

