#include "stdafx.h"
#include "Bullet.h"

CBullet::CBullet()
{
}

CBullet::~CBullet()
{
}

void CBullet::Init()
{
    m_tInfo.fSpeed = 15.f;
}

void CBullet::Release()
{
}

void CBullet::Render(HDC hdc)
{
    for (vector<ObjImg*>::iterator iter = m_tInfo.image->begin()
        ; iter != m_tInfo.image->end(); ++iter)
    {
        IMG_DRAW_I(hdc, (*iter)->image, m_tInfo.fX, m_tInfo.fY, m_tInfo.fCX, m_tInfo.fCY);
    }
}

int CBullet::Update()
{
    if (isDead())
        return 1;
    INFO info = CPattern::GetInstance()->AngleLine(this, m_tInfo.fAngle);

    m_tInfo.fX = info.fX;
    m_tInfo.fY = info.fY;
    m_tInfo.fCX = info.fCX;
    m_tInfo.fCY = info.fCY;
    
    CObj::Update();

    return 0;
}
