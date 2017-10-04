#include "stdafx.h"
#include "EriIdleLeg.h"


EriIdleLeg::EriIdleLeg()
{
    m_path = L"../resource/eri/standing/leg/05.png";
    m_vImage.push_back(new Image(m_path));

    iter = m_vImage.begin();
    isRev = false;
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

    graphics.DrawImage(*iter, FLOAT(m_pObj->GetInfo().rect.left + 4), FLOAT(m_pObj->GetInfo().rect.top + 18));
    //graphics.DrawImage(*iter, m_pObj->GetInfo().fX - 13, m_pObj->GetInfo().fY);

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
