#include "stdafx.h"
#include "Things.h"

CThings::CThings()
{
}

CThings::~CThings()
{
    Release();
}

void CThings::Init()
{
}

void CThings::Release()
{
}

void CThings::Render(HDC hdc)
{
    Rectangle(hdc, m_tInfo.rect.left, m_tInfo.rect.top, m_tInfo.rect.right, m_tInfo.rect.bottom);
}

int CThings::Update()
{
    if (isDead())
        return 1;
    CObj::Update();
    return 0;
}
