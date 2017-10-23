#include "stdafx.h"
#include "Mouse.h"

CMouse::CMouse()
{

}

CMouse::~CMouse()
{

}

void CMouse::Init()
{
    m_tInfo.fCX = 5.f;
    m_tInfo.fCY = 5.f;
}

void CMouse::Release()
{
}

void CMouse::Render(HDC hdc)
{
    Ellipse(hdc, m_tInfo.rect.left, m_tInfo.rect.top, m_tInfo.rect.right, m_tInfo.rect.bottom);
    wchar_t         pos[64];
    swprintf_s(pos, L"X:%.2f Y:%.2f", m_tInfo.fX, m_tInfo.fY);
    //wsprintf();
    SetTextAlign(hdc, TA_CENTER);
    SetBkMode(hdc, TRANSPARENT);
    TextOut(hdc, m_tInfo.fX, m_tInfo.fY - 30, pos, wcslen(pos));
}

int CMouse::Update()
{
    POINT pt = {};
    pt = CMouse::GetMousePos();
    m_tInfo.fX = FLOAT(pt.x) - CScrollMgr::GetInstance()->GetScrollX();
    m_tInfo.fY = FLOAT(pt.y);
    CObj::Update();

    return 0;
}

POINT CMouse::GetMousePos()
{
	POINT pt = {};
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	return pt;
}