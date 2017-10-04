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

    gr.DrawImage(*iter, m_pObj->GetInfo().fX - 19, m_pObj->GetInfo().fY);

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
