#pragma once

#include "Obj.h"

class CExplosion
    : public CObj
{
public:
    CExplosion();
    virtual ~CExplosion();
public:
    // CObj��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Release() override;
    virtual void Render(HDC hdc) override;
    virtual int  Update();
};