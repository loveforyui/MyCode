#include "stdafx.h"
#include "StartMove.h"
#include "CObj.h"
#include "Player.h"


StartMove::StartMove()
{
}


StartMove::~StartMove()
{
}

void StartMove::Handle()
{
    INFO info = dynamic_cast<CPlayer*>(m_pObj)->GetPos();

    HDC hdc = GetDC(g_hWnd);

    wchar_t tempStr[] = L"Move";
    SetTextAlign(hdc, TA_CENTER);
    TextOut(hdc, LONG(info.fX), LONG(info.fY), tempStr, wcslen(tempStr));
    m_eState = MOVE;

    ReleaseDC(g_hWnd, hdc);
}
