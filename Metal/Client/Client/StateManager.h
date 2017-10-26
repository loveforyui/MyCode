#pragma once
#include "Obj.h"

class CStateManager
{
public:
    CStateManager();
    virtual ~CStateManager();
public:
    virtual void    initialize() = 0;

public:
    virtual void    handle(HDC hdc) = 0;
    void            SetImage(vector<ObjImg*>* img)
    { 
        m_vImage    = img;
        iter_begin  = img->begin();
        iter_end    = img->end();
    }
    void            SetObj(OBJID eId) { m_pObjLst = &OBJ_MGR_GETLIST(eId); }
    void            SetIterator(INT index) { m_incre = index; }
    void            SetIterator(vector<ObjImg*>::iterator iter) { iter_begin = iter; }
public:
    vector<ObjImg*>* GetImgVector() { return m_vImage; }

protected:
    OBJLIST*                    m_pObjLst;
    vector<ObjImg*>*            m_vImage;
    vector<ObjImg*>::iterator   iter_begin;
    vector<ObjImg*>::iterator   iter_end;
    int m_incre = 0;
};