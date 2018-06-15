﻿/***********************************************************************************
**
** GUIDataBox.h
**
** Компонента для хранения каких-либо данных.
** Используется для хранения динамических данных, например: содержимое контейнеров, списки строк (журнала), списки объектов.
**
** Copyright (C) August 2016 Hotride
**
************************************************************************************
*/

#ifndef GUIDATABOX_H
#define GUIDATABOX_H

class CGUIDataBox : public CGUIPolygonal
{
public:
    CGUIDataBox();
    virtual ~CGUIDataBox();

    virtual void PrepareTextures();

    virtual bool EntryPointerHere();

    virtual bool Select() { return true; }
};

#endif
