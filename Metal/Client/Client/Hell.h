#pragma once

#include "MonsterKind.h"

class CHell
    : public CMonsterKind
{
public:
    enum HELLPASE {WAIT, PATROLL};
public:
    CHell();
    CHell(CObj* pObj) { m_pObj = pObj; Init(); }
    virtual ~CHell();

public:
    // CMonsterKind을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Render(HDC hdc) override;
    virtual void Release() override;
    virtual int  Update();

    void IsJump();

    void IsCollisionLine();

    void dropBomb();

    CObj * CreateBomb(vector<ObjImg*>* img, float fAngle);

private:
    INT         end         = 0;
    HELLPASE    fase        = WAIT;
    float       patAngle    = 180.f;

    CObj* boss;
    
    vector<ObjImg*>::iterator eff_begin;
    vector<ObjImg*>::iterator eff_end;

    vector<ObjImg*>* m_vBombimg;

    DWORD m_dwCurt = 0;
    DWORD m_dwOldt = GetTickCount();
};