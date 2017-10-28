#include "stdafx.h"
#include "BabarianBase.h"
#include "Obj.h"

CBabarian::CBabarian()
{
}

CBabarian::~CBabarian()
{
}

void CBabarian::Init()
{
}

void CBabarian::Render(HDC hdc)
{
    //Image* img      = m_curImg->image;

    HBRUSH hBrush   = CreateSolidBrush(MOB_K_BABA);
    HBRUSH hOldsh   = (HBRUSH)SelectObject(hdc, hBrush);

    Rectangle(
        hdc
        , m_pObj->GetInfo().rect.left
        , m_pObj->GetInfo().rect.top
        , m_pObj->GetInfo().rect.right
        , m_pObj->GetInfo().rect.bottom
    );

    DeleteObject(SelectObject(hdc, hOldsh));
    DeleteObject(hBrush);
}

void CBabarian::Release()
{
}

int CBabarian::Update()
{
    return 0;
}
