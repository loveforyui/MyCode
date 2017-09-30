#include "stdafx.h"
#include "Attack.h"
#include "Player.h"


Attack::Attack()
{
}


Attack::~Attack()
{
}

void Attack::Handle()
{
    INFO info = dynamic_cast<CPlayer*>(m_pObj)->GetPos();

    HDC hdc = GetDC(g_hWnd);

    wchar_t tempStr[] = L"Attack";
    SetTextAlign(hdc, TA_CENTER);
    TextOut(hdc, LONG(info.fX), LONG(info.fY), tempStr, wcslen(tempStr));
    m_eState = IDLE;

    ReleaseDC(g_hWnd, hdc);
}
