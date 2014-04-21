//
//  Face2dGrid.cpp
//  face2d_x
//
//  Created by 血染的玩偶 on 14-4-11.
//  Copyright (c) 2014年 qeeplay.com. All rights reserved.
//

#include "Face2dGrid.h"
#include "Face2dNode.h"
#include "Face2dUnit.h"

Face2dGrid* Face2dGrid::create(CCDictionary* config,Face2dNode* orginNode)
{
    Face2dGrid* pRet = new Face2dGrid();
    if (pRet && pRet->initWithConfig(config,orginNode))
    {
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return pRet;
}

Face2dGrid::Face2dGrid()
:m_bind_unit(NULL)
{
}

Face2dGrid::~Face2dGrid()
{
    if(m_bind_unit)
        delete m_bind_unit;
}

bool Face2dGrid::initWithConfig(CCDictionary* config,Face2dNode* orginNode)
{
    orginNode->m_all_grid[config->valueForKey("name")->m_sString] = this;
    typeAt(CCDictionary, unit, config);
    m_bind_unit = new Face2dUnit();
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
        Face2dGrid* grid = Face2dGrid::create(obj, orginNode);
        this->addChild(grid);
    }
    return true;
}

void Face2dGrid::draw()
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
