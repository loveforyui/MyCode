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
	CObj* pTarget = CObjManager::GetInst()->FindObject(OBJ_PLAYER);

	if (nullptr == pTarget)
		return;

	// ���� ȭ�� ��ǥ ���� �����°� �÷��̾� ��ǥ�� ���Ѵ�.
    if (200 < pTarget->GetInfo().fX + m_fScrollX)
        m_fScrollX -= pTarget->GetSpeed();

	/*if (m_fOffSet - 200.f > pTarget->GetInfo().fX + m_fScrollX)
		m_fScrollX += pTarget->GetSpeed();*/

    if (m_fScrollX < -3390)
    {
        m_fScrollX = -3390;
    }
}
