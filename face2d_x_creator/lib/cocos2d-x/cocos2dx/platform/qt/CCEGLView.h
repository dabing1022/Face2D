/****************************************************************************
Copyright (c) 2010 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#ifndef __CC_EGLVIEW_WIN32_H__
#define __CC_EGLVIEW_WIN32_H__

#include <QMouseEvent>
#include <QWidget>
#include <QWindow>

#include "touch_dispatcher/CCTouch.h"
#include "CCStdC.h"
#include "platform/CCCommon.h"
#include "cocoa/CCGeometry.h"
#include "platform/CCEGLViewProtocol.h"

//
#include "FastDelegate.h"

typedef fastdelegate::FastDelegate1<QKeyEvent *> MyAccelerometerDelegate;

NS_CC_BEGIN

class Cocos2DQt5OpenGLIntegration;
class CCEGL;
class CCTouch;

class CC_DLL CCEGLView : public CCEGLViewProtocol
{
public:
    CCEGLView();
    virtual ~CCEGLView();

    /* override functions */
    virtual bool isOpenGLReady();
    virtual void end();
    virtual void swapBuffers();
    virtual void setFrameSize(float width, float height);
    virtual void setIMEKeyboardState(bool bOpen);
    virtual void setViewName(const char* pszViewName);

    // Qt
    void mouseMove(QMouseEvent *event);
    void mousePress(QMouseEvent *event);
    void mouseRelease(QMouseEvent *event);
    void setAccelerometerKeyHook(MyAccelerometerDelegate accelerometerDelegate);
    QWidget * getGLWidget();
    void setGLWidget(QWidget* widget);
    QWindow *getWindow();

private:
    virtual bool Create();
    bool initGL();
    void destroyGL();
public:

    void resize(int width, int height);
    /* 
     * Set zoom factor for frame. This method is for debugging big resolution (e.g.new ipad) app on desktop.
     */
    void setFrameZoomFactor(float fZoomFactor);
	float getFrameZoomFactor();
    void centerWindow();
    void moveWindow(int left, int top);

    virtual void setViewPortInPoints(float x , float y , float w , float h);
    virtual void setScissorInPoints(float x , float y , float w , float h);
    
    // static function
    /**
    @brief    get the shared main open gl window
    */
    static CCEGLView* sharedOpenGLView();
    static void purgeSharedOpenGLView();

private:
    bool m_bIsInit;
    bool m_bCaptured;
    bool m_bSupportTouch;
    float m_fFrameZoomFactor;
    float m_fScreenScaleFactor;

    CCSet * m_pSet;
    CCTouch * m_pTouch;
    QWidget * m_glParentWidget;
    Cocos2DQt5OpenGLIntegration *m_integration;

};

NS_CC_END

#endif    // end of __CC_EGLVIEW_WIN32_H__
