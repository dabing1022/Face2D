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
    ../../../face2d_x/sources/face2d_x

LIBS += $${LINK_AGAINST_COCOS2DX}

SOURCES += main.cpp \
    Face2dCreator.cpp
HEADERS  += \
    Face2dCreator.h

SOURCES += ../sources/AppDelegate.cpp \
    ../sources/SimulatorConfig.cpp \
    ../../../face2d_x/sources/face2d_x/Face2dXAnimation.cpp \
    ../../../face2d_x/sources/face2d_x/Face2dXAnimManager.cpp \
    ../../../face2d_x/sources/face2d_x/Face2dXGrid.cpp \
    ../../../face2d_x/sources/face2d_x/Face2dXNode.cpp \
    ../../../face2d_x/sources/face2d_x/Face2dXTouchAnimation.cpp \
    ../../../face2d_x/sources/face2d_x/Face2dXUnit.cpp \
    ../../../face2d_x/sources/face2d_x/Face2dXUnitAnimation.cpp


HEADERS += ../sources/AppDelegate.h \
    ../sources/SimulatorConfig.h \
    ../../../face2d_x/sources/face2d_x/Face2dXAnimation.h \
    ../../../face2d_x/sources/face2d_x/Face2dXAnimManager.h \
    ../../../face2d_x/sources/face2d_x/Face2dXGrid.h \
    ../../../face2d_x/sources/face2d_x/Face2dXNode.h \
    ../../../face2d_x/sources/face2d_x/Face2dXTouchAnimation.h \
    ../../../face2d_x/sources/face2d_x/Face2dXUnit.h \
    ../../../face2d_x/sources/face2d_x/Face2dXUnitAnimation.h \
    ../../../face2d_x/sources/face2d_x/Face2dXTypes.h


FORMS    += \
    Face2dCreator.ui

#OTHER_FILES +=

DESTDIR = $${LIB_OUTPUT_DIR}
