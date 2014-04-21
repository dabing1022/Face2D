//
//  Face2dGrid.h
//  face2d_x
//
//  Created by 血染的玩偶 on 14-4-11.
//  Copyright (c) 2014年 qeeplay.com. All rights reserved.
//

#ifndef __face2d_x__Face2dGrid__
#define __face2d_x__Face2dGrid__

#include <iostream>
#include "Face2dUnit.h"
#include "Face2dUnitAnimation.h"

class Face2dNode;
class Face2dGrid:public CCNode
{
public:
    Face2dGrid();
    ~Face2dGrid();
    static Face2dGrid* create(CCDictionary* config,Face2dNode* orginNode);
    bool initWithConfig(CCDictionary* config,Face2dNode* orginNode);
    void draw();
private:
    Face2d_Pos m_grid_handler[8]; //曲面网格的8个手柄端点（4端点，每端点2个）
    Face2dUnit* m_bind_unit;
    int m_width_count; //宽的网格数
    int m_height_count; //高的网格数
    vector<Face2dUnitAnimation*> m_all_unit_animations;
};

#endif /* defined(__face2d_x__Face2dGrid__) */
