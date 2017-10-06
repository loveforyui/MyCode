#include "stdafx.h"
#include "EriStJmpLeg.h"


EriStJmpLeg::EriStJmpLeg()
{
    m_path = L"../resource/eri/jump/st_jmp/leg/st_jmp_leg_0000.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/eri/jump/st_jmp/leg/st_jmp_leg_0001.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/eri/jump/st_jmp/leg/st_jmp_leg_0002.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/eri/jump/st_jmp/leg/st_jmp_leg_0003.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/eri/jump/st_jmp/leg/st_jmp_leg_0004.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/eri/jump/st_jmp/leg/st_jmp_leg_0005.png";
    m_vImage.push_back(new Image(m_path));

    m_path = L"../resource/eri/jump/st_jmp/leg_left/st_jmp_leg_left_0000.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/eri/jump/st_jmp/leg_left/st_jmp_leg_left_0001.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/eri/jump/st_jmp/leg_left/st_jmp_leg_left_0002.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/eri/jump/st_jmp/leg_left/st_jmp_leg_left_0003.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/eri/jump/st_jmp/leg_left/st_jmp_leg_left_0004.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/eri/jump/st_jmp/leg_left/st_jmp_leg_left_0005.png";
    m_vImagf.push_back(new Image(m_path));

    itef = m_vImagf.begin();
    isRevf = false;

    iter = m_vImage.begin();
    isRev = false;
}


EriStJmpLeg::~EriStJmpLeg()
{
}

void EriStJmpLeg::handle(HDC hdc)
{
    Graphics gr(hdc);

    if (iter == m_vImage.end())
    {
        isRev = true;
        --iter;
    }
    else if (iter == m_vImage.begin())
    {
        isRev = false;
    }

    gr.DrawImage(*iter
            , m_pObj->GetInfo().rect.left   
            , m_pObj->GetInfo().rect.top + ((IMGCY/3) + 7)
            , IMGCX
            , IMGCY);
    //gr.DrawImage(*iter, m_pObj->GetInfo().fX - 19, m_pObj->GetInfo().fY);

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

void EriStJmpLeg::handlf(HDC hdc)
{
    Graphics gr(hdc);

    if (itef == m_vImagf.end())
    {
        isRevf = true;
        --itef;
    }
    else if (itef == m_vImagf.begin())
    {
        isRevf = false;
    }

    gr.DrawImage(*itef
            , m_pObj->GetInfo().rect.left   
            , m_pObj->GetInfo().rect.top + ((IMGCY/3) + 7)
            , IMGCX
            , IMGCY);
    //gr.DrawImage(*iter, m_pObj->GetInfo().fX - 19, m_pObj->GetInfo().fY);

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
