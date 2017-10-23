#include "stdafx.h"
#include "ObjManager.h"
#include "Obj.h"

CObjManager* CObjManager::inst = nullptr;

CObjManager::CObjManager()
{
}

CObjManager::~CObjManager()
{
}

int CObjManager::Update()
{
    for (auto obj : m_objLst)
    {
        for (auto i : obj)
        {
            i->Update();
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
