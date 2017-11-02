#pragma once
#include "MonsterKind.h"

class CSamSol
    : public CMonsterKind
{
public:
    CSamSol();
    CSamSol(CObj* pObj) { m_pObj = pObj; Init(); }
    virtual ~CSamSol();

public:
    // CMonsterKind을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Render(HDC hdc) override;
    virtual void Release() override;
    virtual int  Update();

    CObj * CreateBullet(vector<ObjImg*>* img, float fAngle);

private:
    DWORD m_dwCt;
    DWORD m_dwOt;

    vector<ObjImg*>::iterator smoke_begin;
    vector<ObjImg*>::iterator smoke_end;
    bool isShoot = false;
    int end = 0;
};