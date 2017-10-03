#include "stdafx.h"
#include "EriIdle.h"
#include "Object.h"
#include "player.h"


EriIdle::EriIdle()
{
    m_path = L"../resource/eri/standing/body/01.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/eri/standing/body/02.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/eri/standing/body/03.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/eri/standing/body/04.png";
    m_vImage.push_back(new Image(m_path));

    iter = m_vImage.begin();
    isRev = false;
}

EriIdle::~EriIdle()
{
}

void EriIdle::handle(HDC hdc)
{
    //m_hdc = GetDC(g_hWnd);

    Graphics graphics(hdc);

    if (iter == m_vImage.end())
    {
        isRev = true;
        --iter;
    }
    else if (iter == m_vImage.begin())
    {
        isRev = false;
    }

    graphics.DrawImage(*iter, m_pObj->GetInfo().fX - 17, m_pObj->GetInfo().fY - 18);

    if (isRev)
    {
        --iter;
    }
    else
    {
        ++iter;
    }
}
