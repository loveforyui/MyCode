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
    int Update();
    void Render(HDC hdc);

public:
    OBJLIST&    GetObjlst(OBJID eId) { return m_objLst[eId]; }
    OBJLIST&    GetObjlst(INT eIn) { return m_objLst[eIn]; }
    CObj*       FindObject(OBJID eId)
    {
        if (m_objLst[eId].empty())
            return nullptr;

        return m_objLst[eId].back();
    }
    void        AddObj(CObj* pObj, OBJID eId);

public:
    

    void SaveData();

    void LoadData();

private:
    static CObjManager* inst;

    // OBJLIST
    OBJLIST                 m_objLst[OBJ_END];
};


#define OBJ_MGR_GETLIST(ObjId) CObjManager::GetInst()->GetObjlst(ObjId)