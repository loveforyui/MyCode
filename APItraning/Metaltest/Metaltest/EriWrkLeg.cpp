#include "stdafx.h"
#include "EriWrkLeg.h"


EriWrkLeg::EriWrkLeg()
{
    m_path = L"../resource/eri/working/wrk_leg/wrk_leg_04.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/eri/working/wrk_leg/wrk_leg_05.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/eri/working/wrk_leg/wrk_leg_06.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/eri/working/wrk_leg/wrk_leg_07.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/eri/working/wrk_leg/wrk_leg_08.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/eri/working/wrk_leg/wrk_leg_09.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/eri/working/wrk_leg/wrk_leg_10.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/eri/working/wrk_leg/wrk_leg_11.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/eri/working/wrk_leg/wrk_leg_12.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/eri/working/wrk_leg/wrk_leg_13.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/eri/working/wrk_leg/wrk_leg_14.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/eri/working/wrk_leg/wrk_leg_15.png";
    m_vImage.push_back(new Image(m_path));

    iter = m_vImage.begin();
    isRev = false;
}


EriWrkLeg::~EriWrkLeg()
{
}

void EriWrkLeg::handle(HDC hdc)
{
    Graphics graphics(hdc);

    if (iter == m_vImage.end())
    {
        iter = m_vImage.begin();
    }

    graphics.DrawImage(*iter, FLOAT(m_pObj->GetInfo().rect.left - 4), FLOAT(m_pObj->GetInfo().rect.top + 13));
    //graphics.DrawImage(*iter, m_pObj->GetInfo().fX - 21, m_pObj->GetInfo().fY - 4);

    ++iter;
}
