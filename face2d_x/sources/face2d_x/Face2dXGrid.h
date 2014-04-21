//
//  Face2dXGrid.h
//  face2d_x
//
//  Created by 血染的玩偶 on 14-4-11.
//  Copyright (c) 2014年 qeeplay.com. All rights reserved.
//

#ifndef __face2d_x__Face2dXGrid__
#define __face2d_x__Face2dXGrid__

#include <iostream>
#include "Face2dXUnit.h"
#include "Face2dXUnitAnimation.h"

class Face2dXNode;
class Face2dXGrid:public CCNode
{
public:
    Face2dXGrid();
    ~Face2dXGrid();
    static Face2dXGrid* create(CCDictionary* config,Face2dXNode* orginNode);
    bool initWithConfig(CCDictionary* config,Face2dXNode* orginNode);
    void draw();
private:
    Face2dX_Pos m_grid_handler[8]; //曲面网格的8个手柄端点（4端点，每端点2个）
    Face2dXUnit* m_bind_unit;
    int m_width_count; //宽的网格数
    int m_height_count; //高的网格数
    vector<Face2dXUnitAnimation*> m_all_unit_animations;
};

#endif /* defined(__face2d_x__Face2dXGrid__) */
