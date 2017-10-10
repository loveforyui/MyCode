#include "stdafx.h"
#include "MainManager.h"
#include "Object.h"
#include "player.h"
#include "BackGround.h"
#include "floor.h"

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
    GetClientRect(g_hWnd, &m_wndRect);
    m_wndLimitX = m_wndRect.left;
    m_wndLimitCX = m_wndLimitX + WINCX;

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
        OBJINFO tempObj(0.f, 0.f, 30.f, 40.f);
        m_pPlayer = new player;
        m_pPlayer->Initialize(tempObj);
    }
    m_gravity.addObject(m_pPlayer);

    // make line object
    COLORREF rgb;
    HDC hdc = GetDC(g_hWnd);
    m_hBackBuffer = CreateCompatibleDC(hdc);
    m_hBitmap = CreateCompatibleBitmap(hdc, 3800, m_wndRect.bottom);
    m_hOldmap = (HBITMAP)SelectObject(m_hBackBuffer, m_hBitmap);

    m_pStage->Render(m_hBackBuffer);
    //BitBlt(hdc, 0, 0, 3800, WINCY, m_hBackBuffer, 0, 0, SRCCOPY);
    /*for (FLOAT y = 100.f; y <= 266.f; ++y)
    {
        for (FLOAT x = 0.f; x <= 270.f; ++x)
        {
            rgb = GetPixel(hdc, INT(x), INT(y));
            if(0 < GetRValue(rgb))
            { 
                OBJINFO tempObj(x, y, 0.1f, 20.f);
                Floor* tempFloor = new Floor;
                tempFloor->Initialize(tempObj);
                dynamic_cast<BackGround*>(m_pStage)->m_vLineObj.push_back(tempFloor);
            }
        }
    }*/

    for (int x = 0; x < 3823; ++x)
    {
        for (int y = 100; y < 270; ++y)
        {
            rgb = GetPixel(m_hBackBuffer, INT(x), INT(y));
            if(255 == rgb)
            {
                dynamic_cast<BackGround*>(m_pStage)->m_vfStage.push_back(y);
            }
        }
    }
    DeleteObject(SelectObject(m_hBackBuffer, m_hOldmap));
    DeleteDC(m_hBackBuffer);
    ReleaseDC(g_hWnd, hdc);

    m_gravity.SetLine(&dynamic_cast<BackGround*>(m_pStage)->m_vfStage);
    dynamic_cast<player*>(m_pPlayer)->SetLine(&(dynamic_cast<BackGround*>(m_pStage)->m_vfStage));
}

void MainManager::Update()
{
    m_gravity.Update(); 
    m_pPlayer->Update();

    Collision(m_pPlayer, m_pStage);


    INT xr = (m_pPlayer->GetInfo().fX - (400*(5.f/8.f)));
    INT rx = (m_pPlayer->GetInfo().fX + (400*(5.f/8.f)));

    INT camMoxr = (m_pPlayer->GetInfo().fX + (WINCX*(2.f/3.f))/2);
    INT camMorx = (m_pPlayer->GetInfo().fX - 100);
    if (0 <= m_wndLimitX && m_wndLimitCX <= 3800)
    {
        if (m_pPlayer->GetDirection() == OBJ_D_RIGHT)
        {
            if (
                m_wndLimitX + (((m_wndLimitCX - m_wndLimitX) / 2)*(5.f / 8.f))
                <= m_pPlayer->GetInfo().fX)
            {
                m_wndLimitX += m_pPlayer->GetInfo().speed;
                m_wndLimitCX = m_wndLimitX + WINCX;
            }
        }
    }
}

void MainManager::Render()
{
    HDC hdc = GetDC(g_hWnd);

    m_hBackBuffer = CreateCompatibleDC(hdc);
    m_hBitmap = CreateCompatibleBitmap(hdc, 3800, m_wndRect.bottom);
    m_hOldmap = (HBITMAP)SelectObject(m_hBackBuffer, m_hBitmap);

    //PatBlt(m_hBackBuffer, 0, 0, WINCX, WINCY, BLACKNESS);
    
    //stage
    /*Graphics stage(m_hBackBuffer);
    Image iStage(L"../resource/background/stage01-01.png");
    stage.DrawImage(&iStage, 0, 25);*/
    m_pStage->Render(m_hBackBuffer);

    // draw white line
    /*for (vector<FLOAT>::size_type i = 0;
        i < dynamic_cast<BackGround*>(m_pStage)->m_vfStage.size(); ++i)
    {
        SetPixel(m_hBackBuffer, i, INT(dynamic_cast<BackGround*>(m_pStage)->m_vfStage[i]), RGB(255,255,255));
    }*/

    // player
    m_pPlayer->Render(m_hBackBuffer);

    StretchBlt(hdc, 0, 0, m_wndLimitCX*1.5, 208 * 1.5, m_hBackBuffer, m_wndLimitX, 0, m_wndLimitCX, 208, SRCCOPY);

    //BitBlt(hdc, 0, 0, 3800, WINCY, m_hBackBuffer, 0, 0, SRCCOPY);
    
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
        y = -(int)(sin(f*3.14 / 180) * 100);
        SetPixel(m_hdc, (int)f, y, RGB(0, 0, 0));
    }
}

BOOL MainManager::Collision(Object * dst, Object * src)
{
    return (*dst)||(*src);
}

BOOL MainManager::CollisionO(Object * dst, Object * src)
{
    return (*dst)&&(*src);
}

MainManager * MainManager::GetInst()
{
    if (!inst)
    {
        inst = new MainManager;
    }

    return inst;
}
