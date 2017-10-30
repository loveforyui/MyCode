#pragma once
#include "Obj.h"

class CBullet
    : public CObj
{
public:
    enum BULLETPATTERN {LINE, CONIC, PAT_END};

public:
    CBullet();
    virtual ~CBullet();

public:
    // CObj��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Release() override;
    virtual void Render(HDC hdc) override;
    virtual int Update();

public:
    void SetBullPettern(BULLETPATTERN eid) { m_pattern = eid; }

public:
    void Line();
    void Conic();

    void IsCollisionLine();

private:
    BULLETPATTERN m_pattern = LINE;
    INT m_end = 0;
    INT m_distSum = 0;
};