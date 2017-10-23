#include "stdafx.h"
#include "Mouse.h"

CMouse::CMouse()
{
}

CMouse::~CMouse()
{
}

POINT CMouse::GetMousePos()
{
	POINT pt = {};
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	return pt;
}

int CMouse::Update()
{
    POINT pt = GetMousePos();
    m_tInfo.fX = FLOAT(pt.x) - CScrollMgr::GetInstance()->GetScrollX();//(WINCX - CScrollMgr::GetInstance()->GetScrollX()) - (WINCX - FLOAT(pt.x)) ;
    m_tInfo.fY = FLOAT(pt.y);
    m_tInfo.fCX = 2;
    m_tInfo.fCY = 2;
    CObj::Update();
    m_tInfo.iHP = 1000;
    return 0;
}

void CMouse::Init()
{
    m_tInfo.rect = { 0, 0, 5, 5 };
}

void CMouse::Release()
{
}

void CMouse::Render(HDC hdc)
{
	Ellipse(hdc, m_tInfo.fX - 2, m_tInfo.fY - 2, m_tInfo.fX + 2, m_tInfo.fY + 2);

    wchar_t         pos[64];
    swprintf_s(pos, L"X:%.2f Y:%.2f", m_tInfo.fX, m_tInfo.fY);
    SetTextAlign(hdc, TA_CENTER);
    SetBkMode(hdc, TRANSPARENT);
    TextOut(hdc, m_tInfo.fX + 50, m_tInfo.fY - 30, pos, wcslen(pos));
}
