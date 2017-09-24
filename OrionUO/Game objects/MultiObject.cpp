﻿/***********************************************************************************
**
** MultiObject.h
**
** Copyright (C) August 2016 Hotride
**
************************************************************************************
*/
//----------------------------------------------------------------------------------
#include "stdafx.h"
//----------------------------------------------------------------------------------
CMultiObject::CMultiObject(const ushort &graphic, const short &x, const short &y, const char &z, const uint &flags, const bool &isCustomHouseMulti)
: CRenderStaticObject(ROT_MULTI_OBJECT, 0, graphic, 0, x, y, z), m_OnTarget(flags == 2),
m_IsCustomHouseMulti(isCustomHouseMulti)
{
	WISPFUN_DEBUG("c25_f1");
	m_OriginalGraphic = graphic;
	UpdateGraphicBySeason();

#if UO_DEBUG_INFO!=0
	g_MultiObjectsCount++;
#endif //UO_DEBUG_INFO!=0
}
//----------------------------------------------------------------------------------
CMultiObject::~CMultiObject()
{
#if UO_DEBUG_INFO!=0
	g_MultiObjectsCount--;
#endif //UO_DEBUG_INFO!=0
}
//----------------------------------------------------------------------------------
void CMultiObject::UpdateGraphicBySeason()
{
	WISPFUN_DEBUG("c25_f2");
	//ushort graphic = m_Graphic;

	m_Graphic = g_Orion.GetSeasonGraphic(m_OriginalGraphic);

	//if (m_Graphic != graphic)
	{
		m_Vegetation = g_Orion.IsVegetation(m_Graphic);

		if (IsWet())
			m_RenderQueueIndex = 1;
		else if (IsBackground())
			m_RenderQueueIndex = 3 - (int)IsSurface();
		else if (IsSurface())
			m_RenderQueueIndex = 4;
		else
			m_RenderQueueIndex = 6;
	}
}
//----------------------------------------------------------------------------------
void CMultiObject::Draw(const int &x, const int &y)
{
	WISPFUN_DEBUG("c25_f3");
#if UO_DEBUG_INFO!=0
	g_RenderedObjectsCountInGameWindow++;
#endif

	if (m_OnTarget) //Мульти на таргете
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_COLOR, GL_ONE_MINUS_SRC_COLOR);

		g_Orion.DrawStaticArt(m_Graphic, m_Color, x, y);

		glDisable(GL_BLEND);
	}
	else
	{
		m_RenderGraphic = m_Graphic;

		if (g_DeveloperMode == DM_DEBUGGING && g_SelectedObject.Object == this)
			m_RenderColor = SELECT_MULTI_COLOR;
		else
			m_RenderColor = m_Color;

		CRenderStaticObject::Draw(x, y);
	}
}
//----------------------------------------------------------------------------------
void CMultiObject::Select(const int &x, const int &y)
{
	WISPFUN_DEBUG("c25_f4");
	if (!m_OnTarget)
	{
		m_RenderGraphic = m_Graphic;

		CRenderStaticObject::Select(x, y);
	}
}
//----------------------------------------------------------------------------------
