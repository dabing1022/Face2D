//
//  Face2dNode.h
//  face2d_x
//
//  Created by 血染的玩偶 on 14-4-11.
//  Copyright (c) 2014年 qeeplay.com. All rights reserved.
//

#ifndef __face2d_x__Face2dNode__
#define __face2d_x__Face2dNode__

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

#include "Face2dTypes.h"
#include "Face2dGrid.h"
#include "Face2dUnitAnimation.h"
#include "Face2dAnimation.h"
#include "Face2dTouchAnimation.h"

class Face2dUnit;
class Face2dNode:public CCNode
{
public:
    Face2dNode();
    ~Face2dNode();
    bool initWithFile(const char* path);
    bool initWithConfig(CCDictionary* config);
    void stopAllAnimations();
    void reset();
private:
    map<string,Face2dGrid*> m_all_grid;
    Face2dTouchAnimation* m_touch_animation;
    map<string,Face2dAnimation*> m_animations;
    vector<CCTexture2D*> m_textures;
    string m_config_path;
    
    friend class Face2dGrid;
    friend class Face2dUnit;
};

#endif /* defined(__face2d_x__Face2dNode__) */
