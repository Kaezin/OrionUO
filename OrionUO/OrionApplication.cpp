﻿/***********************************************************************************
**
** OrionApplication.cpp
**
** Copyright (C) August 2016 Hotride
**
************************************************************************************
*/

#include "stdafx.h"

COrionApplication g_App;

void COrionApplication::OnMainLoop()
{
    WISPFUN_DEBUG("c193_f1");

    g_Ticks = timeGetTime();

    if (NextRenderTime <= g_Ticks)
    {
        NextUpdateTime = g_Ticks + 50;
        NextRenderTime = NextUpdateTime; // g_Ticks + g_OrionWindow.RenderTimerDelay;

        //g_Orion.Process(true);
        g_ConnectionManager.Recv();
        g_PacketManager.ProcessPluginPackets();
        g_PacketManager.SendMegaClilocRequests();
    }
    else if (NextUpdateTime <= g_Ticks)
    {
        NextUpdateTime = g_Ticks + 50;

        //g_Orion.Process(false);
        g_ConnectionManager.Recv();
        g_PacketManager.ProcessPluginPackets();
        g_PacketManager.SendMegaClilocRequests();
    }
    //else
    //	Sleep(1);
}
