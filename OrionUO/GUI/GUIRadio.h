﻿/***********************************************************************************
**
** GUIRadio.h
**
** Компонента для отображения радио-кнопок
**
** Copyright (C) August 2016 Hotride
**
************************************************************************************
*/

#ifndef GUIRADIO_H
#define GUIRADIO_H

class CGUIRadio : public CGUICheckbox
{
public:
    CGUIRadio(
        int serial, ushort graphic, ushort graphicChecked, ushort graphicDisabled, int x, int y);
    virtual ~CGUIRadio();
};

#endif
