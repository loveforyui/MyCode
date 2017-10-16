#pragma once

class CMainGame
{
public:
    CMainGame();
    ~CMainGame();

public:
    void Initialize();
    void Release();
    void Render();
    void Update();

    // render functions
public:
    void CharacterSelect_R(HDC hdc);

    // update functions
public:
    void CharacterSelect_U();

private:
    // DC
    HDC                     m_hdc;

    // Window Rect
    RECT                    m_wndRect;

    // processing time
    DWORD                   m_dwOldT;
    DWORD                   m_dwCurT;

    // Image
    HBITMAP                 m_hBitmap;
    HBITMAP                 m_hOldmap;
    GdiplusStartupInput     m_GdiplusStartI;
    ULONG_PTR               m_GdiplusToken;
    map<UINT, Image*>       m_imgSelect;

    // GameState
    eGameState              m_GameState;
    UINT                    m_bSelect_hud;

    // OBJLIST
    list<CObj*>             m_objLst[OBJ_END];
};

