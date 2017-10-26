#include "stdafx.h"
#include "MainGame.h"
#include "BackGround.h"
#include "Player.h"
#include "Mouse.h"

#define PATH_RC "../resource/"

CMainGame::CMainGame()
{
}


CMainGame::~CMainGame()
{
    Release();
}

void CMainGame::Initialize()
{
    // GDI+ setting
    GdiplusStartup(&m_GdiplusToken, &m_GdiplusStartI, nullptr);

    // Window Rect
    GetClientRect(g_hWnd, &m_wndRect);

    // DC Setting
    m_hdc = GetDC(g_hWnd);

    // Timer Setting
    m_dwOldT = GetTickCount();
    m_dwCurT = 0;

    //default val initialize
    m_bSelect_hud = 0x00000;
    CObjManager::GetInst()->LoadData();


    CSceneMgr::GetInstance()->SceneChange(CSceneMgr::LOGO);   
}

void CMainGame::Release()
{
    CSceneMgr::GetInstance()->DestroyInstance();
    CKeyManager::GetInst()->Destroy();
    CImageMgr::GetInst()->DestroyInstance();
    CObjManager::GetInst()->Destroy();
    CLineMgr::GetInstance()->DestroyInstance();
    CScrollMgr::GetInstance()->DestroyInstance();
}

void CMainGame::Render()
{
    HDC hdc = GetDC(g_hWnd);
    m_hdc = CreateCompatibleDC(hdc);
    m_hBitmap = CreateCompatibleBitmap(hdc, 3823, WINCY);
    m_hOldmap = (HBITMAP)SelectObject(m_hdc, m_hBitmap);
    
    CSceneMgr::GetInstance()->Render(m_hdc);
    CLineMgr::GetInstance()->Render(m_hdc);

    float fScrollX = CScrollMgr::GetInstance()->GetScrollX();

    DeleteObject(SelectObject(m_hdc, m_hOldmap));
    DeleteDC(m_hdc);
    ReleaseDC(g_hWnd, hdc);
}

void CMainGame::Update()
{
    CSceneMgr::GetInstance()->Update();

    CKeyManager::GetInst()->Update();
}

