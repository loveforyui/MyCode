#pragma once

#include "Obj.h"

class CItem
    : public CObj
{
public:
    CItem();
    CItem(INFO& info) { m_tInfo = info; }
    virtual ~CItem();

public:
    // CObj��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Release() override;
    virtual void Render(HDC hdc) override;
    virtual int  Update();
    void CollisionSphere(OBJLIST & dst, OBJLIST & src);
    void IsJump();
    void IsCollisionLine();
public:
    ITEMKINDE kind;
};