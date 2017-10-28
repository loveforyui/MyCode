#include "stdafx.h"
#include "BerserkMboss.h"
#include "Obj.h"

CBerserkMboss::CBerserkMboss()
{
}

CBerserkMboss::~CBerserkMboss()
{
}

void CBerserkMboss::Init()
{
}

void CBerserkMboss::Render(HDC hdc)
{
    HBRUSH hBrush   = CreateSolidBrush(MOB_K_BAKING);
    HBRUSH hOldsh   = (HBRUSH)SelectObject(hdc, hBrush);

    Rectangle(
        hdc
        , m_pObj->GetInfo().rect.left
        , m_pObj->GetInfo().rect.top
        , m_pObj->GetInfo().rect.right
        , m_pObj->GetInfo().rect.bottom
    );

    SelectObject(hdc, hOldsh);
    DeleteObject(hBrush);
}

void CBerserkMboss::Release()
{
}

int CBerserkMboss::Update()
{
    return 0;
}
