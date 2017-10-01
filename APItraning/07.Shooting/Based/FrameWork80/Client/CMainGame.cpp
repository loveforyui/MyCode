#include "stdafx.h"
#include "CMainGame.h"

#include "Player.h"
#include "Holdon.h"
#include "PatrolMon.h"

#include "StateContext.h"
#include "States.h"

CMainGame* CMainGame::inst              = nullptr;

CMainGame::             CMainGame       ()
	: m_pPlayer(nullptr), m_midObj(nullptr), m_ptrObj(nullptr)
{
}

CMainGame::             ~CMainGame      ()
{
	Release();
}

CMainGame * CMainGame:: getInst         ()
{
    if (nullptr == inst)
    {
        inst = new CMainGame;
    }
    return inst;
}

void CMainGame::        Initialize      ()
{
	// GetDC: DC의 핸들을 얻어오는 함수.
	// BeginPaint는 WM_PAINT 메시지 내부에서만 수행 가능한 함수라서 외부에서는 GetDC로 얻어와야함.
	m_hDC = GetDC(g_hWnd);
    GetClientRect(g_hWnd, &m_wndRect);

    if (nullptr == m_midObj)
	{
        INFO templaryInfo { FLOAT(m_wndRect.right) / 2, FLOAT(m_wndRect.bottom - 300), 600.f, 300.f };
		m_midObj = new Holdon;
        m_midObj->Initialize(templaryInfo, 0.f);
	}

	if (nullptr == m_pPlayer)
	{
        INFO templaryInfo { FLOAT(m_wndRect.right) / 2, FLOAT(m_wndRect.bottom - 50), 50.f, 50.f };
		m_pPlayer = new CPlayer;
        m_pPlayer->Initialize(templaryInfo, 10.f);
		dynamic_cast<CPlayer*>(m_pPlayer)->SetBulletList(&m_BulletList);
	}

    if (nullptr == m_ptrObj)
    {
        INFO templaryInfo { FLOAT(m_wndRect.right) / 2, FLOAT(m_wndRect.bottom - 400), 50.f, 50.f };
        m_ptrObj = new PatrolMon;
        m_ptrObj->Initialize(templaryInfo, 10.f);
    }
}

void CMainGame::        Update          ()
{
    m_midObj->Update();
	m_pPlayer->Update();
    
    // isEllipsed player to midRect?
    isEllipsed(m_pPlayer, m_midObj);

    // isEllipsed PatrolMonster to MidRect?
    if (isEllipsed(m_ptrObj, m_midObj))
    {
        switch (m_ptrObj->GetDirection())
        {
        case D_LEFT:
            m_ptrObj->SetDirection(D_RIGHT);
            break;
        case D_RIGHT:
            m_ptrObj->SetDirection(D_LEFT);
            break;
        }
    }
    m_ptrObj->Update();
    //--------------------------------------------

	//for (auto bullet : m_BulletList) // 범위 기반 for문
	//	bullet->Update();

    for (OBJLIST::iterator iter = m_BulletList.begin();
        iter != m_BulletList.end();)
    {
        (*iter)->Update();
        if (isEllipsed((*iter), m_midObj))
        {
            iter = m_BulletList.erase(iter);
        }
        else if (isEllipsed((*iter), m_ptrObj))
        {
            iter = m_BulletList.erase(iter);
        }
        else
        {
            ++iter;
        }
    }
		
}

void CMainGame::        Render          ()
{
	Rectangle(m_hDC, 0, 0, WINCX, WINCY);

    m_midObj->Render(m_hDC);

	m_pPlayer->Render(m_hDC);

    m_ptrObj->Render(m_hDC);

	for (auto bullet : m_BulletList)
		bullet->Render(m_hDC);
}

void CMainGame::        Release         ()
{
	// EndPaint 함수도 WM_PAINT 메시지 처리 내부에서만 호출 가능.
	// ReleaseDC: 할당받은 DC를 해제해주는 함수.
	ReleaseDC(g_hWnd, m_hDC);

	SAFEDELETE<CObj*>(m_pPlayer);

    for_each(m_BulletList.begin(), m_BulletList.end(), 
	[](CObj*& pObj)
	{
		if (pObj)
		{
			delete pObj;
			pObj = nullptr;
		}
	});

	m_BulletList.clear();
}

BOOL CMainGame::        isEllipsed      (CObj * dest, CObj * src)
{
    return (*dest) || (*src);
}
