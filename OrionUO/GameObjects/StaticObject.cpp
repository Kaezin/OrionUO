

#include "stdafx.h"

CStaticObject::CStaticObject(int serial, ushort graphic, ushort color, short x, short y, char z)
    : CRenderStaticObject(ROT_STATIC_OBJECT, serial, graphic, color, x, y, z)
{
    WISPFUN_DEBUG("c28_f1");
    OriginalGraphic = graphic;
    UpdateGraphicBySeason();

    m_TextControl->MaxSize = 1;

#if UO_DEBUG_INFO != 0
    g_StaticsObjectsCount++;
#endif
}

void CStaticObject::UpdateGraphicBySeason()
{
    WISPFUN_DEBUG("c28_f2");

    Graphic = g_Orion.GetSeasonGraphic(OriginalGraphic);

    {
        Vegetation = g_Orion.IsVegetation(Graphic);
    }

    NoDrawTile = IsNoDrawTile(Graphic);
}

void CStaticObject::Draw(int x, int y)
{
    WISPFUN_DEBUG("c28_f3");
    RenderGraphic = Graphic;

    if (g_DeveloperMode == DM_DEBUGGING && g_SelectedObject.Object == this)
        RenderColor = SELECT_STATIC_COLOR;
    else
        RenderColor = Color;

    CRenderStaticObject::Draw(x, y);
}

void CStaticObject::Select(int x, int y)
{
    WISPFUN_DEBUG("c28_f4");
    RenderGraphic = Graphic;

    CRenderStaticObject::Select(x, y);
}
