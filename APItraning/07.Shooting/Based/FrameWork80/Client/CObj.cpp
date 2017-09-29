#include "stdafx.h"
#include "CObj.h"


CObj::CObj()
	: m_tInfo{} // 유니폼 초기화 (현재 m_tInfo의 모든 멤버 0 초기화)
	, m_tRect{}
	, m_fSpeed(0.f)
{
}

CObj::~CObj()
{
}

int CObj::Update()
{
	m_tRect.left    = LONG(m_tInfo.fX - m_tInfo.fCX / 2);
	m_tRect.top     = LONG(m_tInfo.fY - m_tInfo.fCY / 2);
	m_tRect.right   = LONG(m_tInfo.fX + m_tInfo.fCX / 2);
	m_tRect.bottom  = LONG(m_tInfo.fY + m_tInfo.fCY / 2);

	return 0;
}
