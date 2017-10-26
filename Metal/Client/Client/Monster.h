#pragma once
#include "Obj.h"

class CMonster
    : public CObj
{
public:
    CMonster();
    CMonster(INFO& info) { m_tInfo = info; }
    virtual ~CMonster();

public:
    // CObj��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Release() override;
    virtual void Render(HDC hdc) override;
    virtual int  Update();
};