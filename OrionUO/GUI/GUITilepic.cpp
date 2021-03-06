

#include "stdafx.h"

CGUITilepic::CGUITilepic(ushort graphic, ushort color, int x, int y)
    : CGUIDrawObject(GOT_TILEPIC, 0, graphic, color, x, y)
{
}

CGUITilepic::~CGUITilepic()
{
}

WISP_GEOMETRY::CSize CGUITilepic::GetSize()
{
    WISPFUN_DEBUG("c80_f1");
    WISP_GEOMETRY::CSize size;

    CGLTexture *th = g_Orion.ExecuteStaticArt(Graphic);

    if (th != NULL)
    {
        size.Width = th->Width;
        size.Height = th->Height;
    }

    return size;
}

void CGUITilepic::PrepareTextures()
{
    WISPFUN_DEBUG("c80_f2");
    g_Orion.ExecuteStaticArt(Graphic);
}

void CGUITilepic::Draw(bool checktrans)
{
    WISPFUN_DEBUG("c80_f3");
    CGLTexture *th = g_Orion.ExecuteStaticArt(Graphic);

    if (th != NULL)
    {
        SetShaderMode();

        th->Draw(m_X, m_Y, checktrans);
    }
}

bool CGUITilepic::Select()
{
    WISPFUN_DEBUG("c80_f4");

    CGLTexture *th = g_Orion.m_StaticDataIndex[Graphic].Texture;

    if (th != NULL)
        return th->Select(m_X, m_Y, !CheckPolygon);

    return false;
}
