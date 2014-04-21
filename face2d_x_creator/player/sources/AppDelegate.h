
#ifndef  _APP_DELEGATE_H_
#define  _APP_DELEGATE_H_

#include "cocoa/CCObject.h"
#include "CCApplication.h"
#include "SimulatorConfig.h"

//class StartupCall;

/**
 @brief    The cocos2d Application.

 The reason for implement as private inheritance is to hide some interface call by CCDirector.
 */
class  AppDelegate : public cocos2d::CCApplication
{
public:
#if (CC_TARGET_PLATFORM == CC_PLATFORM_QT)
    AppDelegate(int argc, char *argv[]);
#else
    AppDelegate();
#endif
    virtual ~AppDelegate();

    /**
     @brief    Implement CCDirector and CCScene init code here.
     @return true    Initialize success, app continue.
     @return false   Initialize failed, app terminate.
     */
    virtual bool applicationDidFinishLaunching();

    /**
     @brief  The function be called when the application enter background
     @param  the pointer of the application
     */
    virtual void applicationDidEnterBackground();

    /**
     @brief  The function be called when the application enter foreground
     @param  the pointer of the application
     */
    virtual void applicationWillEnterForeground();

    void setProjectConfig(const ProjectConfig& config);

private:
    ProjectConfig m_projectConfig;

//    friend class StartupCall;
};


#endif // _APP_DELEGATE_H_
