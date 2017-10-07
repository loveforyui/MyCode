#include "stdafx.h"
#include "StdLeg.h"


StdLeg::StdLeg()
{
    m_path = L"../resource/std_leg/st_leg/st_leg.png";
    m_vImage.push_back(new Image(m_path));

    m_path = L"../resource/std_leg/st_leg/st_left.png";
    m_vImagf.push_back(new Image(m_path));

    iter    = m_vImage.begin();
    itef    = m_vImagf.begin();
    isRev   = false;
    isRevf  = false;
}


StdLeg::~StdLeg()
{
}

void StdLeg::handle(HDC hdc)
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
            , m_pObj->GetInfo().rect.left   
            , m_pObj->GetInfo().rect.top + ((IMGCY/3))
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

void StdLeg::handlf(HDC hdc)
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
        , m_pObj->GetInfo().rect.left + 7
        , m_pObj->GetInfo().rect.top + ((IMGCY / 3))
        , IMGCX
        , IMGCY);

    if (isRevf)
    {
        if (itef != m_vImagf.begin())
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
