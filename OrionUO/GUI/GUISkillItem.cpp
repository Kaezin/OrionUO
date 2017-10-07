﻿/***********************************************************************************
**
** GUISkillItem.cpp
**
** Copyright (C) August 2016 Hotride
**
************************************************************************************
*/
//----------------------------------------------------------------------------------
#include "stdafx.h"
//----------------------------------------------------------------------------------
CGUISkillItem::CGUISkillItem(const uint &serial, const uint &useSerial, const uint &statusSerial, const int &index, const int &x, const int &y)
: CBaseGUI(GOT_SKILLITEM, serial, 0, 0, x, y), m_Index(index)
{
	WISPFUN_DEBUG("c76_f1");
	CSkill *skill = g_SkillsManager.Get(m_Index);

	if (skill != NULL)
	{
		if (skill->Button != 0)
			m_ButtonUse = new CGUIButton(useSerial, 0x0837, 0x0838, 0x0838, 8, 0);
		else
			m_ButtonUse = NULL;

		m_Status = skill->Status;

		ushort graphic = GetStatusButtonGraphic();
		m_ButtonStatus = new CGUIButton(statusSerial, graphic, graphic, graphic, 251, 0);
		m_ButtonStatus->CheckPolygone = true;

		g_FontManager.GenerateA(9, m_NameText, skill->Name.c_str(), 0x0288);

		CreateValueText();
	}
}
//----------------------------------------------------------------------------------
CGUISkillItem::~CGUISkillItem()
{
	WISPFUN_DEBUG("c76_f2");
	m_NameText.Clear();
	m_ValueText.Clear();

	RELEASE_POINTER(m_ButtonUse);
	RELEASE_POINTER(m_ButtonStatus);
}
//----------------------------------------------------------------------------------
void CGUISkillItem::OnChangeStatus(const uchar &val)
{
	WISPFUN_DEBUG("c76_f3");
	m_Status = val;

	ushort graphic = GetStatusButtonGraphic();

	m_ButtonStatus->Graphic = graphic;
	m_ButtonStatus->GraphicSelected = graphic;
	m_ButtonStatus->GraphicPressed = graphic;
}
//----------------------------------------------------------------------------------
ushort CGUISkillItem::GetStatusButtonGraphic()
{
	WISPFUN_DEBUG("c76_f4");
	ushort graphic = 0x0984; //Up

	if (m_Status == 1)
		graphic = 0x0986; //Down
	else if (m_Status == 2)
		graphic = 0x082C; //Lock

	return graphic;
}
//----------------------------------------------------------------------------------
void CGUISkillItem::CreateValueText(const bool &showReal, const bool &showCap)
{
	WISPFUN_DEBUG("c76_f5");
	CSkill *skill = g_SkillsManager.Get(m_Index);

	if (skill != NULL)
	{
		//Значение скилла (учитывая выбранный флаг отображения)
		float val = skill->BaseValue;
		if (showReal)
			val = skill->Value;
		else if (showCap)
			val = skill->Cap;

		char sbf[10] = { 0 };
		sprintf_s(sbf, "%.1f", val);

		g_FontManager.GenerateA(9, m_ValueText, sbf, 0x0288);
	}
}
//----------------------------------------------------------------------------------
void CGUISkillItem::PrepareTextures()
{
	WISPFUN_DEBUG("c76_f6");
	if (m_ButtonUse != NULL)
		m_ButtonUse->PrepareTextures();

	m_ButtonStatus->PrepareTextures();
}
//----------------------------------------------------------------------------------
CBaseGUI *CGUISkillItem::SelectedItem()
{
	WISPFUN_DEBUG("c76_f7");
	CBaseGUI *selected = this;

	if (g_Orion.PolygonePixelsInXY(m_X + m_ButtonStatus->X, m_Y + m_ButtonStatus->Y, 14, 14))
		selected = m_ButtonStatus;
	else if (m_ButtonUse != NULL)
	{
		if (g_Orion.GumpPixelsInXY(m_ButtonUse->Graphic, m_X + m_ButtonUse->X, m_Y + m_ButtonUse->Y))
			selected = m_ButtonUse;
	}

	return selected;
}
//----------------------------------------------------------------------------------
void CGUISkillItem::Draw(const bool &checktrans)
{
	WISPFUN_DEBUG("c76_f8");
	glTranslatef((GLfloat)m_X, (GLfloat)m_Y, 0.0f);

	if (m_ButtonUse != NULL)
		m_ButtonUse->Draw(checktrans);

	if (g_PressedObject.LeftObject == this)
		g_GL.DrawPolygone(20, 0, 250, 14);

	m_NameText.Draw(22, 0, checktrans);

	m_ButtonStatus->Draw(checktrans);

	m_ValueText.Draw(250 - m_ValueText.Width, 0);

	glTranslatef((GLfloat)-m_X, (GLfloat)-m_Y, 0.0f);
}
//----------------------------------------------------------------------------------
bool CGUISkillItem::Select()
{
	WISPFUN_DEBUG("c76_f9");
	int x = g_MouseManager.Position.X - m_X;
	int y = g_MouseManager.Position.Y - m_Y;

	return (x >= 0 && y >= 0 && x < 255 && y < 17);
}
//----------------------------------------------------------------------------------
