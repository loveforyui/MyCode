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

void CObjManager::AddObj(CObj * pObj, OBJID eId)
{
    m_objLst[eId].push_back(pObj);
}
