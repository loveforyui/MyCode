#pragma once
#include "Obj.h"

class CMouse
    : public CObj
{
public:
    CMouse();
    ~CMouse();

public:
	static POINT GetMousePos();

    // CObj��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Release() override;
    virtual void Render(HDC hdc) override;
    virtual int Update();
};