#include "stdafx.h"
#include "Building.h"

CBuilding::CBuilding()
{
}

CBuilding::CBuilding(INFO & info)
{
    m_tInfo = info;
}

CBuilding::~CBuilding()
{
}

void CBuilding::Init()
{
    m_tInfo.isDead = false;
}

void CBuilding::Release()
{
}

void CBuilding::Render(HDC hdc)
{
    CObj::Update();
    float fx = CScrollMgr::GetInstance()->GetScrollX();
    Rectangle(
        hdc
        , m_tInfo.rect.left + fx
        , m_tInfo.rect.top
        , m_tInfo.rect.right + fx
        , m_tInfo.rect.bottom);
}

int CBuilding::Update()
{
    if (m_tInfo.isDead)
        return 1;
    CObj::Update();
    return 0;
}
