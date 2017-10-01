#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"
#include "StateManager.h"
#include "States.h"

CPlayer::CPlayer()
    : m_pBulletList(nullptr), keyInput(false)
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
    keyInput = false;
    if (GetAsyncKeyState(VK_LEFT)   & 0x8000)
    {
        m_tInfo.fX -= m_fSpeed;
        m_tState.SetState(new StartMove);

        // Decision Direction
        switch (m_eDirec)
        {
        case D_UP:
            m_eDirec = D_UL;
            break;
        case D_DOWN:
            m_eDirec = D_DL;
            break;
        default:
            m_eDirec = D_LEFT;
            break;
        }

        keyInput = true;
    }		
    if (GetAsyncKeyState(VK_RIGHT)  & 0x8000)
    {
        m_tInfo.fX += m_fSpeed;
        m_tState.SetState(new StartMove);
        // Decision Direction
        switch (m_eDirec)
        {
        case D_UP:
            m_eDirec = D_UR;
            break;
        case D_DOWN:
            m_eDirec = D_DR;
            break;
        default:
            m_eDirec = D_RIGHT;
            break;
        }
        keyInput = true;
    }		
    if (GetAsyncKeyState(VK_UP)     & 0x8000)
    {
        m_tInfo.fY -= m_fSpeed;
        m_tState.SetState(new StartMove);
        // Decision Direction
        switch (m_eDirec)
        {
        case D_LEFT:
            m_eDirec = D_UL;
            break;
        case D_RIGHT:
            m_eDirec = D_UR;
            break;
        default:
            m_eDirec = D_UP;
            break;
        }
        keyInput = true;
    }		
    if (GetAsyncKeyState(VK_DOWN)   & 0x8000)
    {
        m_tInfo.fY += m_fSpeed;
        m_tState.SetState(new StartMove);
        // Decision Direction
        switch (m_eDirec)
        {
        case D_LEFT:
            m_eDirec = D_DL;
            break;
        case D_RIGHT:
            m_eDirec = D_DR;
            break;
        default:
            m_eDirec = D_DOWN;
            break;
        }
        keyInput = true;
    }		
    if (GetAsyncKeyState(0x57)  & 0x8000)   //w
    {
        m_tState.SetState(new Attack);
        m_pBulletList->push_back(CreateBullet(D_UP));

        keyInput = true;
    }
    if (GetAsyncKeyState(0x53)  & 0x8000)   //s
    {
        m_tState.SetState(new Attack);
        m_pBulletList->push_back(CreateBullet(D_DOWN));
        keyInput = true;
    }
    if (GetAsyncKeyState(0x41)  & 0x8000)   //a
    {
        m_tState.SetState(new Attack);
        m_pBulletList->push_back(CreateBullet(D_LEFT));
        keyInput = true;
    }
    if (GetAsyncKeyState(0x44)  & 0x8000)   //d
    {
        m_tState.SetState(new Attack);
        m_pBulletList->push_back(CreateBullet(D_RIGHT));
        keyInput = true;
    }

    if (!keyInput)
    {
        ++keyTime;
        if (96 <= keyTime)
        {
            m_tState.SetState(new Idle);
        }
    }
    else
    {
        keyTime = 0;
    }
        

    
	return 0;
}

void CPlayer::Render(HDC hDC)
{
	CObj::Update();
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
    CObj::m_tState.request();
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

CObj * CPlayer::CreateBullet(DIRECTION d)
{
    CObj* pBullet = new CBullet;
	pBullet->Initialize();
	pBullet->SetPos(m_tInfo.fX, m_tInfo.fY);
    pBullet->SetDirection(d);

	return pBullet;
}


