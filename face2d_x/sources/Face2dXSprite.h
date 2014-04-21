//
//  Face2dXSprite.h
//  face2d_x
//
//  Created by 血染的玩偶 on 14-4-1.
//  Copyright (c) 2014年 qeeplay.com. All rights reserved.
//

#ifndef __face2d_x__Face2dXSprite__
#define __face2d_x__Face2dXSprite__

#include <iostream>
#include "face2d_x/Face2dXTypes.h"

class Face2dXSprite: public CCSprite
{
public:
    Face2dXSprite();
    ~Face2dXSprite();
    static Face2dXSprite* create(const char* pictruePath, const char* configPath);
    
public:
    bool initWithFile(const char* pictruePath, const char* configPath);
    bool initWithConfig( const char* configPath);
    void draw();
    void runAnimation(string name);
    const CCSize& getBaseSize(){return m_baseSize;}
private:
    void convertDictToConfig(CCDictionary* config);
    void animationUpdate(float time);
private:
    vector<Face2dX_UV> m_orginUV;//所有顶点位于贴图的多少百分比位置，先按照部件在map中的位置排序，同一部件内的坐标按照id排序
    vector<Face2dX_Color> m_orginColor;//所有顶点的颜色，先按照部件在map中的位置排序，同一部件内的坐标按照id排序
    vector<Face2dX_Vertex> m_orginVertex;//所有顶点位于画布的坐标（配置是左上角，这里是左下角对齐），先按照部件在map中的位置排序，同一部件内的坐标按照id排序
    vector<Face2dX_Vertex> m_nowVertex;//所有坐标当前位于画布的坐标（左下角对齐），先按照部件在map中的位置排序，同一部件内的坐标按照id排序
    map<string,Face2dX_TriangleList> m_all_units;//所有部件，Face2dX_TriangleList是三角形ID列表
    
    vector<map<int,Face2dX_Unit_Anim_Pos> > m_all_point_move;
    map<string, map<string,Face2dX_Unit_Anims> > m_all_unitanims;//所有部件动画
    map<string, Face2dX_Anims> m_all_anims;//所有动画
    CCSize m_baseSize;
    cc_timeval m_nowTime;
    float m_animTime;
    float m_animNowTime;
    bool m_isAnimation;
    Face2dX_Anims* m_curAnims;
};

#endif /* defined(__face2d_x__Face2dXSprite__) */
