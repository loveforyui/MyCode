#include "stdafx.h"
#include "ScrollMgr.h"
#include "Obj.h"

IMPLEMENT_SINGLETON(CScrollMgr)

CScrollMgr::CScrollMgr()
{
}


CScrollMgr::~CScrollMgr()
{
}

void CScrollMgr::Update()
{
	// 현재 화면 좌표 상의 오프셋과 플레이어 좌표를 비교한다.
    if(-m_fScrollX < 3823)
        if (KEY_PRESSING(VK_RIGHT))
            m_fScrollX -= 10.f;

    if(0 > m_fScrollX)
        if (KEY_PRESSING(VK_LEFT))
            m_fScrollX += 10.f;
}
