#include "stdafx.h"
#include "Monster.h"

CMonster::CMonster()
{
}

CMonster::~CMonster()
{
    Release();
}

void CMonster::Init()
{
}

void CMonster::Release()
{
}

void CMonster::Render(HDC hdc)
{
    HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));
    HBRUSH oBrush = (HBRUSH)SelectObject(hdc, brush);

    Rectangle(hdc, m_tInfo.rect.left, m_tInfo.rect.top, m_tInfo.rect.right, m_tInfo.rect.bottom);

    SelectObject(hdc, oBrush);
    DeleteObject(brush);
}

int CMonster::Update()
{
    if (isDead())
        return 1;
    CObj::Update();
    return 0;
}
