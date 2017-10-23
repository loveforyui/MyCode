#include "stdafx.h"
#include "ScrollMgr.h"

IMPLEMENT_SINGLETON(CScrollMgr)

CScrollMgr::CScrollMgr()
{
}


CScrollMgr::~CScrollMgr()
{
}

void CScrollMgr::Update()
{
    if(m_fScrollX > -3823 + WINCX)
	    if (KEY_PRESSING(VK_RIGHT))
		    m_fScrollX -= 5.f;

    if(0 < -m_fScrollX)
	    if (KEY_PRESSING(VK_LEFT))
		    m_fScrollX += 5.f;
}
