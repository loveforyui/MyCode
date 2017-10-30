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

void CBackGround::Render(HDC hDC)
{
    for (vector<ObjImg*>::iterator iter = ++m_tInfo.image->begin()
        ; iter != m_tInfo.image->end()
        ; ++iter)
    {
        IMG_DRAW_I(
            hDC
            , (*iter)->image
            , 0.f, 0.f
            , FLOAT((*iter)->image->GetWidth())
            , FLOAT((*iter)->image->GetHeight())
        );
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
