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

	// 현재 화면 좌표 상의 오프셋과 플레이어 좌표를 비교한다.
	if (m_fOffSet + 200.f < pTarget->GetInfo().fX + m_fScrollX)
		m_fScrollX -= 10.f;

	if (m_fOffSet - 200.f > pTarget->GetInfo().fX + m_fScrollX)
		m_fScrollX += 10.f;
}
