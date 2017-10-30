#pragma once

#include "MonsterKind.h"

class CBerserkMboss
    : public CMonsterKind
{
public:
    CBerserkMboss();
    CBerserkMboss(CObj* pObj) { m_pObj = pObj; Init(); }
    virtual ~CBerserkMboss();

public:
    // CMonsterKind을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Render(HDC hdc) override;
    virtual void Release() override;
    virtual int Update();
    void CalcRect();
    void PatternS();
    void PatternA();
    void PatternB();
    void PatternL();
    void IsCollisionLine();
    CObj * CreateBullet(vector<ObjImg*>* img, float fAngle);
    void InsertImage(const TCHAR * key, vector<ObjImg*>* vImg);

private:
    INT m_fase = 1;
    INT endl = 0;
    POINT ePt;
    FLOAT fend = 90.f;

    vector<ObjImg*>::iterator iter_b;
    vector<ObjImg*>::iterator iter_e;
};