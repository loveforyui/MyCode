#pragma once
#include "MonsterKind.h"

class CBabarian
    : public CMonsterKind
{
public:
    CBabarian();
    CBabarian(CObj* pObj) { m_pObj = pObj; }
    virtual ~CBabarian();

    // CMonsterKind을(를) 통해 상속됨
    virtual void Init() override;

    virtual void Render(HDC hdc) override;

    virtual void Release() override;

    virtual int  Update();

};
