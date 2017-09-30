#include "stdafx.h"
#include "Ellised.h"
#include "CObj.h"
#include "Player.h"


Ellised::Ellised()
{
}


Ellised::~Ellised()
{
}

void Ellised::Handle()
{
    INFO info = dynamic_cast<CPlayer*>(m_pObj)->GetPos();

    HDC hdc = GetDC(g_hWnd);

    wchar_t tempStr[] = L"Ellipsed";
    SetTextAlign(hdc, TA_CENTER);
    TextOut(hdc, LONG(info.fX), LONG(info.fY), tempStr, wcslen(tempStr));
    m_eState = IDLE;

    ReleaseDC(g_hWnd, hdc);
}
