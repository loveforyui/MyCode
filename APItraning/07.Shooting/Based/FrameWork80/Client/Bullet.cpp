#include "stdafx.h"
#include "Bullet.h"


CBullet::CBullet()
{
}

CBullet::~CBullet()
{
	Release();
}

void CBullet::Initialize()
{
	m_tInfo.fCX = 15.f;
	m_tInfo.fCY = 15.f;

	m_fSpeed = 12.f;
}

void CBullet::Initialize(INFO info, FLOAT speed)
{
}

int CBullet::Update()
{
	CObj::Update();

    switch (m_eDirec)
    {
    case D_UP:
        m_tInfo.fY -= m_fSpeed;
        break;
    case D_DOWN:
        m_tInfo.fY += m_fSpeed;
        break;
    case D_LEFT:
        m_tInfo.fX -= m_fSpeed;
        break;
    case D_RIGHT:
        m_tInfo.fX += m_fSpeed;
        break;
    case D_UL:
        break;
    case D_UR:
        break;
    case D_DL:
        break;
    case D_DR:
        break;
    default:
        break;
    }

	return 0;
}

void CBullet::Render(HDC hDC)
{
	CObj::Update();
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CBullet::Release()
{
}


