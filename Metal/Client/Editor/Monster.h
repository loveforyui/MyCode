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
    void SetKind(CMonsterKind* kind);
    void SetKind(eKMOB ekmb);

public:
    CMonsterKind* GetKind() { return m_Kind; }

public:
    // CObj을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Release() override;
    virtual void Render(HDC hdc) override;
    virtual int  Update();
    void         IsCollisionLine();
    float        FollowLine();

private:
    CMonsterKind*   m_Kind;
    eKMOB           m_eKind;
};










//#pragma once
//#include "Obj.h"
//
//class CMonster
//    : public CObj
//{
//public:
//    CMonster();
//    CMonster(INFO& info) { m_tInfo = info; }
//    virtual ~CMonster();
//
//public:
//    // CObj을(를) 통해 상속됨
//    virtual void Init() override;
//    virtual void Release() override;
//    virtual void Render(HDC hdc) override;
//    virtual int  Update();
//};