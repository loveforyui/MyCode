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

    graphics.DrawImage(*iter, FLOAT(m_pObj->GetInfo().rect.left), FLOAT(m_pObj->GetInfo().rect.top));

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
