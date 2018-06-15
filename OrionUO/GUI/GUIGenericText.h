﻿/***********************************************************************************
**
** GUIGenericText.h
**
** Компонента текста для гампов от сервера
**
** Copyright (C) August 2016 Hotride
**
************************************************************************************
*/

#ifndef GUIGENERICTEXT_H
#define GUIGENERICTEXT_H

class CGUIGenericText : public CGUIText
{
public:
    //!Индекс текста
    uint TextID = 0;

    //!Максимальная ширина (для CroppedText)
    int MaxWidth = 0;

    CGUIGenericText(int index, ushort color, int x, int y, int maxWidth = 0);
    virtual ~CGUIGenericText();

    void CreateTexture(const wstring &str);
};

#endif
