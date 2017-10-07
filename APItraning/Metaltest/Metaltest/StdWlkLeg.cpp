#include "stdafx.h"
#include "StdWlkLeg.h"


StdWlkLeg::StdWlkLeg()
{
    // right
    m_path = L"../resource/std_leg/wlk_leg/std_wlk_leg_0000.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/std_leg/wlk_leg/std_wlk_leg_0001.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/std_leg/wlk_leg/std_wlk_leg_0002.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/std_leg/wlk_leg/std_wlk_leg_0003.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/std_leg/wlk_leg/std_wlk_leg_0004.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/std_leg/wlk_leg/std_wlk_leg_0005.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/std_leg/wlk_leg/std_wlk_leg_0006.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/std_leg/wlk_leg/std_wlk_leg_0007.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/std_leg/wlk_leg/std_wlk_leg_0008.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/std_leg/wlk_leg/std_wlk_leg_0009.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/std_leg/wlk_leg/std_wlk_leg_0010.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/std_leg/wlk_leg/std_wlk_leg_0011.png";
    m_vImage.push_back(new Image(m_path));
    // left
    m_path = L"../resource/std_leg/wlk_leg/std_wlk_leg_left_0000.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/std_leg/wlk_leg/std_wlk_leg_left_0001.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/std_leg/wlk_leg/std_wlk_leg_left_0002.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/std_leg/wlk_leg/std_wlk_leg_left_0003.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/std_leg/wlk_leg/std_wlk_leg_left_0004.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/std_leg/wlk_leg/std_wlk_leg_left_0005.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/std_leg/wlk_leg/std_wlk_leg_left_0006.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/std_leg/wlk_leg/std_wlk_leg_left_0007.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/std_leg/wlk_leg/std_wlk_leg_left_0008.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/std_leg/wlk_leg/std_wlk_leg_left_0009.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/std_leg/wlk_leg/std_wlk_leg_left_0010.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/std_leg/wlk_leg/std_wlk_leg_left_0011.png";
    m_vImagf.push_back(new Image(m_path));

    itef = m_vImagf.begin();
    isRev = false;

    iter = m_vImage.begin();
    isRev = false;
}


StdWlkLeg::~StdWlkLeg()
{
}

void StdWlkLeg::handle(HDC hdc)
{
    Graphics graphics(hdc);

    if (iter == m_vImage.end())
    {
        iter = m_vImage.begin();
    }

    graphics.DrawImage(*iter
            , m_pObj->GetInfo().rect.left   - 4
            , m_pObj->GetInfo().rect.top    + ((IMGCY/3))
            , IMGCX
            , IMGCY);
    //graphics.DrawImage(*iter, m_pObj->GetInfo().fX - 21, m_pObj->GetInfo().fY - 4);

    ++iter;
}

void StdWlkLeg::handlf(HDC hdc)
{
    Graphics graphics(hdc);

    if (itef == m_vImagf.end())
    {
        itef = m_vImagf.begin();
    }

    graphics.DrawImage(*itef
            , m_pObj->GetInfo().rect.left   + 4
            , m_pObj->GetInfo().rect.top    + ((IMGCY/3))
            , IMGCX
            , IMGCY);
    //graphics.DrawImage(*iter, m_pObj->GetInfo().fX - 21, m_pObj->GetInfo().fY - 4);

    ++itef;
}
