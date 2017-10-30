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
    // CMonsterKind��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Render(HDC hdc) override;
    virtual void Release() override;
    virtual int Update();
    void CalcRect();
    void PatternS();
    void PatternA();
    void PatternB();
    void IsCollisionLine();
    void InsertImage(const TCHAR * key, vector<ObjImg*>* vImg);

private:
    INT m_fase = 1;

    vector<ObjImg*>::iterator iter_b;
    vector<ObjImg*>::iterator iter_e;
};