#pragma once

#include "MonsterKind.h"

class CSamBdoor
    : public CMonsterKind
{
public:
    CSamBdoor();
    CSamBdoor(CObj* pObj) { m_pObj = pObj; Init(); }
    virtual ~CSamBdoor();

public:
    // CMonsterKind��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Render(HDC hdc) override;
    virtual void Release() override;
    virtual int  Update();

private:
    INT end = 0;
    float multiple = 1.0f;
};