#include "stdafx.h"
#include "CObj.h"
#include "StateManager.h"
#include "States.h"

CObj::CObj()
	: m_tInfo{} // ������ �ʱ�ȭ (���� m_tInfo�� ��� ��� 0 �ʱ�ȭ)
	, m_tRect{}
	, m_fSpeed(0.f)
{
    m_tState.SetObj(this);
    m_tState.SetState(new Idle);
}

CObj::~CObj()
{
}

void CObj::SetState(StateManager * state)
{
    m_tState.SetState(state);
}

int CObj::Update()
{
	m_tRect.left    = LONG(m_tInfo.fX - m_tInfo.fCX / 2);
	m_tRect.top     = LONG(m_tInfo.fY - m_tInfo.fCY / 2);
	m_tRect.right   = LONG(m_tInfo.fX + m_tInfo.fCX / 2);
	m_tRect.bottom  = LONG(m_tInfo.fY + m_tInfo.fCY / 2);

	return 0;
}