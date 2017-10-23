#include "stdafx.h"
#include "Line.h"


CLine::CLine()
{
}

CLine::CLine(LINEINFO & rInfo)
	: m_tInfo(rInfo.tLPoint, rInfo.tRPoint)
{
}


CLine::~CLine()
{
}

void CLine::Render(HDC hDC)
{
	//float fScrollX = CScrollMgr::GetInstance()->GetScrollX();

	MoveToEx(hDC, (int)m_tInfo.tLPoint.fX, (int)m_tInfo.tLPoint.fY, nullptr);
	LineTo(hDC, (int)m_tInfo.tRPoint.fX, (int)m_tInfo.tRPoint.fY);
}
