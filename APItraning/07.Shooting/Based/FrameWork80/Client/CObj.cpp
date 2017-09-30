#include "stdafx.h"
#include "CObj.h"
#include "StateManager.h"
#include "States.h"

CObj::CObj()
	: m_tInfo{} // 유니폼 초기화 (현재 m_tInfo의 모든 멤버 0 초기화)
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

BOOL CObj::operator&&(CObj & src)
{
    BOOL result = FALSE;

    // 하
    if ((src.m_tRect.left <= m_tRect.left) && (m_tRect.left <= src.m_tRect.right))
    {
        if ((m_tRect.top <= src.m_tRect.bottom) && (src.m_tRect.bottom <= m_tRect.bottom))
        {
            m_tInfo.fY += m_fSpeed;
            result = TRUE;
            return result;
        }        
    }
    else if ((src.m_tRect.left <= m_tRect.right) && (m_tRect.right <= src.m_tRect.right))
    {
        if ((m_tRect.top <= src.m_tRect.bottom) && (src.m_tRect.bottom <= m_tRect.bottom))
        {
            m_tInfo.fY += m_fSpeed;
            result = TRUE;
            return result;
        }
    }
    // 상
    if ((src.m_tRect.left <= m_tRect.left) && (m_tRect.left <= src.m_tRect.right))
    {
        if ((src.m_tRect.top <= m_tRect.bottom) && (m_tRect.top <= src.m_tRect.top))
        {
            m_tInfo.fY -= m_fSpeed;
            result = TRUE;
            return result;
        }
    }
    else if ((src.m_tRect.left <= m_tRect.right) && (m_tRect.right <= src.m_tRect.right))
    {
        if ((src.m_tRect.top <= m_tRect.bottom) && (m_tRect.top <= src.m_tRect.top))
        {
            m_tInfo.fY -= m_fSpeed;
            result = TRUE;
            return result;
        }
    }
    // 좌
    if ((src.m_tRect.top <= m_tRect.bottom) && (m_tRect.top <= src.m_tRect.top))
    {
        
    }
    else if ((m_tRect.top <= src.m_tRect.bottom) && (src.m_tRect.bottom <= m_tRect.bottom))
    {

    }

    return result;
}
