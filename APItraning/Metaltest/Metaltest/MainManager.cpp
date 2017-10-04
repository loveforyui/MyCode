#include "stdafx.h"
#include "MainManager.h"
#include "Object.h"
#include "player.h"
#include "BackGround.h"

MainManager* MainManager::inst = nullptr;

MainManager::MainManager()
    : m_pPlayer(nullptr)
{
}


MainManager::~MainManager()
{
    Release();
}

void MainManager::Initialize()
{
    //gdi+ set
    GdiplusStartupInput         m_GdiplusStartupInput;
    ULONG_PTR                   m_GdiplusToken;
    GdiplusStartup(&m_GdiplusToken, &m_GdiplusStartupInput, NULL);

    // screen initialize
    m_hdc = GetDC(g_hWnd);
    //m_hBackBuffer = CreateCompatibleDC(m_hdc);
    //m_hBitmap = LoadBitmap(hInst, MAKEINTRESOURCE(m_hBackBuffer));
    //SelectObject(m_hBackBuffer, (HBITMAP)m_hBitmap);
    //ReleaseDC(g_hWnd, m_hdc);
    GetClientRect(g_hWnd, &m_wndRect);    

    // background Initailize
    if (!m_pStage)
    {
        OBJINFO tempObj(1900.f, 150.f, FLOAT(3800), 300.f);
        m_pStage = new BackGround;
        m_pStage->Initialize(tempObj);
    }

    //player initailize
    if (!m_pPlayer)
    {
        OBJINFO tempObj(100.f, 100.f, 36.f, 50.f);
        m_pPlayer = new player;
        m_pPlayer->Initialize(tempObj);
    }
    m_gravity.addObject(m_pPlayer);

}

void MainManager::Update()
{
    m_gravity.Update();
    m_pPlayer->Update();
    Collision(m_pPlayer, m_pStage);
}

void MainManager::Render()
{
    HDC hdc = GetDC(g_hWnd);
    //Rectangle(hdc, m_wndRect.left, m_wndRect.top, m_wndRect.right, m_wndRect.bottom);
    /*Graphics graphics(m_hdc);
    Image   image(L"working_body_0012.png");
    graphics.DrawImage(&image, 100, 100);*/
    m_hBackBuffer = CreateCompatibleDC(hdc);
    m_hBitmap = CreateCompatibleBitmap(hdc, 3800, m_wndRect.bottom);
    m_hOldmap = (HBITMAP)SelectObject(m_hBackBuffer, m_hBitmap);

    //PatBlt(m_hBackBuffer, 0, 0, WINCX, WINCY, BLACKNESS);
    
    //stage
    /*Graphics stage(m_hBackBuffer);
    Image iStage(L"../resource/background/stage01-01.png");
    stage.DrawImage(&iStage, 0, 25);*/
    m_pStage->Render(m_hBackBuffer);

    // player
    m_pPlayer->Render(m_hBackBuffer);
    
    BitBlt(hdc, 0, 0, 3800, WINCY, m_hBackBuffer, 0, 0, SRCCOPY);
    DeleteObject(SelectObject(m_hBackBuffer, m_hOldmap));
    DeleteDC(m_hBackBuffer);
    ReleaseDC(g_hWnd, hdc);
}

void MainManager::Release()
{
    ReleaseDC(g_hWnd, m_hdc);
    SafeDelete<Object*>(m_pPlayer);
    
}

void MainManager::DrawSin()
{
    MoveToEx(m_hdc, -2000, 0, nullptr);
    LineTo(m_hdc, 2000, 0);
    MoveToEx(m_hdc, 0, -2000, nullptr);
    LineTo(m_hdc, 0, 2000);

    for (f = -500; f < 1000; ++f)
    {
        y = (int)(sin(f*3.14 / 180) * 100);
        SetPixel(m_hdc, (int)f, y, RGB(0, 0, 0));
    }
}

BOOL MainManager::Collision(Object * dst, Object * src)
{
    return (*dst)||(*src);
}

MainManager * MainManager::GetInst()
{
    if (!inst)
    {
        inst = new MainManager;
    }

    return inst;
}
