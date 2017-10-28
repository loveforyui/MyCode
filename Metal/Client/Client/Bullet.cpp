#include "stdafx.h"
#include "Bullet.h"

CBullet::CBullet()
{
}

CBullet::~CBullet()
{
}

void CBullet::  Init        ()
{
    m_tInfo.fSpeed = 5.f;
    if (!m_tInfo.image->empty())
    {
        img_begin = m_tInfo.image->begin();
        img_end = m_tInfo.image->end();
    }
    m_tInfo.curState = OBJ_A_JUMP;
    m_tInfo.fJumpAcc = GRAVITY * 1.5f;
    m_tInfo.fY -= 10.f;
}

void CBullet::  Release     ()
{
}

void CBullet::  Render      (HDC hdc)
{
    m_tInfo.fCX = FLOAT((*img_begin)->image->GetWidth());
    m_tInfo.fCY = FLOAT((*img_begin)->image->GetHeight());

    HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0));
    HBRUSH hOldsh = (HBRUSH)SelectObject(hdc, hBrush);

    IMG_DRAW_I(
        hdc
        , (*img_begin)->image
        , m_tInfo.fX - (m_tInfo.fCX/2.f)
        , m_tInfo.fY - (m_tInfo.fCY/2.f)
        , m_tInfo.fCX
        , m_tInfo.fCY);

    SelectObject(hdc, hOldsh);
    DeleteObject(hBrush);
    //Rectangle(hdc, m_tInfo.rect.left, m_tInfo.rect.top, m_tInfo.rect.right, m_tInfo.rect.bottom);

    ++img_begin;
    if (1 < m_end)
    {
        img_begin = m_tInfo.image->end();
        --img_begin;
        return;
    }
    if (img_begin == (img_end - 2))
    {
        img_begin = m_tInfo.image->begin();
    }
}

int CBullet::   Update      ()
{
    if (isDead())
        return 1;
    if (STATE_SAME(m_tInfo.curState, OBJ_A_STND))
    {
        ++m_end;
        img_begin = m_tInfo.image->end();
        --img_begin;
        if (60 < m_end)
            return 1;
    }

    if (m_end == 0)
    {
        switch (m_pattern)
        {
        case CBullet::LINE:
            Line();
            break;
        case CBullet::CONIC:
            Conic();
            break;
        case CBullet::PAT_END:
            break;
        }
    }


    IsCollisionLine();

    CObj::Update();

    if (m_tInfo.fX < 0 || 3823 < m_tInfo.fX)
        return 1;

    if (m_tInfo.fY < 0 || WINCY < m_tInfo.fY)
        return 1;

    return 0;
}

void CBullet::Line()
{
    POINT info = CPattern::GetInstance()->AngleLine(this, m_tInfo.fAngle);

    m_tInfo.fX = float(info.x);
    m_tInfo.fY = float(info.y);
}

void CBullet::Conic()
{
    POINT info = CPattern::GetInstance()->AngleLine(this, m_tInfo.fAngle);
    m_tInfo.fX = float(info.x);
    m_tInfo.fY = float(info.y);

    m_tInfo.fAngle += 5.f;
    if (240.f <= m_tInfo.fAngle)
        m_tInfo.fAngle = 240.f;
}

void CBullet::     IsCollisionLine ()
{
    float fy = m_tInfo.fY;

    if (CLineMgr::GetInstance()->CollisionLine(m_tInfo.fX, &fy))
    {
        if (!(m_tInfo.curState & OBJ_A_JUMP))
        {
            m_tInfo.fY = fy - m_tInfo.fCY / 2;
        }
        if (m_tInfo.fY >= fy - m_tInfo.fCY / 2) // 점프 중에 라인에 도달하면 라인을 타고
		{
			m_tInfo.fY = fy - m_tInfo.fCY / 2;
			m_tInfo.fJumpAcc = 0.f;
            m_tInfo.curState = OBJ_A_STND;
		}
    }
    else
    {
        m_tInfo.curState = OBJ_A_JUMP;
    }
}