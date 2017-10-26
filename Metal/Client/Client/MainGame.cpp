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

    float fScrollX = CScrollMgr::GetInstance()->GetScrollX();

    DeleteObject(SelectObject(m_hdc, m_hOldmap));
    DeleteDC(m_hdc);
    ReleaseDC(g_hWnd, hdc);
}

void CMainGame::Update()
{
    //switch (m_GameState)
    //{
    //case GS_START:
    //{
    //    // Image Loading
    //    char fullPath[256] = "";
    //    // Hud/select Img Loadinng
    //    sprintf_s(fullPath, "%s%s", PATH_RC, "hud/select/");
    //    IMG_LOAD(L"hud/select", fullPath);
    //
    //    // BackGround Img Loading
    //    sprintf_s(fullPath, "%s%s", PATH_RC, "background/");
    //    IMG_LOAD(L"BackGround", fullPath);
    //
    //    // Player Img Loading
    //    sprintf_s(fullPath, "%s%s", PATH_RC, "fio/st/body/");
    //    IMG_LOAD(L"fio/stand_r", fullPath);
    //    sprintf_s(fullPath, "%s%s", PATH_RC, "fio/st/body_left/");
    //    IMG_LOAD(L"fio/stand_l", fullPath);
    //    sprintf_s(fullPath, "%s%s", PATH_RC, "fio/st/leg/");
    //    IMG_LOAD(L"fio/stand_leg", fullPath);
    //
    //    // BackGround Setting
    //    if (OBJ_MGR_GETLIST(OBJ_BACKGROUD).empty())
    //    {
    //        vector<ObjImg*>* objimg = IMG_GET_V(L"BackGround");
    //        OBJ_MGR_GETLIST(OBJ_BACKGROUD).push_back(CAbstractFactory<CBackGround>::CreateObj(objimg));
    //    }
    //    if (OBJ_MGR_GETLIST(OBJ_MOUSE).empty())
    //    {
    //        //vector<ObjImg*>* objimg = IMG_GET_V(L"BackGround");
    //        OBJ_MGR_GETLIST(OBJ_MOUSE).push_back(CAbstractFactory<CMouse>::CreateObj());
    //    }
    //}
    //    break;
    //case GS_LOAD:
    //{
    //    
    //}
    //    break;
    //case GS_SELECT:
    //{
    //    CharacterSelect_U();
    //}
    //    break;
    //case GS_RUN:
    //    CObjManager::GetInst()->Update();
    //    CScrollMgr::GetInstance()->Update();
    //    break;
    //case GS_END:
    //    break;
    //default:
    //    break;
    //}

    CSceneMgr::GetInstance()->Update();

    CKeyManager::GetInst()->Update();
}

