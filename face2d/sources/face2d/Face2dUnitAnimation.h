//
//  Face2dUnitAnimation.h
//  face2d_x
//
//  Created by 血染的玩偶 on 14-4-13.
//  Copyright (c) 2014年 qeeplay.com. All rights reserved.
//

#ifndef __face2d_x__Face2dUnitAnimation__
#define __face2d_x__Face2dUnitAnimation__

#include <iostream>
#include "Face2dTypes.h"

enum Face2dUnitAxisType
{
    Face2dUnitAxisX = 0,
    Face2dUnitAxisY,
    Face2dUnitAxisXY,
};

class Face2dUnitAnimation
{
public:
    Face2dUnitAnimation();
    ~Face2dUnitAnimation();
private:
    Face2dUnitAxisType m_type;
    vector<Face2d_Vertex> m_vertex[9];
    
};


#endif /* defined(__face2d_x__Face2dUnitAnimation__) */
