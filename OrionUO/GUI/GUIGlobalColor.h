﻿/***********************************************************************************
**
** GUIGlobalColor.h
**
** Компонента для применения глобального цвета
**
** Copyright (C) December 2016 Hotride
**
************************************************************************************
*/

#ifndef GUIGLOBALCOLOR_H
#define GUIGLOBALCOLOR_H

class CGUIGlobalColor : public CBaseGUI
{
    //!R компонента цвета
    GLfloat R = 0.0f;

    //!G компонента цвета
    GLfloat G = 0.0f;

    //!B компонента цвета
    GLfloat B = 0.0f;

    //!A компонента цвета
    GLfloat A = 0.0f;

public:
    CGUIGlobalColor(bool enabled, GLfloat r, GLfloat g, GLfloat b, GLfloat a);
    virtual ~CGUIGlobalColor();

    virtual void Draw(bool checktrans = false);
};

#endif
