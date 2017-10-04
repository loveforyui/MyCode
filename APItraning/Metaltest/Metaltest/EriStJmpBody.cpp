#include "stdafx.h"
#include "EriStJmpBody.h"


EriStJmpBody::EriStJmpBody()
{
    m_path = L"../resource/eri/jump/st_jmp/body/st_jmp_body_0000.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/eri/jump/st_jmp/body/st_jmp_body_0001.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/eri/jump/st_jmp/body/st_jmp_body_0002.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/eri/jump/st_jmp/body/st_jmp_body_0003.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/eri/jump/st_jmp/body/st_jmp_body_0004.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/eri/jump/st_jmp/body/st_jmp_body_0005.png";
    m_vImage.push_back(new Image(m_path));

    iter = m_vImage.begin();
    isRev = false;
}
EriStJmpBody::~EriStJmpBody()
{
}

void EriStJmpBody::handle(HDC hdc)
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

    gr.DrawImage(*iter, m_pObj->GetInfo().fX - 17, m_pObj->GetInfo().fY - 18);

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
