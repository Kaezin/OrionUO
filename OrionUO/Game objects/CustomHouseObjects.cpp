﻿/***********************************************************************************
**
** CustomHouseObjects.cpp
**
** Copyright (C) September 2017 Hotride
**
************************************************************************************
*/
//----------------------------------------------------------------------------------
#include "stdafx.h"
//----------------------------------------------------------------------------------
bool CCustomHouseObjectWall::Parse(const char *text)
{
	WISPFUN_DEBUG("");
	bool result = sscanf(text,
		"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
		&m_Category, &m_Style, &m_TID, &m_South1, &m_South2, &m_South3, &m_Corner, &m_East1, &m_East2, &m_East3, &m_Post, &m_WindowS, &m_AltWindowS, &m_WindowE, &m_AltWindowE, &m_SecondAltWindowS, &m_SecondAltWindowE, &m_FeatureMask) >= 17;

	if (result)
	{
		m_Graphics[0] = m_South1;
		m_Graphics[1] = m_South2;
		m_Graphics[2] = m_South3;
		m_Graphics[3] = m_Corner;
		m_Graphics[4] = m_East1;
		m_Graphics[5] = m_East2;
		m_Graphics[6] = m_East3;
		m_Graphics[7] = m_Post;
	}

	return result;
}
//----------------------------------------------------------------------------------
bool CCustomHouseObjectFloor::Parse(const char *text)
{
	WISPFUN_DEBUG("");
	bool result = sscanf(text,
		"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
		&m_Category, &m_F1, &m_F2, &m_F3, &m_F4, &m_F5, &m_F6, &m_F7, &m_F8, &m_F9, &m_F10, &m_F11, &m_F12, &m_F13, &m_F14, &m_F15, &m_F16, &m_FeatureMask) >= 17;

	if (result)
	{
		m_Graphics[0] = m_F1;
		m_Graphics[1] = m_F2;
		m_Graphics[2] = m_F3;
		m_Graphics[3] = m_F4;
		m_Graphics[4] = m_F5;
		m_Graphics[5] = m_F6;
		m_Graphics[6] = m_F7;
		m_Graphics[7] = m_F8;
		m_Graphics[8] = m_F9;
		m_Graphics[9] = m_F10;
		m_Graphics[10] = m_F11;
		m_Graphics[11] = m_F12;
		m_Graphics[12] = m_F13;
		m_Graphics[13] = m_F14;
		m_Graphics[14] = m_F15;
		m_Graphics[15] = m_F16;
	}

	return result;
}
//----------------------------------------------------------------------------------
bool CCustomHouseObjectDoor::Parse(const char *text)
{
	WISPFUN_DEBUG("");
	bool result = sscanf(text,
		"%d %d %d %d %d %d %d %d %d %d",
		&m_Category, &m_Piece1, &m_Piece2, &m_Piece3, &m_Piece4, &m_Piece5, &m_Piece6, &m_Piece7, &m_Piece8, &m_FeatureMask) >= 9;

	if (result)
	{
		m_Graphics[0] = m_Piece1;
		m_Graphics[1] = m_Piece2;
		m_Graphics[2] = m_Piece3;
		m_Graphics[3] = m_Piece4;
		m_Graphics[4] = m_Piece5;
		m_Graphics[5] = m_Piece6;
		m_Graphics[6] = m_Piece7;
		m_Graphics[7] = m_Piece8;
	}

	return result;
}
//----------------------------------------------------------------------------------
bool CCustomHouseObjectMisc::Parse(const char *text)
{
	WISPFUN_DEBUG("");
	bool result = sscanf(text,
		"%d %d %d %d %d %d %d %d %d %d %d %d",
		&m_Category, &m_Style, &m_TID, &m_Piece1, &m_Piece2, &m_Piece3, &m_Piece4, &m_Piece5, &m_Piece6, &m_Piece7, &m_Piece8, &m_FeatureMask) >= 11;

	if (result)
	{
		m_Graphics[0] = m_Piece1;
		m_Graphics[1] = m_Piece2;
		m_Graphics[2] = m_Piece3;
		m_Graphics[3] = m_Piece4;
		m_Graphics[4] = m_Piece5;
		m_Graphics[5] = m_Piece6;
		m_Graphics[6] = m_Piece7;
		m_Graphics[7] = m_Piece8;
	}

	return result;
}
//----------------------------------------------------------------------------------
bool CCustomHouseObjectStair::Parse(const char *text)
{
	WISPFUN_DEBUG("");
	bool result = sscanf(text,
		"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
		&m_Category, &m_Block, &m_North, &m_East, &m_South, &m_West, &m_Squared1, &m_Squared2, &m_Rounded1, &m_Rounded2, &m_MultiNorth, &m_MultiEast, &m_MultiSouth, &m_MultiWest, &m_FeatureMask) >= 14;

	return result;
}
//----------------------------------------------------------------------------------
bool CCustomHouseObjectTeleport::Parse(const char *text)
{
	WISPFUN_DEBUG("");
	bool result = sscanf(text,
		"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
		&m_Category, &m_F1, &m_F2, &m_F3, &m_F4, &m_F5, &m_F6, &m_F7, &m_F8, &m_F9, &m_F10, &m_F11, &m_F12, &m_F13, &m_F14, &m_F15, &m_F16, &m_FeatureMask) >= 17;

	if (result)
	{
		m_Graphics[0] = m_F1;
		m_Graphics[1] = m_F2;
		m_Graphics[2] = m_F3;
		m_Graphics[3] = m_F4;
		m_Graphics[4] = m_F5;
		m_Graphics[5] = m_F6;
		m_Graphics[6] = m_F7;
		m_Graphics[7] = m_F8;
		m_Graphics[8] = m_F9;
		m_Graphics[9] = m_F10;
		m_Graphics[10] = m_F11;
		m_Graphics[11] = m_F12;
		m_Graphics[12] = m_F13;
		m_Graphics[13] = m_F14;
		m_Graphics[14] = m_F15;
		m_Graphics[15] = m_F16;
	}

	return result;
}
//----------------------------------------------------------------------------------
bool CCustomHouseObjectRoof::Parse(const char *text)
{
	WISPFUN_DEBUG("");
	bool result = sscanf(text,
		"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
		&m_Category, &m_Style, &m_TID, &m_North, &m_East, &m_South, &m_West, &m_NSCrosspiece, &m_EWCrosspiece, &m_NDent, &m_SDent, &m_WDent, &m_NTPiece, &m_ETPiece, &m_STPiece, &m_WTPiece, &m_XPiece, &m_Extra, &m_Piece, &m_FeatureMask) >= 19;

	if (result)
	{
		m_Graphics[0] = m_North;
		m_Graphics[1] = m_East;
		m_Graphics[2] = m_South;
		m_Graphics[3] = m_West;
		m_Graphics[4] = m_NSCrosspiece;
		m_Graphics[5] = m_EWCrosspiece;
		m_Graphics[6] = m_NDent;
		m_Graphics[7] = m_SDent;
		m_Graphics[8] = m_WDent;
		m_Graphics[9] = m_NTPiece;
		m_Graphics[10] = m_ETPiece;
		m_Graphics[11] = m_STPiece;
		m_Graphics[12] = m_WTPiece;
		m_Graphics[13] = m_XPiece;
		m_Graphics[14] = m_Extra;
		m_Graphics[15] = m_Piece;
	}

	return result;
}
//----------------------------------------------------------------------------------
