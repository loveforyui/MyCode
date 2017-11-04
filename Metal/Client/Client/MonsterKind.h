#pragma once

class CMonsterKind
{
public:
    CMonsterKind();
    virtual ~CMonsterKind();

public:
    virtual void Init() = 0;
    virtual void Render(HDC hdc) = 0;
    virtual void Release() = 0;
    virtual int Update() { return 0; }

public:
    void SetObj(CObj* pObj) { m_pObj = pObj; }
    
public:
    vector<ObjImg*>::iterator GetBegin() { return iter_begin; }
    map<const TCHAR*, vector<ObjImg*>*>* GetImgVector() { return m_mImage; }

protected:
    CObj*                                   m_pObj;
    ObjImg*                                 m_curImg;
    map<const TCHAR*, vector<ObjImg*>*>*    m_mImage;
    vector<ObjImg*>::iterator               iter_begin;
    vector<ObjImg*>::iterator               iter_end;
};