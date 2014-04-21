#ifndef MACROS_H
#define MACROS_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include <QString>
#include <QFileDialog>
#include <QSettings>
#include <QTextStream>
#include <QMessageBox>
#include <QDir>
#include <QDebug>
#include <QTreeWidgetItem>
#include <QHeaderView>
#include <QMenu>
#include <QContextMenuEvent>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QScrollBar>
#include <QDockWidget>
#include <QGridLayout>
#include <QWheelEvent>
#include <QWindow>
#include <QGLFunctions>
#include <QGLWidget>
#include <QImage>

using namespace std;

#define Shared(type) \
static type* getInstance()\
{\
    static type* __instance = null;\
    if(!__instance)\
    {\
        __instance = new type();\
    }\
    return __instance;\
}

#define null NULL

#endif // MACROS_H
