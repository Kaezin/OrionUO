﻿/***********************************************************************************
**
** CustomHouseMultiObject.h
**
** Copyright (C) September 2017 Hotride
**
************************************************************************************
*/
//----------------------------------------------------------------------------------
#ifndef CUSTOMHOUSEMULTIOBJECT_H
#define CUSTOMHOUSEMULTIOBJECT_H
//----------------------------------------------------------------------------------
enum CUSTOM_HOUSE_MULTI_OBJECT_FLAGS
{
	CHMOF_INTERNAL = 0x01,
	CHMOF_GENERIC_INTERNAL = 0x02,
	CHMOF_STAIR = 0x08,
	CHMOF_TRANSPARENT = 0x04,
	CHMOF_IGNORE_IN_RENDER = 0x10
};
//----------------------------------------------------------------------------------
//Объект для мульти-объекта
class CCustomHouseMultiObject : public CMultiObject
{
	SETGET(int, Dbg, 0);

public:
	CCustomHouseMultiObject(const ushort &graphic, const ushort &color, const short &x, const short &y, const char &z, const uint &flags);
	virtual ~CCustomHouseMultiObject();

	//Это объект мульти для кастомных домов
	virtual bool IsCustomHouseMulti() { return true; }
};
//----------------------------------------------------------------------------------
#endif //CUSTOMHOUSEMULTIOBJECT_H
//----------------------------------------------------------------------------------
