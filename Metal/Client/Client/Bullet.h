#pragma once
#include "Obj.h"

class CBullet
    : public CObj
{
public:
    enum BULLETPATTERN {LINE, CONIC, UDO, PAT_END};

public:
    CBullet();
    virtual ~CBullet();

public:
    // CObj을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Release() override;
    virtual void Render(HDC hdc) override;
    virtual int Update();

public:
    void SetBullPettern(BULLETPATTERN eid) { m_pattern = eid; }

public:
    void Line();
    void Conic();

    void Udo();

    void IsCollisionLine();

private:
    BULLETPATTERN m_pattern = LINE;
    INT m_end = 0;
    INT m_distSum = 0;

    FLOAT minAngle;
    FLOAT maxAngle;
    FLOAT cAngle;
    FLOAT incA = 5.f;
};