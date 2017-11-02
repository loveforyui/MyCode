#pragma once

#include "MonsterKind.h"

class CObj;
class CSamBody
    : public CMonsterKind
{
public:
    CSamBody();
    CSamBody(CObj* pObj) { m_pObj = pObj; Init(); }
    virtual ~CSamBody();

public:
    // CMonsterKind을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Render(HDC hdc) override;
    virtual void Release() override;
    virtual int  Update();

private:
    CObj* m_left;
    CObj* m_right;
    CObj* m_center;

    vector<CObj*> m_vSol;
    vector<CObj*> m_vDoor;
    vector<CObj*> m_vEffect;

    FLOAT scroll = 1.f;
};