//
//  Face2dTypes.h
//  face2d_x
//
//  Created by 血染的玩偶 on 14-4-1.
//  Copyright (c) 2014年 qeeplay.com. All rights reserved.
//

#ifndef face2d_x_Face2dTypes_h
#define face2d_x_Face2dTypes_h

#include <list>
#include <vector>
#include <map>
using namespace std;

#ifndef __QT__
#include "cocos2d.h"
using namespace cocos2d;
#else

#include "CCTexture2D.h"
#include "CCString.h"
#include "CCSprite.h"
#include "CCDictionary.h"
#include "CCTime.h"
#include "CCNode.h"
#include "CCTextureCache.h"

#endif

typedef CCPoint Face2d_Pos;
typedef CCSize Face2d_Size;
typedef ccTex2F Face2d_UV;
typedef ccColor4B Face2d_Color;
typedef ccVertex3F Face2d_Vertex;

#define floatAtArray(index,array) ((CCString*)array->objectAtIndex(index))->floatValue()
#define intAtArray(index,array) ((CCString*)array->objectAtIndex(index))->intValue()
#define typeAt(type,name,object) type* name = (type*)object->objectForKey(#name)

struct Face2d_Triangle
{
    int point[3];
    int orginPoint[3];
};//point_n是Face2d_Unit中，points里Face2dOriginPoint的Index

typedef vector<Face2d_Triangle> Face2d_TriangleList;

enum Face2d_Animation_Type
{
    Face2d_Animation_Position = 0,
};

struct Face2d_Unit_Anim_Pos
{
    float x;
    float y;
    float x_moveBy;
    float y_moveBy;
};

struct Face2d_Unit_Anim
{
    Face2d_Animation_Type type;
    float start_perc;
    float end_perc;
    int anim_id;
};

typedef list<Face2d_Unit_Anim> Face2d_Unit_Anims;

struct Face2d_Anim
{
    Face2d_Unit_Anims* anim;
    string unit_name;
    float delay;
    float time;
};

typedef list<Face2d_Anim> Face2d_Anims;


#endif
