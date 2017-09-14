﻿/***********************************************************************************
**
** ColorManager.cpp
**
** Copyright (C) August 2016 Hotride
**
************************************************************************************
*/
//----------------------------------------------------------------------------------
#include "stdafx.h"

CColorManager g_ColorManager;
//----------------------------------------------------------------------------------
CColorManager::CColorManager()
: m_HuesCount(0)
{
}
//----------------------------------------------------------------------------------
CColorManager::~CColorManager()
{
}
//----------------------------------------------------------------------------------
void CColorManager::Init()
{
	WISPFUN_DEBUG("c137_f1");
	uint addr = (uint)g_FileManager.m_HuesMul.Start;
	uint size = g_FileManager.m_HuesMul.Size;

	if (addr > 0 && size > 0 && addr != 0xFFFFFFFF && size != 0xFFFFFFFF)
	{
		int entryCount = size / sizeof(HUES_GROUP);

		m_HuesCount = entryCount * 8;
		m_HuesRange.resize(entryCount);

		memcpy(&m_HuesRange[0], (PVOID)addr, entryCount * sizeof(HUES_GROUP));
	}
	else
		m_HuesCount = 0;

	if (g_FileManager.m_RadarcolMul.Size)
	{
		m_Radarcol.resize(g_FileManager.m_RadarcolMul.Size);
		memcpy(&m_Radarcol[0], (PVOID)g_FileManager.m_RadarcolMul.Start, g_FileManager.m_RadarcolMul.Size);
	}

	addr = (uint)g_FileManager.m_PaletteMul.Start;

	if (addr > 0 && addr != 0xFFFFFFFF)
		memcpy(m_Palette, (PVOID)addr, 256 * sizeof(PALETTE_BLOCK));
	else
		memset(m_Palette, 0, 256 * sizeof(PALETTE_BLOCK));
}
//----------------------------------------------------------------------------------
/*!
Патч блока цветов из вердаты
@param [__in] index Индекс в списке
@param [__in] group Указатель на цвета патча
@return 
*/
void CColorManager::SetHuesBlock(int index, PVERDATA_HUES_GROUP group)
{
	WISPFUN_DEBUG("c137_f2");
	if (index < 0 || index >= m_HuesCount)
		return;

	m_HuesRange[index].Header = group->Header;
	IFOR(i, 0, 8)
		memcpy(&m_HuesRange[index].Entries[i].ColorTable[0], &group->Entries[i].ColorTable[0], sizeof(ushort[32]));
}
//----------------------------------------------------------------------------------
/*!
Создание палитры цветов для шейдера
@return
*/
void CColorManager::CreateHuesPalette()
{
	WISPFUN_DEBUG("c137_f3");
	m_HuesFloat.resize(m_HuesCount);
	int entryCount = m_HuesCount / 8;

	IFOR(i, 0, entryCount)
	{
		IFOR(j, 0, 8)
		{
			FLOAT_HUES &fh = m_HuesFloat[(i * 8) + j];

			IFOR(h, 0, 32)
			{
				int idx = h * 3;

				ushort c = m_HuesRange[i].Entries[j].ColorTable[h];

				fh.Palette[idx] = (((c >> 10) & 0x1F) / 31.0f);
				fh.Palette[idx + 1] = (((c >> 5) & 0x1F) / 31.0f);
				fh.Palette[idx + 2] = ((c & 0x1F) / 31.0f);
			}
		}
	}
}
//----------------------------------------------------------------------------------
/*!
Отправка цветов в шейдер
@param [__in] color Индекс цвета
@return
*/
void CColorManager::SendColorsToShader(ushort color)
{
	WISPFUN_DEBUG("c137_f4");
	if (color != 0)
	{
		if (color & SPECTRAL_COLOR_FLAG)
			glUniform1fv(ShaderColorTable, 32 * 3, &m_HuesFloat[0].Palette[0]);
		else
		{
			if (color >= m_HuesCount)
			{
				color %= m_HuesCount;

				if (!color)
					color = 1;
			}

			glUniform1fv(ShaderColorTable, 32 * 3, &m_HuesFloat[color - 1].Palette[0]);
		}
	}
}
//----------------------------------------------------------------------------------
/*!
Конвертирование цвета из 16 бит в 32 бит
@param [__in] c 16-битный цвет
@return 32-битный цвет
*/
uint CColorManager::Color16To32(const ushort &c)
{
	return
	(
		(((c >> 10) & 0x1F) * 0xFF / 0x1F) |
		((((c >> 5) & 0x1F) * 0xFF / 0x1F) << 8) |
		(((c & 0x1F) * 0xFF / 0x1F) << 16)
	);
}
//----------------------------------------------------------------------------------
/*!
Конвертирование цвета из 32 бит в 16 бит
@param [__in] c 32-битный цвет
@return 16-битный цвет
*/
ushort CColorManager::Color32To16(const uint &c)
{
	return
	(
		((c & 0xFF) * 32) / 256) |
		(((((c >> 16) & 0xff) * 32) / 256) << 10) |
		(((((c >> 8) & 0xff) * 32) / 256) << 5
	);
}
//----------------------------------------------------------------------------------
/*!
Перевод в серый
@param [__in] c 16-битный цвет
@return 16-битный цвет
*/
ushort CColorManager::ConvertToGray(const ushort &c)
{
	return ((c & 0x1F) * 299 + ((c >> 5) & 0x1F) * 587 + ((c >> 10) & 0x1F) * 114) / 1000;
}
//----------------------------------------------------------------------------------
/*!
Получить 16-битный цвет
@param [__in] c Исходный цвет
@param [__in] color Индекс цвета в палитре
@return 16-битный цвет
*/
ushort CColorManager::GetColor16(const ushort &c, ushort color)
{
	WISPFUN_DEBUG("c137_f5");
	if (color != 0 && color < m_HuesCount)
	{
		color -= 1;
		int g = color / 8;
		int e = color % 8;

		return m_HuesRange[g].Entries[e].ColorTable[(c >> 10) & 0x1F];
	}

	return c;
}
//----------------------------------------------------------------------------------
/*!
Получить 16-битный цвет для радара
@param [__in] c Исходный 16-битный цвет
@return 16-битный цвет
*/
ushort CColorManager::GetRadarColorData(const ushort &c)
{
	WISPFUN_DEBUG("c137_f6");
	pushort ptr = (pushort)&m_Radarcol[0];
	return ptr[c];
}
//----------------------------------------------------------------------------------
/*!
Получить 32-битный цвет для радара
@param [__in] c Исходный 16-битный цвет
@return 32-битный цвет
*/
uint CColorManager::GetRadarColor(const ushort &c)
{
	WISPFUN_DEBUG("c137_f7");
	pushort ptr = (pushort)&m_Radarcol[0];
	return Color16To32(ptr[c]);
}
//----------------------------------------------------------------------------------
/*!
Получить 32-битный цвет без конвертирования входящего цвета
@param [__in] c Исходный 16-битный цвет
@param [__in] color Индекс цвета в палитре
@return 32-битный цвет
*/
uint CColorManager::GetPolygoneColor(ushort c, ushort color)
{
	WISPFUN_DEBUG("c137_f8");
	if (color != 0 && color < m_HuesCount)
	{
		color -= 1;
		int g = color / 8;
		int e = color % 8;

		return Color16To32(m_HuesRange[g].Entries[e].ColorTable[c]);
	}

	return 0xFF010101; //Black
}
//----------------------------------------------------------------------------------
/*!
Получить 32-битный цвет для Unicode-шрифтов
@param [__in] c Исходный 16-битный цвет
@param [__in] color Индекс цвета в палитре
@return 32-битный цвет
*/
uint CColorManager::GetUnicodeFontColor(ushort &c, ushort color)
{
	WISPFUN_DEBUG("c137_f9");
	if (color != 0 && color < m_HuesCount)
	{
		color -= 1;
		int g = color / 8;
		int e = color % 8;

		return Color16To32(m_HuesRange[g].Entries[e].ColorTable[8]);
	}

	return Color16To32(c);
}
//----------------------------------------------------------------------------------
/*!
Получить 32-битный цвет
@param [__in] c Исходный 16-битный цвет
@param [__in] color Индекс цвета в палитре
@return 32-битный цвет
*/
uint CColorManager::GetColor(ushort &c, ushort color)
{
	WISPFUN_DEBUG("c137_f10");
	if (color != 0 && color < m_HuesCount)
	{
		color -= 1;
		int g = color / 8;
		int e = color % 8;

		return Color16To32(m_HuesRange[g].Entries[e].ColorTable[(c >> 10) & 0x1F]);
	}

	return Color16To32(c);
}
//----------------------------------------------------------------------------------
/*!
Получить 32-битный цвет с учетом оттенков серого
@param [__in] c Исходный 16-битный цвет
@param [__in] color Индекс цвета в палитре
@return 32-битный цвет
*/
uint CColorManager::GetPartialHueColor(ushort &c, ushort color)
{
	WISPFUN_DEBUG("c137_f11");
	if (color != 0 && color < m_HuesCount)
	{
		color -= 1;
		int g = color / 8;
		int e = color % 8;

		uint cl = Color16To32(c);

		if (GetRValue(cl) == GetGValue(cl) && GetBValue(cl) == GetGValue(cl))
			return Color16To32(m_HuesRange[g].Entries[e].ColorTable[(c >> 10) & 0x1F]);

		return cl;
	}

	return Color16To32(c);
}
//----------------------------------------------------------------------------------
ushort CColorManager::FixColor(const ushort &color, const ushort &defaultColor)
{
	ushort fixedColor = color & 0x3FFF;

	if (fixedColor)
	{
		if (fixedColor >= 0x0BB8)
			fixedColor = 1;

		fixedColor |= (color & 0xC000);
	}
	else
	{
		fixedColor = defaultColor;
	}

	return fixedColor;
}
//----------------------------------------------------------------------------------
