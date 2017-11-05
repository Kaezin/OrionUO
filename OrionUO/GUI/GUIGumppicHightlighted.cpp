﻿// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
/***********************************************************************************
**
** GUIGumppicHightlighted.cpp
**
** Copyright (C) August 2016 Hotride
**
************************************************************************************
*/
//----------------------------------------------------------------------------------
#include "stdafx.h"
//----------------------------------------------------------------------------------
CGUIGumppicHightlighted::CGUIGumppicHightlighted(const uint &serial, const ushort &graphic, const ushort &color, const ushort &selectedColor, const int &x, const int &y)
: CGUIDrawObject(GOT_GUMPPICHIGHTLIGHTED, serial, graphic, color, x, y),
m_SelectedColor(selectedColor)
{
}
//----------------------------------------------------------------------------------
CGUIGumppicHightlighted::~CGUIGumppicHightlighted()
{
}
//----------------------------------------------------------------------------------
void CGUIGumppicHightlighted::SetShaderMode()
{
	WISPFUN_DEBUG("c56_f1");

	if (g_SelectedObject.Object == this)
	{
		glUniform1iARB(g_ShaderDrawMode, SDM_COLORED);

		g_ColorManager.SendColorsToShader(m_SelectedColor);
	}
	else if (m_Color != 0)
	{
		if (m_PartialHue)
			glUniform1iARB(g_ShaderDrawMode, SDM_PARTIAL_HUE);
		else
			glUniform1iARB(g_ShaderDrawMode, SDM_COLORED);

		g_ColorManager.SendColorsToShader(m_Color);
	}
	else
		glUniform1iARB(g_ShaderDrawMode, SDM_NO_COLOR);
}
//----------------------------------------------------------------------------------
void CGUIGumppicHightlighted::OnMouseEnter()
{
	WISPFUN_DEBUG("c56_f2");
	if (g_SelectedObject.Gump != NULL)
		g_SelectedObject.Gump->WantRedraw = true;
}
//----------------------------------------------------------------------------------
void CGUIGumppicHightlighted::OnMouseExit()
{
	WISPFUN_DEBUG("c56_f3");
	if (g_LastSelectedObject.Gump != NULL)
		g_LastSelectedObject.Gump->WantRedraw = true;
}
//----------------------------------------------------------------------------------
