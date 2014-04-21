//
//  Face2dXUnitAnimation.h
//  face2d_x
//
//  Created by 血染的玩偶 on 14-4-13.
//  Copyright (c) 2014年 qeeplay.com. All rights reserved.
//

#ifndef __face2d_x__Face2dXUnitAnimation__
#define __face2d_x__Face2dXUnitAnimation__

#include <iostream>
#include "Face2dXTypes.h"

enum Face2dXUnitAxisType
{
    Face2dXUnitAxisX = 0,
    Face2dXUnitAxisY,
    Face2dXUnitAxisXY,
};

class Face2dXUnitAnimation
{
public:
    Face2dXUnitAnimation();
    ~Face2dXUnitAnimation();
private:
    Face2dXUnitAxisType m_type;
    vector<Face2dX_Vertex> m_vertex[9];
    
};


#endif /* defined(__face2d_x__Face2dXUnitAnimation__) */
