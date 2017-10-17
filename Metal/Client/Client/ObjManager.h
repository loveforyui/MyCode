#pragma once

class CObj;
class CObjManager
{
private:
    CObjManager();
    ~CObjManager();

public:
    static CObjManager* GetInst()
    {
        if (nullptr == inst)
            inst = new CObjManager;

        return inst;
    }
    void Destroy()
    {
        if (inst)
        {
            delete inst;
            inst = nullptr;
        }
    }
    
public:
    OBJLIST& GetObjlst(OBJID eId) { return m_objLst[eId]; }
    OBJLIST& GetObjlst(INT eIn) { return m_objLst[eIn]; }

public:
    void AddObj(CObj* pObj, OBJID eId);

private:
    static CObjManager* inst;

    // OBJLIST
    OBJLIST                 m_objLst[OBJ_END];
};


#define OBJ_MGR_GETLIST(ObjId) CObjManager::GetInst()->GetObjlst(ObjId)