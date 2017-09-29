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
	m_tInfo.fCX = 5.f;
	m_tInfo.fCY = 5.f;

	m_fSpeed = 15.f;
}

void CBullet::Initialize(INFO info, FLOAT speed)
{
    
}

int CBullet::Update()
{
	CObj::Update();

	m_tInfo.fY -= m_fSpeed;

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


