#include <QApplication>
#include <QProcess>
#include <QDebug>
#include <QWidget>
#include <QWindow>

#include "cocos2d.h"
#include "AppDelegate.h"
#include "Face2dCreator.h"

int main(int argc, char *argv[])
{
    AppDelegate app(argc, argv);

    ProjectConfig projectConfig;
    // parse argv
    std::vector<std::string> args;
    for (int i = 1; i < argc; i++) {
        args.push_back(argv[i]);
    }
    projectConfig.parseCommandLine(args);

    cocos2d::CCEGLView *view = cocos2d::CCEGLView::sharedOpenGLView();
    view->setFrameSize(960,640);

    Face2dCreator m_window;
    m_window.show();
    if(!app.applicationDidFinishLaunching())
    {
        return 0;
    }
    return app.run();
}

