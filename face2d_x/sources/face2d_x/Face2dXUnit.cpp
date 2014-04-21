//
//  Face2dXUnit.cpp
//  face2d_x
//
//  Created by 血染的玩偶 on 14-4-11.
//  Copyright (c) 2014年 qeeplay.com. All rights reserved.
//

#include "Face2dXUnit.h"
#include "Face2dXNode.h"

static map<GLuint,int> s_textures;


Face2dXUnit::Face2dXUnit()
:m_texture(0)
,m_grid(NULL)
{
}

Face2dXUnit::~Face2dXUnit()
{
    CC_SAFE_RELEASE(m_texture);
}

bool Face2dXUnit::initWithConfig(CCDictionary* config,Face2dXNode* orginNode)
{
    int textureid = config->valueForKey("texture")->intValue();
    m_texture = orginNode->m_textures[textureid];
    m_texture->retain();
    typeAt(CCArray, uv, config);
    typeAt(CCArray, vertex, config);
    for (int i = 0; i < uv->count(); ++i)
    {
        CCArray* pos = (CCArray*)uv->objectAtIndex(i);
        float u = ((CCString*)pos->objectAtIndex(0))->floatValue();
        float v = ((CCString*)pos->objectAtIndex(1))->floatValue();
        Face2dX_UV tuv = {u,v};
        m_all_uv.push_back(tuv);
        
        CCArray* ver = (CCArray*)vertex->objectAtIndex(i);
        float x = ((CCString*)ver->objectAtIndex(0))->floatValue();
        float y = ((CCString*)ver->objectAtIndex(1))->floatValue();
        Face2dX_Vertex tvertex = {x,y,0};
        m_now_vertex.push_back(tvertex);
        m_now_color.push_back(ccc4(0xff, 0xff, 0xff, 0xff));
    }
    typeAt(CCArray, triangle, config);
    for (int i = 0; i < triangle->count(); ++i)
    {
        CCArray* tri = (CCArray*)triangle->objectAtIndex(i);
        int i_0 = ((CCString*)tri->objectAtIndex(0))->intValue();
        int i_1 = ((CCString*)tri->objectAtIndex(1))->intValue();
        int i_2 = ((CCString*)tri->objectAtIndex(2))->intValue();
        Face2dXTriangle tria = {(GLushort)i_0,(GLushort)i_1,(GLushort)i_2};
        m_all_triangle.push_back(tria);
    }
    return true;
}

void Face2dXUnit::draw()
{
    if (m_texture == 0 || m_texture->getName() == 0)
    {
        return;
    }
#define Face2dX_Vertex_Size sizeof(Face2dX_Vertex)
#define Face2dX_UV_Size sizeof(Face2dX_UV)
#define Face2dX_Color_Size sizeof(Face2dX_Color)
#ifndef __QT__

    ccGLBindTexture2D( m_texture->getName() );

    ccGLEnableVertexAttribs(kCCVertexAttribFlag_PosColorTex );

    // vertex
    glVertexAttribPointer(kCCVertexAttrib_Position, 3, GL_FLOAT, GL_FALSE, Face2dX_Vertex_Size, (void*)m_now_vertex.data());
    glVertexAttribPointer(kCCVertexAttrib_TexCoords, 2, GL_FLOAT, GL_FALSE, Face2dX_UV_Size, (void*)m_all_uv.data());
    glVertexAttribPointer(kCCVertexAttrib_Color, 4, GL_UNSIGNED_BYTE, GL_TRUE, Face2dX_Color_Size, (void*)m_now_color.data());

    glDrawElements(GL_TRIANGLES,(GLsizei)m_all_triangle.size()*3, GL_UNSIGNED_SHORT, m_all_triangle.data());
#else
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D,m_texture->getName());
    for(vector<Face2dXTriangle>::iterator iter = m_all_triangle.begin();
        iter != m_all_triangle.end(); ++iter)
    {
        Face2dXTriangle& points = *iter;
        float a,b;

        glBegin(GL_TRIANGLES);

        GLushort index = points.first;
        glTexCoord2f(m_all_uv[index].u,-m_all_uv[index].v);
        a = m_now_vertex[index].x*2/ Interface::getWinSize().width-1;
        b = m_now_vertex[index].y*2/ Interface::getWinSize().height-1;
        glVertex3f(a,b,0);

        index = points.second;
        glTexCoord2f(m_all_uv[index].u,-m_all_uv[index].v);
        a = m_now_vertex[index].x*2/ Interface::getWinSize().width-1;
        b = m_now_vertex[index].y*2/ Interface::getWinSize().height-1;
        glVertex3f(a,b,0);

        index = points.three;
        glTexCoord2f(m_all_uv[index].u,-m_all_uv[index].v);
        a = m_now_vertex[index].x*2/ Interface::getWinSize().width-1;
        b = m_now_vertex[index].y*2/ Interface::getWinSize().height-1;
        glVertex3f(a,b,0);

        glEnd();
    }
#endif
}
