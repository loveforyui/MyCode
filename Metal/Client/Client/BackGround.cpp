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
    Graphics rend(hdc);
    IMG_DRAW_B(hdc, L"BackGround", L"background_line.png", 0.f, 0.f);
}

int CBackGround::Update()
{
    return 0;
}

void CBackGround::AddFloorY(int y)
{
    m_vlineY.push_back(y);
}
