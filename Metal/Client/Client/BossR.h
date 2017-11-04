#pragma once
#include "MonsterKind.h"

class CBossR
    : public CMonsterKind
{
public:
    CBossR();
    CBossR(CObj* pObj) { m_pObj = pObj; Init(); }
    virtual ~CBossR();

public:
    // CMonsterKind을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Render(HDC hdc) override;
    virtual void Release() override;
    virtual int  Update();

public:
    void rectMake();
    void PatternA();
    void Broken(HDC hdc);

private:
    INT eff_cnt = 0;
    vector<ObjImg*>::iterator eff_begin;
    vector<ObjImg*>::iterator eff_end;

    vector<ObjImg*>::iterator atk_begin;
    vector<ObjImg*>::iterator atk_end;

    vector<ObjImg*>::iterator kemuri_begin;
    vector<ObjImg*>::iterator kemuri_end;

    vector<ObjImg*>::iterator e_begin;
    vector<ObjImg*>::iterator e_end;
};