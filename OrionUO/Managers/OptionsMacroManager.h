﻿/***********************************************************************************
**
** OptionsMacroManager.h
**
** Copyright (C) August 2016 Hotride
**
************************************************************************************
*/

#ifndef OPTIONSMACROMANAGER_H
#define OPTIONSMACROMANAGER_H

//!Класс менеджера макросов для опций
class COptionsMacroManager : public CBaseQueue
{
public:
    COptionsMacroManager();
    virtual ~COptionsMacroManager();

    /*!
	Загрузить из списка макросов
	@return 
	*/
    void LoadFromMacro();
};

//!Ссылка на менеджер макросов для опций
extern COptionsMacroManager g_OptionsMacroManager;

#endif
