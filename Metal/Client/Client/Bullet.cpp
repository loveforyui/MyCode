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
    m_tInfo.fSpeed = 15.f;
}

void CBullet::  Release     ()
{
}

void CBullet::  Render      (HDC hdc)
{
    for (vector<ObjImg*>::iterator iter = m_tInfo.image->begin()
        ; iter != m_tInfo.image->end(); ++iter)
    {

        IMG_DRAW_I(hdc, (*iter)->image, m_tInfo.fX, m_tInfo.fY, m_tInfo.fCX, m_tInfo.fCY);
    }
}

int CBullet::   Update      ()
{
    if (isDead())
        return 1;
    POINT info = CPattern::GetInstance()->AngleLine(this, m_tInfo.fAngle);

    m_tInfo.fX = float(info.x);
    m_tInfo.fY = float(info.y);
    //m_tInfo.fCX = info.fCX;
    //m_tInfo.fCY = info.fCY;
    
    CObj::Update();

    if (m_tInfo.fX < 0 || 3823 < m_tInfo.fX)
        return 1;

    if (m_tInfo.fY < 0 || WINCY < m_tInfo.fY)
        return 1;

    return 0;
}
