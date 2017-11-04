#pragma once

#include "Obj.h"

class CBomb
    : public CObj
{
public:
    CBomb();
    virtual ~CBomb();
public:
    // CObj��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Release() override;
    virtual void Render(HDC hdc) override;
    virtual int  Update();
    void isCollisionLine();
    void isJump();

private:
    float side;
    float ttt = 90.f;
    int end = 0;
};