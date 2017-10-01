#include "stdafx.h"
#include "PatrolMon.h"


PatrolMon::PatrolMon()
{
    m_eDirec = D_LEFT;
}


PatrolMon::~PatrolMon()
{
}

void PatrolMon::Initialize          ()
{
    m_tInfo     = { 400.f, 500.f, 50.f, 50.f };
	m_fSpeed    = 10.f;
}

void PatrolMon::Initialize          (INFO info, FLOAT speed)
{
    m_tInfo     = info;
    m_fSpeed    = speed;
}

void PatrolMon::Render              (HDC hdc)
{
    CObj::Update();
	Rectangle(hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
    //CObj::m_tState.request();
}

void PatrolMon::Release             ()
{
}

int PatrolMon:: Update              ()
{
    CObj::Update();
    switch (m_eDirec)
    {
    case D_LEFT:
        m_tInfo.fX -= m_fSpeed;
        break;
    case D_RIGHT:
        m_tInfo.fX += m_fSpeed;
        break;
    }
    return 0;
}
