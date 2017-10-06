#include "stdafx.h"
#include "EriWrkBody.h"


EriWrkBody::EriWrkBody()
{
    m_path = L"../resource/eri/working/wrk_body/wrk_body_00.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/eri/working/wrk_body/wrk_body_01.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/eri/working/wrk_body/wrk_body_02.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/eri/working/wrk_body/wrk_body_03.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/eri/working/wrk_body/wrk_body_04.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/eri/working/wrk_body/wrk_body_05.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/eri/working/wrk_body/wrk_body_06.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/eri/working/wrk_body/wrk_body_07.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/eri/working/wrk_body/wrk_body_08.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/eri/working/wrk_body/wrk_body_09.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/eri/working/wrk_body/wrk_body_10.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/eri/working/wrk_body/wrk_body_11.png";
    m_vImage.push_back(new Image(m_path));

    m_path = L"../resource/eri/working/wrk_body_left/wrk_body_left_0000.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/eri/working/wrk_body_left/wrk_body_left_0001.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/eri/working/wrk_body_left/wrk_body_left_0002.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/eri/working/wrk_body_left/wrk_body_left_0003.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/eri/working/wrk_body_left/wrk_body_left_0004.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/eri/working/wrk_body_left/wrk_body_left_0005.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/eri/working/wrk_body_left/wrk_body_left_0006.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/eri/working/wrk_body_left/wrk_body_left_0007.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/eri/working/wrk_body_left/wrk_body_left_0008.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/eri/working/wrk_body_left/wrk_body_left_0009.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/eri/working/wrk_body_left/wrk_body_left_0010.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/eri/working/wrk_body_left/wrk_body_left_0011.png";
    m_vImagf.push_back(new Image(m_path));

    itef = m_vImagf.begin();
    isRevf = false;

    iter = m_vImage.begin();
    isRev = false;
}


EriWrkBody::~EriWrkBody()
{
}

void EriWrkBody::handle(HDC hdc)
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
            , m_pObj->GetInfo().rect.top
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

void EriWrkBody::handlf(HDC hdc)
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
            , m_pObj->GetInfo().rect.left   
            , m_pObj->GetInfo().rect.top
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
