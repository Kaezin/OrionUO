﻿/***********************************************************************************
**
** GUIBuff.h
**
** Компонента иконки баффа
**
** Copyright (C) August 2016 Hotride
**
************************************************************************************
*/

#ifndef GUIBUFF_H
#define GUIBUFF_H

class CGUIBuff : public CGUIDrawObject
{
public:
    //!Время жизни
    uint Timer = 0;

    //!Текст баффа для отображения
    wstring Text = L"";

    //!Таймер всплывающей подсказки
    uint TooltipTimer = 0;

    //!Флаг для уменьшения альфа-канала
    bool DecAlpha = true;

    //!Текущее значение альфа-канала
    uchar Alpha = 0xFF;

    CGUIBuff(ushort graphic, int timer, const wstring &text);
    virtual ~CGUIBuff();

    virtual void Draw(bool checktrans = false);
};

#endif
