#pragma once
#include "Obj.h"

class CMonster
    : public CObj
{
public:
    CMonster();
    CMonster(INFO& info) { m_tInfo = info; }
    virtual ~CMonster();

public:
    // CObj을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Release() override;
    virtual void Render(HDC hdc) override;
    virtual int  Update();
};