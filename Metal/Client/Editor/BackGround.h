#pragma once

#include "Obj.h"

class CBackGround
    : public CObj
{
public:
    CBackGround();
    ~CBackGround();

public:
    // CObj��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Release() override;
    virtual void Render(HDC hdc) override;
    virtual int  Update();
};