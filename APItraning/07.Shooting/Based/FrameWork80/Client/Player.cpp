#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"

CPlayer::CPlayer()
	: m_pBulletList(nullptr)
{
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	m_tInfo     = { 400.f, 500.f, 50.f, 50.f };
	m_fSpeed    = 10.f;
}
void CPlayer::Initialize(INFO info, FLOAT speed)
{
    m_tInfo     = info;
    m_fSpeed    = speed;
}

int CPlayer::Update()
{
	CObj::Update();

	// GetAsyncKeyState가 반환하는 값
	// 0: 눌린적이 없을 때
	// 1: 전에 눌린적은 있지만 호출 시점에서 눌리지 않았을 때
	// 0x8000: 전에 눌린적도 없고 호출 시점에서 눌렸을 때
	// 0x8001: 전에 눌린적이 있고 호출 시점에서도 눌렸을 때
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		m_tInfo.fX -= m_fSpeed;
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		m_tInfo.fX += m_fSpeed;
	if (GetAsyncKeyState(VK_UP) & 0x8000)
		m_tInfo.fY -= m_fSpeed;
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		m_tInfo.fY += m_fSpeed;
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		m_pBulletList->push_back(CreateBullet());

	return 0;
}

void CPlayer::Render(HDC hDC)
{
	CObj::Update();
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CPlayer::Release()
{
}

CObj * CPlayer::CreateBullet()
{
	CObj* pBullet = new CBullet;
	pBullet->Initialize();
	pBullet->SetPos(m_tInfo.fX, m_tInfo.fY);

	return pBullet;
}


