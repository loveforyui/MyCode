#include "stdafx.h"
#include "ObjManager.h"
#include "Obj.h"
#include "Things.h"
#include "Monster.h"

CObjManager* CObjManager::inst = nullptr;

CObjManager::CObjManager()
{
}

CObjManager::~CObjManager()
{
}

int CObjManager::Update()
{
    for (int objid = 0; objid < OBJ_END; ++objid)
    {
        for (OBJITER iter = m_objLst[objid].begin()
            ; iter != m_objLst[objid].end();)
        {
            int iEvent = (*iter)->Update();

            if (1 == iEvent)
            {
                delete (*iter);
                iter = m_objLst[objid].erase(iter);
            }
            else
                ++iter;
        }
    }

    return 0;
}

void CObjManager::Render(HDC hdc)
{
    for (int i = 0; i < OBJ_END; ++i)
    {
        OBJITER iter_begin = m_objLst[i].begin();
		OBJITER iter_end = m_objLst[i].end();

        if(!m_objLst[i].empty())
            for (; iter_begin != iter_end; ++iter_begin)
            {
                (*iter_begin)->Render(hdc);         
            }
	}
}

void CObjManager::AddObj(CObj * pObj, OBJID eId)
{
    m_objLst[eId].push_back(pObj);
}

void CObjManager::SaveData()
{
    SaveThings();
    SaveMonster();
}

void CObjManager::SaveThings()
{
    HANDLE hFile = CreateFile(L"../Data/ThingsData.dat", GENERIC_WRITE, 0, 0
		, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);

	if (INVALID_HANDLE_VALUE == hFile)
	{
		MessageBox(g_hWnd, L"../Data/ThingsData.dat", L"Save failed!!", MB_OK);
		return;
	}

	DWORD dwBytes = 0;


	for (auto pMonster : m_objLst[OBJ_THINGS])
	{
		// WriteFile: API의 파일 출력 함수.
		WriteFile(hFile, &(pMonster->GetInfo()), sizeof(INFO), &dwBytes, nullptr);
	}

    for (auto pMonster : m_objLst[OBJ_THINGS])
	{
		// WriteFile: API의 파일 출력 함수.
		WriteFile(hFile, &(pMonster->GetInfo()), sizeof(INFO), &dwBytes, nullptr);
	}

	CloseHandle(hFile);
}

void CObjManager::SaveMonster()
{
    HANDLE hFile = CreateFile(L"../Data/MonsterData.dat", GENERIC_WRITE, 0, 0
		, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);

	if (INVALID_HANDLE_VALUE == hFile)
	{
		MessageBox(g_hWnd, L"../Data/MonsterData.dat", L"Save failed!!", MB_OK);
		return;
	}

	DWORD dwBytes = 0;


	for (auto pMonster : m_objLst[OBJ_MONSTER])
	{
		// WriteFile: API의 파일 출력 함수.
		WriteFile(hFile, &(pMonster->GetInfo()), sizeof(INFO), &dwBytes, nullptr);
	}

    for (auto pMonster : m_objLst[OBJ_MONSTER])
	{
		// WriteFile: API의 파일 출력 함수.
		WriteFile(hFile, &(pMonster->GetInfo()), sizeof(INFO), &dwBytes, nullptr);
	}

	CloseHandle(hFile);
}

void CObjManager::LoadData()
{
    LoadThings();
    LoadMonster();
}

void CObjManager::LoadThings()
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

void CObjManager::LoadMonster()
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