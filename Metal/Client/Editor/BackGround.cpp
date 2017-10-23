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
    for (vector<ObjImg*>::iterator iter = m_tInfo.image->begin()
        ; iter != m_tInfo.image->end(); ++iter)
    {
        IMG_DRAW_I(
            hdc
            , (*iter)->image
            , m_tInfo.fX
            , m_tInfo.fY
            , m_tInfo.fCX
            , m_tInfo.fCY
        );
    }
    
}

int CBackGround::Update()
{
    CObj::Update();

    return 0;
}