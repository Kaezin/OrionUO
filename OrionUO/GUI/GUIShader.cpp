﻿/***********************************************************************************
**
** GUIShader.cpp
**
** Copyright (C) August 2016 Hotride
**
************************************************************************************
*/

#include "stdafx.h"

CGUIShader::CGUIShader(CGLShader *shader, bool enabled)
    : CBaseGUI(GOT_SHADER, 0, 0, 0, 0, 0)
    , m_Shader(shader)
{
    Enabled = enabled;
}

CGUIShader::~CGUIShader()
{
}

void CGUIShader::Draw(bool checktrans)
{
    WISPFUN_DEBUG("c72_f1");
    if (Enabled && m_Shader != NULL)
        m_Shader->Use();
    else
        UnuseShader();
}
