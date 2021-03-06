#-------------------------------------------------
#
# Project created by QtCreator 2020-02-15T12:46:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += multimedia

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
        src/gameover.cpp \
        src/settingsmenu.cpp \
        src/citylocation.cpp \
        src/archer.cpp \
        src/bullet.cpp \
        src/collisionrect.cpp \
        src/dialoglabel.cpp \
        src/dialogs_and_notes.cpp \
        src/door.cpp \
        src/enemy.cpp \
        src/environment.cpp \
        src/gameview.cpp \
        src/interactableobject.cpp \
        src/inventorylabel.cpp \
        src/locationbase.cpp \
        src/hpbar.cpp \
        src/main.cpp \
        src/mainmenu.cpp \
        src/movableentity.cpp \
        src/pickableobject.cpp \
        src/pixmapbutton.cpp \
        src/player.cpp \
        src/scene_base.cpp

HEADERS += \
        src/gameover.h \
        src/settingsmenu.h \
        src/citylocation.h \
        src/archer.h \
        src/bullet.h \
        src/collisionrect.h \
        src/dialoglabel.h \
        src/dialogs_and_notes.h \
        src/door.h \
        src/enemy.h \
        src/environment.h \
        src/gameview.h \
        src/interactableobject.h \
        src/inventorylabel.h \
        src/locationbase.h \
        src/hpbar.h \
        src/mainmenu.h \
        src/movableentity.h \
        src/pickableobject.h \
        src/pixmapbutton.h \
        src/player.h \
        src/scene_base.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res/res.qrc

