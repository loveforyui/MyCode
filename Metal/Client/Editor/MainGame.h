#pragma once

class CMyEdit;
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

private:
    HDC m_hdc;
    RECT m_wndRect;
    
    DWORD m_dwOldt;
    DWORD m_dwCurt;

    HBITMAP m_hBitmap;
    HBITMAP m_hOldmap;
    GdiplusStartupInput m_GdiplusStartI;
    ULONG_PTR m_GdiplusToken;

    CMyEdit* m_edit;
};