#pragma once
#include "Obj.h"

class CThings
    : public CObj
{
public:
    CThings();
    CThings(INFO& info) { m_tInfo = info; }
    ~CThings();
public:
    // CObj을(를) 통해 상속됨
    virtual void    Init() override;
    virtual void    Release() override;
    virtual void    Render(HDC hdc) override;
    virtual int     Update();
};