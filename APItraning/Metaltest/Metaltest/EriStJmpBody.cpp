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

    m_path = L"../resource/eri/jump/st_jmp/body_left/st_jmp_body_left_0000.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/eri/jump/st_jmp/body_left/st_jmp_body_left_0001.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/eri/jump/st_jmp/body_left/st_jmp_body_left_0002.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/eri/jump/st_jmp/body_left/st_jmp_body_left_0003.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/eri/jump/st_jmp/body_left/st_jmp_body_left_0004.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/eri/jump/st_jmp/body_left/st_jmp_body_left_0005.png";
    m_vImagf.push_back(new Image(m_path));

    itef = m_vImagf.begin();
    isRevf = false;

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

    gr.DrawImage(*iter
            , m_pObj->GetInfo().rect.left
            , m_pObj->GetInfo().rect.top
            , IMGCX
            , IMGCY);
    //gr.DrawImage(*iter, m_pObj->GetInfo().fX - 18, m_pObj->GetInfo().fY - 17);

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

void EriStJmpBody::handlf(HDC hdc)
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
            , m_pObj->GetInfo().rect.top
            , IMGCX
            , IMGCY);
    //gr.DrawImage(*itef, m_pObj->GetInfo().fX - 18, m_pObj->GetInfo().fY - 17);

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
