#include "stdafx.h"
#include "MainManager.h"
#include <math.h>

MainManager* MainManager::inst = nullptr;

MainManager::MainManager()
{
}


MainManager::~MainManager()
{
    Release();
}

void MainManager::Initialize()
{
    m_hdc = GetDC(g_hWnd);
    GetClientRect(g_hWnd, &m_wndRect);
    SetMapMode(m_hdc, MM_LOENGLISH);
    SetViewportOrgEx(m_hdc, m_wndRect.left, m_wndRect.bottom, NULL);
}

void MainManager::Release()
{
    ReleaseDC(g_hWnd, m_hdc);
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

MainManager * MainManager::GetInst()
{
    if (!inst)
    {
        inst = new MainManager;
    }

    return inst;
}
