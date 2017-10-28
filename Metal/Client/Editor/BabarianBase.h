#pragma once
#include "MonsterKind.h"

class CBabarian
    : public CMonsterKind
{
public:
    CBabarian();
    CBabarian(CObj* pObj) { m_pObj = pObj; }
    virtual ~CBabarian();

    // CMonsterKind��(��) ���� ��ӵ�
    virtual void Init() override;

    virtual void Render(HDC hdc) override;

    virtual void Release() override;

    virtual int  Update();

};
