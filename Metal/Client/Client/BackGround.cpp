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
    HDC hdc = GetDC(g_hWnd);
    for (vector<ObjImg*>::iterator iter = ++m_tInfo.image->begin()
        ; iter != m_tInfo.image->end()
        ; ++iter)
    {
        IMG_DRAW_I(
            hDC
            , (*iter)->image
            , 0.f, 0.f
            , (*iter)->image->GetWidth(), (*iter)->image->GetHeight());
    }
    ReleaseDC(g_hWnd, hdc);
}

int CBackGround::Update()
{
    return 0;
}

void CBackGround::AddFloorY(int y)
{
    m_vlineY.push_back(y);
}
