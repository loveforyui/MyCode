#include "stdafx.h"
#include "ObjManager.h"
#include "Obj.h"
#include "Things.h"
#include "Monster.h"
#include "Bullet.h"
#include "Mouse.h"

CObjManager* CObjManager::inst = nullptr;

CObjManager::CObjManager()
{
}

CObjManager::~CObjManager()
{
}

int CObjManager::       Update          ()
{
    CCollisionManager::CollisionSphere(m_objLst[OBJ_MONSTER], m_objLst[OBJ_P_BULLET]);
    CCollisionManager::CollisionSphere(m_objLst[OBJ_M_BULLET], m_objLst[OBJ_P_BULLET]);

    for (int objid = 0; objid < OBJ_END; ++objid)
    {

        for (OBJITER iter = m_objLst[objid].begin()
            ; iter != m_objLst[objid].end();)
        {
            int iEvent = (*iter)->Update();

            if (1 == iEvent)
            {
                SafeDelete<CObj*>(*iter);
                iter = m_objLst[objid].erase(iter);
            }
            else
                ++iter;
        }
    }

    // Things와 bullet 충돌시켜야함
    // things와 player 충돌은 탑부분만
    // 기본적으로 player와 monster는 충돌 안함
    // monster의 bullet과 충돌
    //CCollisionManager::CollisionRect(m_objLst[OBJ_PLAYER], m_objLst[OBJ_THINGS]);
    return 0;
}

void CObjManager::      Render          (HDC hDC)
{
    HDC hdc = GetDC(g_hWnd);
    float fScrollX = CScrollMgr::GetInstance()->GetScrollX();
    for (int i = 0; i < OBJ_END; ++i)
    {
        OBJITER iter_begin = m_objLst[i].begin();
		OBJITER iter_end = m_objLst[i].end();

        if(!m_objLst[i].empty())
            for (; iter_begin != iter_end; ++iter_begin)
            {
                (*iter_begin)->Render(hDC);         
            }
	}
}

void CObjManager::      AddObj          (CObj * pObj, OBJID eId)
{
    m_objLst[eId].push_back(pObj);
}

void CObjManager::      LoadData        ()
{
    LoadThings();
    LoadMonster();
}

void CObjManager::      LoadThings      ()
{
    HANDLE hFile = CreateFile(L"../Data/ThingsData.dat", GENERIC_READ, 0, 0
		, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

	if (INVALID_HANDLE_VALUE == hFile)
	{
		MessageBox(g_hWnd, L"../Data/ThingsData", L"Load failed!!!", MB_OK);
		return;
	}

	INFO tInfo;
	DWORD dwBytes = 0;

	while (true)
	{
		ReadFile(hFile, &tInfo, sizeof(INFO), &dwBytes, nullptr);

		if (0 == dwBytes)
			break;

		m_objLst[OBJ_THINGS].push_back(new CThings(tInfo));
	}

	CloseHandle(hFile);
}

void CObjManager::      LoadMonster     ()
{
    HANDLE hFile = CreateFile(L"../Data/MonsterData.dat", GENERIC_READ, 0, 0
		, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

	if (INVALID_HANDLE_VALUE == hFile)
	{
		MessageBox(g_hWnd, L"../Data/MonsterData", L"Load failed!!!", MB_OK);
		return;
	}

	INFO tInfo;
	DWORD dwBytes = 0;

	while (true)
	{
		ReadFile(hFile, &tInfo, sizeof(INFO), &dwBytes, nullptr);

		if (0 == dwBytes)
			break;

        m_objLst[OBJ_MONSTER].push_back(new CMonster(tInfo));
	}

	CloseHandle(hFile);
}