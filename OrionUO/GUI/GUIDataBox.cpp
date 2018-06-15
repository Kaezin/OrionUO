﻿/***********************************************************************************
**
** GUIDataBox.cpp
**
** Copyright (C) August 2016 Hotride
**
************************************************************************************
*/

#include "stdafx.h"

CGUIDataBox::CGUIDataBox()
    : CGUIPolygonal(GOT_DATABOX, 0, 0, 0, 0)
{
}

CGUIDataBox::~CGUIDataBox()
{
}

void CGUIDataBox::PrepareTextures()
{
    WISPFUN_DEBUG("c51_f1");
    QFOR(item, m_Items, CBaseGUI *)
    item->PrepareTextures();
}

bool CGUIDataBox::EntryPointerHere()
{
    WISPFUN_DEBUG("c51_f2");
    QFOR(item, m_Items, CBaseGUI *)
    {
        if (item->Visible && item->EntryPointerHere())
            return true;
    }

    return false;
}
