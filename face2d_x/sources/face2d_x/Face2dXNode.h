//
//  Face2dXNode.h
//  face2d_x
//
//  Created by 血染的玩偶 on 14-4-11.
//  Copyright (c) 2014年 qeeplay.com. All rights reserved.
//

#ifndef __face2d_x__Face2dXNode__
#define __face2d_x__Face2dXNode__

#include <iostream>
#include <map>
#include <string>
using namespace std;

#ifndef __QT__
#include "cocos2d.h"
using namespace cocos2d;
#else
#include "Interface.h"
#endif

#include "Face2dXTypes.h"
#include "Face2dXGrid.h"
#include "Face2dXUnitAnimation.h"
#include "Face2dXAnimation.h"
#include "Face2dXTouchAnimation.h"

class Face2dXUnit;
class Face2dXNode:public CCNode
{
public:
    Face2dXNode();
    ~Face2dXNode();
    bool initWithFile(const char* path);
    bool initWithConfig(CCDictionary* config);
    void stopAllAnimations();
    void reset();
private:
    map<string,Face2dXGrid*> m_all_grid;
    Face2dXTouchAnimation* m_touch_animation;
    map<string,Face2dXAnimation*> m_animations;
    vector<CCTexture2D*> m_textures;
    string m_config_path;
    
    friend class Face2dXGrid;
    friend class Face2dXUnit;
};

#endif /* defined(__face2d_x__Face2dXNode__) */
