#pragma once

#include "Obj.h"

class CShotgun
    : public CObj
{
public:
    CShotgun();
    virtual ~CShotgun();
public:
    // CObj을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Release() override;
    virtual void Render(HDC hdc) override;
    virtual int  Update();
private:
    INT end = 0;
};