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
	// ���� ȭ�� ��ǥ ���� �����°� �÷��̾� ��ǥ�� ���Ѵ�.
    if(-m_fScrollX < 3823)
        if (KEY_PRESSING(VK_RIGHT))
            m_fScrollX -= 10.f;

    if(0 > m_fScrollX)
        if (KEY_PRESSING(VK_LEFT))
            m_fScrollX += 10.f;
}
