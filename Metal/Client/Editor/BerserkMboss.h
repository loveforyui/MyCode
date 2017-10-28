#pragma once

#include "MonsterKind.h"

class CBerserkMboss
    : public CMonsterKind
{
public:
    CBerserkMboss();
    CBerserkMboss(CObj* pObj) { m_pObj = pObj; }
    virtual ~CBerserkMboss();

public:
    // CMonsterKind��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Render(HDC hdc) override;
    virtual void Release() override;
    virtual int Update();
};