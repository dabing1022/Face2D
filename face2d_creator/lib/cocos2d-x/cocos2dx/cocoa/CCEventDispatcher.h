/****************************************************************************
 Copyright (c) 2010-2012 cocos2d-x.org

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

#ifndef __CCEVENT_DISPATCHER_H__
#define __CCEVENT_DISPATCHER_H__

#include <map>

#include "ccMacros.h"
#include "CCObject.h"

using namespace std;

NS_CC_BEGIN

#define kCCNodeOnEnter                          1
#define kCCNodeOnExit                           2
#define kCCNodeOnEnterTransitionDidFinish       3
#define kCCNodeOnExitTransitionDidStart         4
#define kCCNodeOnCleanup                        5
#define kCCNodeOnEnterFrame                     6

#define ENTER_SCENE_EVENT                       kCCNodeOnEnter
#define EXIT_SCENE_EVENT                        kCCNodeOnExit
#define ENTER_TRANSITION_DID_FINISH_EVENT       kCCNodeOnEnterTransitionDidFinish
#define EXIT_TRANSITION_DID_START_EVENT         kCCNodeOnExitTransitionDidStart
#define CLEANUP_EVENT                           kCCNodeOnCleanup
#define ENTER_FRAME_EVENT                       kCCNodeOnEnterFrame

typedef map<int, int> ScriptHandlerMap;
typedef ScriptHandlerMap::iterator ScriptHandlerMapIterator;

typedef map<int, ScriptHandlerMap> ScriptEventHandlerMap;
typedef ScriptEventHandlerMap::iterator ScriptEventHandlerMapIterator;

class CC_DLL CCEventDispatcher : public CCObject
{
public:
    int addScriptEventListener(int event, int callback);
    void removeScriptEventListener(int event, int handle);
    void removeAllScriptEventListenersForEvent(int event);
    void removeAllScriptEventListeners();

    bool hasScriptEventListener(int event);
    ScriptHandlerMap &getScriptEventListenerForEvent(int event);
    ScriptEventHandlerMap &getAllScriptEventListeners();

    virtual void scheduleUpdateForNodeEvent() = 0;

private:
    ScriptEventHandlerMap m_map;
    static int s_nextid;
};

NS_CC_END


#endif /* defined(__CCEVENT_DISPATCHER_H__) */
