#pragma once
#include "Obj.h"

class CBullet
    : public CObj
{
public:
    CBullet();
    virtual ~CBullet();

public:
    // CObj��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Release() override;
    virtual void Render(HDC hdc) override;
    virtual int Update();
};