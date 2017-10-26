#include "stdafx.h"
#include "Obj.h"

CObj::CObj()
    : m_tInfo{}
{
}

CObj::~CObj()
{
}

int CObj::Update()
{
    if(m_tInfo.fSpeed < 5.f)
        m_tInfo.fSpeed += m_tInfo.fAcc;
    m_tInfo.rect.left    = LONG(m_tInfo.fX - m_tInfo.fCX / 2);
	m_tInfo.rect.top     = LONG(m_tInfo.fY - m_tInfo.fCY / 2);
	m_tInfo.rect.right   = LONG(m_tInfo.fX + m_tInfo.fCX / 2);
	m_tInfo.rect.bottom  = LONG(m_tInfo.fY + m_tInfo.fCY / 2);
    return 0;
}

void CObj::SetPos(float x, float y)
{
    m_tInfo.fX = x;
    m_tInfo.fY = y;
}

void CObj::SetWH(float cx, float cy)
{
    m_tInfo.fCX = cx;
    m_tInfo.fCY = cy;
}

FLOAT CObj::GetImgW()
{
    if(m_tInfo.image->empty())
        return 0.f;
    else
    {
        return (*(m_tInfo.image->begin()))->image->GetWidth();
    }
}

FLOAT CObj::GetImgH()
{
    if(m_tInfo.image->empty())
        return 0.f;
    else
    {
        return (*(m_tInfo.image->begin()))->image->GetHeight();
    }
}

void CObj::ImageRender(HDC hdc)
{
    if (nullptr != m_tInfo.image)
    {
        if (m_tInfo.image->empty())
            return;
        
        IMG_DRAW_I(
            hdc
            , (*img_begin)->image
            , m_tInfo.fX, m_tInfo.fY
            , FLOAT((*img_begin)->image->GetWidth())
            , FLOAT((*img_begin)->image->GetHeight()));

        ++img_begin;
        if (img_begin == img_end)
            img_begin = m_tInfo.image->begin();

    }
}
