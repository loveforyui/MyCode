#pragma once

#include "MonsterKind.h"

class CSamD
    : public CMonsterKind
{
public:
    CSamD();
    CSamD(CObj* pObj) { m_pObj = pObj; Init(); }
    virtual ~CSamD();

public:
    // CMonsterKind을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Render(HDC hdc) override;
    virtual void Release() override;
    virtual int  Update();
};