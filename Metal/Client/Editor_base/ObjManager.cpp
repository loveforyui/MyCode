#include "stdafx.h"
#include "ObjManager.h"
#include "Obj.h"
#include "Building.h"
//#include "Monster.h"

CObjManager* CObjManager::inst = nullptr;

CObjManager::CObjManager()
{
}

CObjManager::~CObjManager()
{
}

int CObjManager::Update()
{
    for (int i = 0 ; i < OBJ_END; ++i)
    {
        if (m_objLst[i].empty())
            continue;

        for (list<CObj*>::iterator iter = m_objLst[i].begin()
            ; iter != m_objLst[i].end();)
        {
            int iEvent = (*iter)->Update();

            if (1 == iEvent || (*iter)->isDead())
            {
                //SafeDelete<CObj*>(*iter);
                delete (*iter);
                (*iter) = nullptr;
                iter = m_objLst[i].erase(iter);
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

                if (m_objLst[i] != m_objLst[OBJ_MOUSE])
                {
                    wchar_t         pos[64];
                    swprintf_s(pos, L"X:%.2f Y:%.2f", (*iter_begin)->GetInfo().fX, (*iter_begin)->GetInfo().fY);
                    SetTextAlign(hdc, TA_CENTER);
                    SetBkMode(hdc, TRANSPARENT);
                    TextOut(hdc, (*iter_begin)->GetInfo().fX + CScrollMgr::GetInstance()->GetScrollX(), (*iter_begin)->GetInfo().fY - 30, pos, wcslen(pos));
                }           
            }
	}
}

void CObjManager::AddObj(CObj * pObj, OBJID eId)
{
    m_objLst[eId].push_back(pObj);
}

void CObjManager::SaveData()
{
	HANDLE hFile = CreateFile(L"../Data/MonsterData.dat", GENERIC_WRITE, 0, 0
		, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);

	if (INVALID_HANDLE_VALUE == hFile)
	{
		MessageBox(g_hWnd, L"../Data/Monster.dat", L"Save failed!!", MB_OK);
		return;
	}

	DWORD dwBytes = 0;


	for (auto pMonster : m_objLst[OBJ_THINGS])
	{
		// WriteFile: API의 파일 출력 함수.
		WriteFile(hFile, &(pMonster->GetInfo()), sizeof(INFO), &dwBytes, nullptr);
	}

	CloseHandle(hFile);
}
void CObjManager::LoadData()
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

		m_objLst[OBJ_THINGS].push_back(new CBuilding(tInfo));
	}

	CloseHandle(hFile);
}