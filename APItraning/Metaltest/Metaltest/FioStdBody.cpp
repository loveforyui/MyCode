#include "stdafx.h"
#include "FioStdBody.h"


FioStdBody::FioStdBody()
{
    // right
    m_path = L"../resource/fio/st/body/st_body_0000.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/fio/st/body/st_body_0001.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/fio/st/body/st_body_0002.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/fio/st/body/st_body_0003.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/fio/st/body/st_body_0004.png";
    m_vImage.push_back(new Image(m_path));
    m_path = L"../resource/fio/st/body/st_body_0005.png";
    m_vImage.push_back(new Image(m_path));

    m_path = L"../resource/fio/st/body_left/st_body_left_0000.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/fio/st/body_left/st_body_left_0001.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/fio/st/body_left/st_body_left_0002.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/fio/st/body_left/st_body_left_0003.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/fio/st/body_left/st_body_left_0004.png";
    m_vImagf.push_back(new Image(m_path));
    m_path = L"../resource/fio/st/body_left/st_body_left_0005.png";
    m_vImagf.push_back(new Image(m_path));

    iter = m_vImage.begin();
    itef = m_vImagf.begin();

    isRev = false;
    isRevf = false;
}


FioStdBody::~FioStdBody()
{
}

void FioStdBody::handle(HDC hdc)
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

    if (m_pObj->GetDirection() == OBJ_D_RIGHT)
    {
        graphics.DrawImage(*iter
            , m_pObj->GetInfo().rect.left
            , m_pObj->GetInfo().rect.top
            , IMGCX
            , IMGCY);
    }
    //graphics.DrawImage(*iter, m_pObj->GetInfo().fX - 17, m_pObj->GetInfo().fY - 18);

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

void FioStdBody::handlf(HDC hdc)
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

    if (m_pObj->GetDirection() == OBJ_D_LEFT)
    {
        graphics.DrawImage(*itef
            , m_pObj->GetInfo().rect.left
            , m_pObj->GetInfo().rect.top
            , IMGCX
            , IMGCY);
    }
    //graphics.DrawImage(*iter, m_pObj->GetInfo().fX - 17, m_pObj->GetInfo().fY - 18);

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
