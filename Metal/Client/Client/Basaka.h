#pragma once

#include "MonsterKind.h"

class CBasaka
    : public CMonsterKind
{
public:
    CBasaka();
    CBasaka(CObj* pObj) { m_pObj = pObj; Init(); }
    virtual ~CBasaka();

public:
    // CMonsterKind��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Render(HDC hdc) override;
    virtual void Release() override;
    virtual int  Update();

private:
    int end = 0;
};