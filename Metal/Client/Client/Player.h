#pragma once
#include "Obj.h"

class CPlayer
    : public CObj
{
public:
    CPlayer();
    ~CPlayer();

public:
    // CObj��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Release() override;
    virtual void Render(HDC hdc) override;
    virtual int  Update();

private:
};