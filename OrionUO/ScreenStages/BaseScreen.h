

#ifndef BASESCREEN_H
#define BASESCREEN_H

class CBaseScreen : public CBaseQueue
{
public:
    uchar SmoothScreenAction = 0;
    ushort CursorGraphic = 0x2073;

protected:
    CGump &m_Gump;

public:
    CBaseScreen(CGump &gump);
    virtual ~CBaseScreen() {}

    virtual void PrepareContent() { m_Gump.PrepareContent(); }

    virtual void UpdateContent() { m_Gump.UpdateContent(); }

    virtual void Init() {}

    virtual void InitToolTip() { m_Gump.InitToolTip(); }

    virtual void Render(bool mode);

    virtual void CreateSmoothAction(uchar action);

    virtual void ProcessSmoothAction(uchar action = 0xFF) {}

    virtual int DrawSmoothMonitor();

    virtual void DrawSmoothMonitorEffect();

    virtual void OnLeftMouseButtonDown() { m_Gump.OnLeftMouseButtonDown(); }
    virtual void OnLeftMouseButtonUp()
    {
        m_Gump.OnLeftMouseButtonUp();
        m_Gump.WantRedraw = true;
    }
    virtual bool OnLeftMouseButtonDoubleClick() { return m_Gump.OnLeftMouseButtonDoubleClick(); }
    virtual void OnRightMouseButtonDown() { m_Gump.OnRightMouseButtonDown(); }
    virtual void OnRightMouseButtonUp() { m_Gump.OnRightMouseButtonUp(); }
    virtual bool OnRightMouseButtonDoubleClick() { return m_Gump.OnRightMouseButtonDoubleClick(); }
    virtual void OnMidMouseButtonDown() { m_Gump.OnMidMouseButtonDown(); }
    virtual void OnMidMouseButtonUp() { m_Gump.OnMidMouseButtonUp(); }
    virtual bool OnMidMouseButtonDoubleClick() { return m_Gump.OnMidMouseButtonDoubleClick(); }
    virtual void OnMidMouseButtonScroll(bool up) { m_Gump.OnMidMouseButtonScroll(up); }
    virtual void OnDragging() { m_Gump.OnDragging(); }
    virtual void OnCharPress(const WPARAM &wParam, const LPARAM &lParam)
    {
        m_Gump.OnCharPress(wParam, lParam);
    }
    virtual void OnKeyDown(const WPARAM &wParam, const LPARAM &lParam)
    {
        m_Gump.OnKeyDown(wParam, lParam);
    }
    virtual void OnKeyUp(const WPARAM &wParam, const LPARAM &lParam)
    {
        m_Gump.OnKeyUp(wParam, lParam);
    }
};

extern CBaseScreen *g_CurrentScreen;

#endif
