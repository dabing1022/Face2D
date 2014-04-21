#-------------------------------------------------
#
# Project created by QtCreator 2013-10-16T03:16:56
#
#-------------------------------------------------
cache()

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = quick-x-player
TEMPLATE = app

include(../../lib/proj.qt/quick-x-src.pri)

INCLUDEPATH += ../sources \
    ../../../face2d/sources/face2d

LIBS += $${LINK_AGAINST_COCOS2DX}

SOURCES += main.cpp \
    Face2dCreator.cpp
HEADERS  += \
    Face2dCreator.h

SOURCES += ../../../face2d/sources/AppDelegate.cpp \
    ../../../face2d/sources/SimulatorConfig.cpp \
    ../../../face2d/sources/face2d/Face2dAnimation.cpp \
    ../../../face2d/sources/face2d/Face2dAnimManager.cpp \
    ../../../face2d/sources/face2d/Face2dGrid.cpp \
    ../../../face2d/sources/face2d/Face2dNode.cpp \
    ../../../face2d/sources/face2d/Face2dTouchAnimation.cpp \
    ../../../face2d/sources/face2d/Face2dUnit.cpp \
    ../../../face2d/sources/face2d/Face2dUnitAnimation.cpp


HEADERS += ../../../face2d/sources/AppDelegate.h \
    ../../../face2d/sources/SimulatorConfig.h \
    ../../../face2d/sources/face2d/Face2dAnimation.h \
    ../../../face2d/sources/face2d/Face2dAnimManager.h \
    ../../../face2d/sources/face2d/Face2dGrid.h \
    ../../../face2d/sources/face2d/Face2dNode.h \
    ../../../face2d/sources/face2d/Face2dTouchAnimation.h \
    ../../../face2d/sources/face2d/Face2dUnit.h \
    ../../../face2d/sources/face2d/Face2dUnitAnimation.h \
    ../../../face2d/sources/face2d/Face2dTypes.h


FORMS    += \
    Face2dCreator.ui

#OTHER_FILES +=

DESTDIR = $${LIB_OUTPUT_DIR}
