#include "stdafx.h"
#include "BackGround.h"



CBackGround::CBackGround()
{
    
}

CBackGround::~CBackGround()
{
}

void CBackGround::Init()
{
}

void CBackGround::Release()
{
}

void CBackGround::Render(HDC hdc)
{
    float fx = CScrollMgr::GetInstance()->GetScrollX();

    for (vector<ObjImg*>::iterator iter = ++m_tInfo.image->begin()
        ; iter != m_tInfo.image->end()
        ; ++iter)
    {
        IMG_DRAW_I(
            hdc
            , (*iter)->image
            , fx, 0.f
            , (*iter)->image->GetWidth(), (*iter)->image->GetHeight());
    }
}

int CBackGround::Update()
{
    return 0;
}

void CBackGround::AddFloorY(int y)
{
    m_vlineY.push_back(y);
}
