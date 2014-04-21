//
//  Face2dNode.cpp
//  face2d_x
//
//  Created by 血染的玩偶 on 14-4-11.
//  Copyright (c) 2014年 qeeplay.com. All rights reserved.
//

#include "Face2dNode.h"
#include "Face2dAnimManager.h"
#include "Face2dGrid.h"

Face2dNode::Face2dNode()
{
}

Face2dNode::~Face2dNode()
{
    for (vector<CCTexture2D*>::iterator iter = m_textures.begin();
         iter != m_textures.end(); ++iter)
    {
        (*iter)->release();
    }
}

bool Face2dNode::initWithFile(const char* path)
{
#ifdef __QT__
    string fullpath = path;
#else
    string fullpath = CCFileUtils::sharedFileUtils()->fullPathForFilename(path);
#endif
    string::size_type pos = fullpath.rfind("/");
    m_config_path = fullpath.substr(0,pos+1);
    CCDictionary* config = CCDictionary::createWithContentsOfFile(fullpath.c_str());
    return initWithConfig(config);
}

bool Face2dNode::initWithConfig(CCDictionary* config)
{
    typeAt(CCDictionary, property, config);
    typeAt(CCArray, texture, property);
    for (int i = 0 ; i < texture->count(); ++i)
    {
        string path = ((CCString*)texture->objectAtIndex(i))->m_sString;
        path = m_config_path + path;
        CCTexture2D* tex = CCTextureCache::sharedTextureCache()->addImage(path.c_str());
        tex->retain();
        m_textures.push_back(tex);
    }
    setContentSize(CCSize(property->valueForKey("width")->floatValue(),property->valueForKey("height")->floatValue()));
    typeAt(CCArray,grid_tree,config);
    for (int i = 0; i < grid_tree->count(); ++i)
    {
        Face2dGrid* grid = Face2dGrid::create((CCDictionary*)grid_tree->objectAtIndex(i),this);
        if (grid)
        {
            this->addChild(grid);
        }
    }
    return true;
}

void Face2dNode::stopAllAnimations()
{
    
}

void Face2dNode::reset()
{
    
}
