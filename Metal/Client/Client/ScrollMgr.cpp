#include "stdafx.h"
#include "ScrollMgr.h"
#include "Obj.h"

IMPLEMENT_SINGLETON(CScrollMgr)

CScrollMgr::CScrollMgr()
{
    char buf[256] = "";
    sprintf_s(buf, "%s%s", IMG_PATH, "scroll/");
    IMG_LOAD(L"scroll/", buf);

    m_image = IMG_GET_V(L"scroll/");
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
    if (m_fOffSet < pTarget->GetInfo().fX + m_fScrollX)
    {
        if (!isHold)
        {
            m_fScrollX -= pTarget->GetSpeed();
        }
    }
        

	/*if (m_fOffSet - 200.f > pTarget->GetInfo().fX + m_fScrollX)
		m_fScrollX += pTarget->GetSpeed();*/

    if (m_fScrollX < -3523)
    {
        m_fScrollX = -3523;
    }
}

void CScrollMgr::Render(HDC hdc)
{
    /*if (-m_fScrollX < m_image->back()->image->GetWidth())
        IMG_DRAW_I(hdc, m_image->back()->image, 0, 0, m_image->back()->image->GetWidth(), m_image->back()->image->GetHeight());
    else
        IMG_DRAW_I(hdc, m_image->back()->image, 0, 0, m_image->back()->image->GetWidth(), m_image->back()->image->GetHeight());*/
}
