﻿/***********************************************************************************
**
** ContainerStack.h
**
** Copyright (C) September 2017 Hotride
**
************************************************************************************
*/
//----------------------------------------------------------------------------------
#ifndef CONTAINERSTACK_H
#define CONTAINERSTACK_H
//----------------------------------------------------------------------------------
//!Класс стека контейнеров, используется для хранения информации при загрузке гапмов контейнеров из конфига при входе в игру
class CContainerStackItem
{
public:
	uint Serial = 0;
	short X = 0;
	short Y = 0;
	short MinimizedX = 0;
	short MinimizedY = 0;
	bool Minimized = false;
	bool LockMoving = false;

	CContainerStackItem(const uint &serial, const short &x, const short &y, const short &minimizedX, const short &minimizedY, const bool &minimized, const bool &lockMoving);
	~CContainerStackItem() {}
};
//----------------------------------------------------------------------------------
//!Ссылка на стек открытия контейнеров
extern deque<CContainerStackItem> g_ContainerStack;

//!Таймер стека открытия контейнеров
extern uint g_CheckContainerStackTimer;
//----------------------------------------------------------------------------------
#endif //CONTAINERSTACK_H
//----------------------------------------------------------------------------------
