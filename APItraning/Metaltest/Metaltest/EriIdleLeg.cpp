#include "stdafx.h"
#include "EriIdleLeg.h"


EriIdleLeg::EriIdleLeg()
{
    m_path = L"../resource/eri/standing/leg/05_leg_R.png";
    m_vImage.push_back(new Image(m_path));

    m_path = L"../resource/eri/standing/leg_left/05_leg_L.png";
    m_vImagf.push_back(new Image(m_path));

    iter    = m_vImage.begin();
    itef    = m_vImagf.begin();
    isRev   = false;
    isRevf  = false;
}


EriIdleLeg::~EriIdleLeg()
{
}

void EriIdleLeg::handle(HDC hdc)
{
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

    graphics.DrawImage(*iter
            , m_pObj->GetInfo().rect.left   - 3
            , m_pObj->GetInfo().rect.top + ((IMGCY/3) + 2)
            , IMGCX
            , IMGCY);

    if (isRev)
    {
        if(iter != m_vImage.begin())
            --iter;

        if (iter == m_vImage.begin())
        {
            isDone = true;
        }
    }
    else
    {
        ++iter;
    }
}

void EriIdleLeg::handlf(HDC hdc)
    {
        Graphics graphics(hdc);

        if (itef == m_vImagf.end())
        {
            isRevf = true;
            --itef;
        }
        else if (itef == m_vImagf.begin())
        {
            isRevf = false;
        }

        graphics.DrawImage(*itef
            , m_pObj->GetInfo().rect.left   + 3
            , m_pObj->GetInfo().rect.top + ((IMGCY/3) + 2)
            , IMGCX
            , IMGCY);

        if (isRevf)
        {
            if(itef != m_vImagf.begin())
                --itef;

            if (itef == m_vImagf.begin())
            {
                isDone = true;
            }
        }
        else
        {
            ++itef;
        }
    }
