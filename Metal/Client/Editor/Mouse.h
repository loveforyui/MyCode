#pragma once
#include "Obj.h"

class CMouse
    : public CObj
{
public:
    CMouse();
    ~CMouse();

public:
    // CObj을(를) 통해 상속됨
    virtual void    Init() override;
    virtual void    Release() override;
    virtual void    Render(HDC hdc) override;
    virtual int     Update();

public:
    static POINT GetMousePos();
};

