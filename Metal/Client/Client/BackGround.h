#pragma once

#include "Obj.h"

class CBackGround
    : public CObj
{
public:
    CBackGround();
    virtual ~CBackGround();

public:
    // CObj을(를) 통해 상속됨
    virtual void    Init() override;
    virtual void    Release() override;
    virtual void    Render(HDC hdc) override;
    virtual int     Update();

public:
    void AddFloorY(int y);

private:
    vector<INT> m_vlineY;
};