#pragma once
#include "CObj.h"
class Holdon :
    public CObj
{
public:
    Holdon();
    ~Holdon();

    // CObj을(를) 통해 상속됨
    virtual void    Initialize();
    virtual void    Initialize(INFO, FLOAT);
    virtual void    Render(HDC);
    virtual void    Release();
    virtual int     Update();
};

