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

	// GetAsyncKeyState�� ��ȯ�ϴ� ��
	// 0: �������� ���� ��
	// 1: ���� �������� ������ ȣ�� �������� ������ �ʾ��� ��
	// 0x8000: ���� �������� ���� ȣ�� �������� ������ ��
	// 0x8001: ���� �������� �ְ� ȣ�� ���������� ������ ��
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


