#pragma once
#include "Obj.h"


class CBuilding
    : public CObj
{
public:
    CBuilding();
    CBuilding(INFO& info);
    ~CBuilding();

public:
    // CObj��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Release() override;
    virtual void Render(HDC hdc) override;
    virtual int Update();
};