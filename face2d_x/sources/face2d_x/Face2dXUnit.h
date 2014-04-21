//
//  Face2dXUnit.h
//  face2d_x
//
//  Created by 血染的玩偶 on 14-4-11.
//  Copyright (c) 2014年 qeeplay.com. All rights reserved.
//

#ifndef __face2d_x__Face2dXUnit__
#define __face2d_x__Face2dXUnit__

#include <iostream>
#include "Face2dXTypes.h"

class Face2dXGrid;

//三角形索引

struct Face2dXTriangle
{
    GLushort first;
    GLushort second;
    GLushort three;
};

class Face2dXNode;
class Face2dXUnit
{
public:
    Face2dXUnit();
    ~Face2dXUnit();
    bool initWithConfig(CCDictionary* config,Face2dXNode*);
    void draw();
private:
    vector<Face2dX_UV> m_all_uv;
    vector<Face2dX_Vertex> m_orgin_vertex;
    vector<Face2dX_Vertex> m_now_vertex;
    vector<Face2dX_Color> m_now_color;
    vector<Face2dXTriangle> m_all_triangle;
    CCTexture2D* m_texture;
    Face2dXGrid* m_grid; //本部件所属的网格曲面
    friend class Face2dXGrid;
    friend class CCNode;
};

#endif /* defined(__face2d_x__Face2dXUnit__) */
