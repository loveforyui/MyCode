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
    
    if (isfirst)
    {
        Image* img = m_tInfo.GetImage(L"00.png");
        IMG_DRAW_I(
            hdc
            , img
            , 0.f, 0.f
            , img->GetWidth(), img->GetHeight());

        isfirst = false;
        return;
    }
    else
    {
        for (vector<ObjImg*>::iterator iter = ++m_tInfo.image->begin()
            ; iter != m_tInfo.image->end()
            ; ++iter)
        {
            IMG_DRAW_I(
                hdc
                , (*iter)->image
                , 0.f, 0.f
                , (*iter)->image->GetWidth(), (*iter)->image->GetHeight());
        }
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
