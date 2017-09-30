#include "stdafx.h"
#include "Holdon.h"


Holdon::Holdon()
{
}


Holdon::~Holdon()
{
}

void Holdon::Initialize()
{

}

void Holdon::Initialize(INFO info, FLOAT speed)
{
    m_tInfo     = info;
    m_fSpeed    = speed;
}

void Holdon::Render(HDC hDC)
{
    Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void Holdon::Release()
{
}

int Holdon::Update()
{
    CObj::Update();
    
    return 0;
}
