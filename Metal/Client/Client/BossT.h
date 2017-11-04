#pragma once
#include "MonsterKind.h"

class CBossT
    : public CMonsterKind
{
public:
    CBossT();
    CBossT(CObj* pObj) { m_pObj = pObj; Init(); }
    virtual ~CBossT();

public:
    // CMonsterKind을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Render(HDC hdc) override;
    virtual void Release() override;
    virtual int  Update();

public:
    void MakeSoldier();

private:
    DWORD m_dwCurt;
    DWORD m_dwOldt;
};