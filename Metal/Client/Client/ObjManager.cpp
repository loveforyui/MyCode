#include "stdafx.h"
#include "ObjManager.h"

CObjManager* CObjManager::inst = nullptr;

CObjManager::CObjManager()
{
}

CObjManager::~CObjManager()
{
}

void CObjManager::AddObj(CObj * pObj, OBJID eId)
{
    m_objLst[eId].push_back(pObj);
}
