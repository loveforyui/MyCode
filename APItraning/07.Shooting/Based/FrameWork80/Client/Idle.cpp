#include "stdafx.h"
#include "Idle.h"
#include "CObj.h"
#include "Player.h"

Idle::Idle()
{
}


Idle::~Idle()
{
}

void Idle::Handle()
{
    INFO info = dynamic_cast<CPlayer*>(m_pObj)->GetPos();

    HDC hdc = GetDC(g_hWnd);

    wchar_t tempStr[] = L"IDLE";
    SetTextAlign(hdc, TA_CENTER);
    TextOut(hdc, LONG(info.fX), LONG(info.fY), tempStr, wcslen(tempStr));
    m_eState = IDLE;

    ReleaseDC(g_hWnd, hdc);
}
