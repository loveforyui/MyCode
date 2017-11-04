#pragma once

#include "MonsterKind.h"

class CBossBody
    : public CMonsterKind
{
public:
    enum BOSSSTANCE {WAIT, STAY, PATROL};
public:
    CBossBody();
    CBossBody(CObj* pObj) { m_pObj = pObj; Init(); }
    virtual ~CBossBody();

public:
    // CMonsterKind을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Render(HDC hdc) override;
    virtual void Release() override;
    virtual int  Update();


public:
    void Wait();
    void Patrol();
    void Stay();

    void BothDeath();

private:
    BOSSSTANCE stance = WAIT;

    CObj* m_left;
    CObj* m_right;
    CObj* m_top;

    float rotate = 30.f;
    float rotateX;
    float rotateY;
    float rotateW;
    float rotateH;

    const float sideDist = 90.f;
};