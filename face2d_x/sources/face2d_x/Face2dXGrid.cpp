//
//  Face2dXGrid.cpp
//  face2d_x
//
//  Created by 血染的玩偶 on 14-4-11.
//  Copyright (c) 2014年 qeeplay.com. All rights reserved.
//

#include "Face2dXGrid.h"
#include "Face2dXNode.h"
#include "Face2dXUnit.h"

Face2dXGrid* Face2dXGrid::create(CCDictionary* config,Face2dXNode* orginNode)
{
    Face2dXGrid* pRet = new Face2dXGrid();
    if (pRet && pRet->initWithConfig(config,orginNode))
    {
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return pRet;
}

Face2dXGrid::Face2dXGrid()
:m_bind_unit(NULL)
{
}

Face2dXGrid::~Face2dXGrid()
{
    if(m_bind_unit)
        delete m_bind_unit;
}

bool Face2dXGrid::initWithConfig(CCDictionary* config,Face2dXNode* orginNode)
{
    orginNode->m_all_grid[config->valueForKey("name")->m_sString] = this;
    typeAt(CCDictionary, unit, config);
    m_bind_unit = new Face2dXUnit();
    m_bind_unit->initWithConfig(unit,orginNode);
    m_bind_unit->m_grid = this;
    typeAt(CCDictionary, property, config);
    m_width_count = property->valueForKey("width_count")->intValue();
    m_height_count = property->valueForKey("height_count")->intValue();
    float x = property->valueForKey("x")->floatValue();
    float y = property->valueForKey("y")->floatValue();
    this->setPosition(x,y);
    typeAt(CCArray, children, config);
    for (int i = 0; i < children->count(); ++i)
    {
        CCDictionary* obj = (CCDictionary*)children->objectAtIndex(i);
        Face2dXGrid* grid = Face2dXGrid::create(obj, orginNode);
        this->addChild(grid);
    }
    return true;
}

void Face2dXGrid::draw()
{
    if(m_bind_unit)
    {
#ifndef __QT__
        CCGLProgram* program = CCShaderCache::sharedShaderCache()->programForKey(kCCShader_PositionTextureColor);
        program->use();
        program->setUniformsForBuiltins();
        
        ccGLBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
#endif
        m_bind_unit->draw();
    }
}
