#pragma once
#include "stdafx.h"
#include "MainGame.h"
#include "MyEdit.h"
#include "Obj.h"
#include "Mouse.h"
#include "BackGround.h"



CMainGame::CMainGame()
{

}

CMainGame::~CMainGame()
{
    Release();
}

void CMainGame::Initialize()
{
    GdiplusStartup(&m_GdiplusToken, &m_GdiplusStartI, nullptr);

    GetClientRect(g_hWnd, &m_wndRect);

    m_hdc = GetDC(g_hWnd);

    m_dwOldt = GetTickCount();
    m_dwCurt = 0;

    char fullPath[256] = "";
    sprintf_s(fullPath, "%s%s", PATH_RC, "background/");
    IMG_LOAD(L"BackGround", fullPath);

    if (OBJ_MGR_GETLIST(OBJ_MOUSE).empty())
    {
        OBJ_MGR_GETLIST(OBJ_MOUSE).push_back(CAbstractFactory<CMouse>::CreateObj());
    }

    if (OBJ_MGR_GETLIST(OBJ_BACKGROUD).empty())
    {
        vector<ObjImg*>* objimg = IMG_GET_V(L"BackGround");
        OBJ_MGR_GETLIST(OBJ_BACKGROUD).push_back(CAbstractFactory<CBackGround>::CreateObj(objimg));
    }

    m_edit = new CMyEdit;
    m_edit->Initialize();

    
}

void CMainGame::Release()
{
    SafeDelete<CMyEdit*>(m_edit);
    CObjManager::   GetInst()->Destroy();
    CKeyManager::   GetInst()->Destroy();
    CImageMgr::     GetInst()->Release();
    CScrollMgr::    GetInstance()->DestroyInstance();
}
void CMainGame::Render()
{
    HDC hdc     = GetDC(g_hWnd);
    m_hdc       = CreateCompatibleDC(hdc);
    m_hBitmap   = CreateCompatibleBitmap(hdc, 3823, WINCY);
    m_hOldmap   = (HBITMAP)SelectObject(m_hdc, m_hBitmap);

    Rectangle(m_hdc, 0, 0, 3823, WINCY);

    CObjManager::GetInst()->Render(m_hdc);
    CLineMgr::GetInstance()->Render(m_hdc);
    m_edit->Render(m_hdc);    

    float fScrollX = CScrollMgr::GetInstance()->GetScrollX();    
    
    RECT rc = {-fScrollX, 0, WINCX - fScrollX, WINCY};

    StretchBlt(hdc
        , 0, 0//* 1.92f , 0
        , WINCX//*1.92f 
        , WINCY//*1.92f
        , m_hdc
        , rc.left, rc.top
        , rc.right - rc.left, rc.bottom - rc.top
        , SRCCOPY);

    //StretchBlt(hdc
    //    , fScrollX*1.92f, 0//* 1.92f , 0
    //    , 3823//*1.92f 
    //    , WINCY//*1.92f
    //    , m_hdc
    //    , 0, 0
    //    , 3823, WINCY
    //    , SRCCOPY);

    DeleteObject(SelectObject(m_hdc, m_hOldmap));
    DeleteDC(m_hdc);
    ReleaseDC(g_hWnd, hdc);
}
void CMainGame::Update()
{
    CScrollMgr::    GetInstance()->Update();

    m_edit->Update();

    CObjManager::   GetInst()->Update();

    CKeyManager::   GetInst()->Update();
}

