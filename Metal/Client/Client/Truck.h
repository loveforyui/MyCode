#pragma once
#include "MonsterKind.h"

class CTruck
    : public CMonsterKind
{
public:
    CTruck();
    CTruck(CObj* pObj) { m_pObj = pObj; Init(); }
    virtual ~CTruck();

public:
    // CMonsterKind을(를) 통해 상속됨
    virtual void    Init                () override;
    virtual void    Render              (HDC hdc) override;
    virtual void    Release             () override;
    virtual int     Update              ();

public:
    void            PatternA            ();

public:
    void            IsCollisionLine     ();

private:
    DWORD m_dwCregT = 0;
    DWORD m_dwOregT = 0;
};
