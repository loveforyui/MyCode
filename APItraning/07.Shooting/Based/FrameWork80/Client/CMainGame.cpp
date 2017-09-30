#include "stdafx.h"
#include "CMainGame.h"
#include "Player.h"
#include "Holdon.h"
#include "StateContext.h"
#include "States.h"

CMainGame* CMainGame::inst              = nullptr;

CMainGame::             CMainGame       ()
	: m_pPlayer(nullptr)
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
	// GetDC: DC�� �ڵ��� ������ �Լ�.
	// BeginPaint�� WM_PAINT �޽��� ���ο����� ���� ������ �Լ��� �ܺο����� GetDC�� ���;���.
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
}

void CMainGame::        Update          ()
{
    m_midObj->Update();
	m_pPlayer->Update();
    isEllipsed(m_pPlayer, m_midObj);
	//for (auto bullet : m_BulletList) // ���� ��� for��
	//	bullet->Update();

	OBJLIST::iterator iter_begin = m_BulletList.begin();
	OBJLIST::iterator iter_end = m_BulletList.end();

	for (; iter_begin != iter_end; ++iter_begin)
		(*iter_begin)->Update();
}

void CMainGame::        Render          ()
{
	Rectangle(m_hDC, 0, 0, WINCX, WINCY);

    m_midObj->Render(m_hDC);

	m_pPlayer->Render(m_hDC);

	for (auto bullet : m_BulletList)
		bullet->Render(m_hDC);
}

void CMainGame::        Release         ()
{
	// EndPaint �Լ��� WM_PAINT �޽��� ó�� ���ο����� ȣ�� ����.
	// ReleaseDC: �Ҵ���� DC�� �������ִ� �Լ�.
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
    return (*dest) && (*src);
}
