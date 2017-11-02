#pragma once
#include "MonsterKind.h"

class CSamR
    : public CMonsterKind
{
public:
    CSamR();
    CSamR(CObj* pObj) { m_pObj = pObj; Init(); }
    virtual ~CSamR();

public:
    // CMonsterKind을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Render(HDC hdc) override;
    virtual void Release() override;
    virtual int  Update();

public:
    vector<ObjImg*>::iterator GetMoveBegin() { return Move_begin; }

private:
    vector<ObjImg*>::iterator Move_begin;
    vector<ObjImg*>::iterator Move_end;

    CObj* m_Door;
    CObj* m_Sol;
};