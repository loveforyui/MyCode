#include "stdafx.h"
#include "Mline.h"


MCLine::MCLine()
{
}

MCLine::MCLine(LINEINFO & rInfo)
	: m_tInfo(rInfo.tLPoint, rInfo.tRPoint)
{
}


MCLine::~MCLine()
{
}

void MCLine::Render(HDC hDC)
{
	//float fScrollX = CScrollMgr::GetInstance()->GetScrollX();

	MoveToEx(hDC, (int)m_tInfo.tLPoint.fX, (int)m_tInfo.tLPoint.fY, nullptr);
	LineTo(hDC, (int)m_tInfo.tRPoint.fX, (int)m_tInfo.tRPoint.fY);
}
