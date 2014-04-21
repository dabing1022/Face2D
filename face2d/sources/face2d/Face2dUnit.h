//
//  Face2dUnit.h
//  face2d_x
//
//  Created by 血染的玩偶 on 14-4-11.
//  Copyright (c) 2014年 qeeplay.com. All rights reserved.
//

#ifndef __face2d_x__Face2dUnit__
#define __face2d_x__Face2dUnit__

#include <iostream>
#include "Face2dTypes.h"

class Face2dGrid;

//三角形索引

struct Face2dTriangle
{
    GLushort first;
    GLushort second;
    GLushort three;
};

class Face2dNode;
class Face2dUnit
{
public:
    Face2dUnit();
    ~Face2dUnit();
    bool initWithConfig(CCDictionary* config,Face2dNode*);
    void draw();
private:
    vector<Face2d_UV> m_all_uv;
    vector<Face2d_Vertex> m_orgin_vertex;
    vector<Face2d_Vertex> m_now_vertex;
    vector<Face2d_Color> m_now_color;
    vector<Face2dTriangle> m_all_triangle;
    CCTexture2D* m_texture;
    Face2dGrid* m_grid; //本部件所属的网格曲面
    friend class Face2dGrid;
    friend class CCNode;
};

#endif /* defined(__face2d_x__Face2dUnit__) */
