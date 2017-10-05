﻿/***********************************************************************************
**
** GumpMinimap.h
**
** Copyright (C) August 2016 Hotride
**
************************************************************************************
*/
//----------------------------------------------------------------------------------
#ifndef GUMPMINIMAP_H
#define GUMPMINIMAP_H
//----------------------------------------------------------------------------------
class CGumpMinimap : public CGump
{
	SETGET(ushort, LastX, 0);
	SETGET(ushort, LastY, 0);

private:
	static const int ID_GMM_LOCK_MOVING = 1;

	uchar m_Count{ 0 };

	CGLTexture m_Texture{ CGLTexture() };

	CGUIGumppic *m_Body{ NULL };
	CGUIDataBox *m_DataBox{ NULL };

	void GenerateMap();

protected:
	virtual void CalculateGumpState();

public:
	CGumpMinimap(uint serial, short x, short y, bool minimized);
	virtual ~CGumpMinimap();

	virtual void PrepareContent();

	virtual void UpdateContent();

	GUMP_BUTTON_EVENT_H;

	virtual bool OnLeftMouseButtonDoubleClick();
};
//----------------------------------------------------------------------------------
#endif
//----------------------------------------------------------------------------------
