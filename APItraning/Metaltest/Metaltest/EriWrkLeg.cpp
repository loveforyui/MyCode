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

    m_path = L"../resource/eri/working/wrk_leg_left/wrk_leg_left_0000.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/eri/working/wrk_leg_left/wrk_leg_left_0001.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/eri/working/wrk_leg_left/wrk_leg_left_0002.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/eri/working/wrk_leg_left/wrk_leg_left_0003.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/eri/working/wrk_leg_left/wrk_leg_left_0004.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/eri/working/wrk_leg_left/wrk_leg_left_0005.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/eri/working/wrk_leg_left/wrk_leg_left_0006.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/eri/working/wrk_leg_left/wrk_leg_left_0007.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/eri/working/wrk_leg_left/wrk_leg_left_0008.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/eri/working/wrk_leg_left/wrk_leg_left_0009.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/eri/working/wrk_leg_left/wrk_leg_left_0010.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/eri/working/wrk_leg_left/wrk_leg_left_0011.png";
    m_vImagf.push_back(new Image(m_path));

    itef = m_vImagf.begin();
    isRev = false;

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

    graphics.DrawImage(*iter
            , m_pObj->GetInfo().rect.left   - 4
            , m_pObj->GetInfo().rect.top + ((IMGCY/3) + 3)
            , IMGCX
            , IMGCY);
    //graphics.DrawImage(*iter, m_pObj->GetInfo().fX - 21, m_pObj->GetInfo().fY - 4);

    ++iter;
}

void EriWrkLeg::handlf(HDC hdc)
{
    Graphics graphics(hdc);

    if (itef == m_vImagf.end())
    {
        itef = m_vImagf.begin();
    }

    graphics.DrawImage(*itef
            , m_pObj->GetInfo().rect.left   + 4
            , m_pObj->GetInfo().rect.top + ((IMGCY/3) + 3)
            , IMGCX
            , IMGCY);
    //graphics.DrawImage(*iter, m_pObj->GetInfo().fX - 21, m_pObj->GetInfo().fY - 4);

    ++itef;
}
