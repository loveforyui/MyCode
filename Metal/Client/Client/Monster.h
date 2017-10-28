#pragma once
#include "Obj.h"
#include "MonsterKind.h"
#include "BabarianBase.h"

class CMonster
    : public CObj
{
public:
    CMonster();
    CMonster(INFO& info);
    virtual ~CMonster();

public:
    void            SetKind         (CMonsterKind* kind);
    void            SetKind         (eKMOB ekmb);

public:
    CMonsterKind*   GetKind         () { return m_Kind; }

public:
    // CObj을(를) 통해 상속됨
    virtual void    Init            () override;
    virtual void    Release         () override;
    virtual void    Render          (HDC hdc) override;
    virtual int     Update          ();

public:
    void            IsJump          ();
    float           FollowLine      ();
    void            IsCollisionLine ();

public:
    void            SetBulletImg    (vector<ObjImg*>* vimg) { m_vBulletimg = vimg; }

public:
    vector<ObjImg*>* GetBulletImg   () { return m_vBulletimg; }

private:
    CMonsterKind*   m_Kind;
    eKMOB           m_eKind;

    vector<ObjImg*>* m_vBulletimg;
};