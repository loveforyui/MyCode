#include "stdafx.h"
#include "Monster.h"
#include "BabarianBase.h"
#include "BerserkMboss.h"
#include "Truck.h"

CMonster::CMonster()
{
    m_tInfo.fSpeed = 2.f;
    m_tInfo.fAcc = 0.f;
}

CMonster::CMonster(INFO& info)
    : CObj(info)
{
    SetKind(m_tInfo.m_eKind);
    m_tInfo.fSpeed = 2.f;
    m_tInfo.fAcc = 0.f;
    //m_tInfo.curState = OBJ_A_STND;
    m_tInfo.isDead = false;
}

CMonster::~CMonster()
{
    Release();
}

void CMonster::     SetKind         (CMonsterKind * kind)
{
    if (nullptr == m_Kind)
        m_Kind = kind;
}

void CMonster::     SetKind         (eKMOB ekmb)
{
    switch (ekmb)
    {
    case MOB_K_BABA:
    {
        SetKind(new CBabarian(this));
        m_tInfo.m_eKind = MOB_K_BABA;
    }
        break;
    case MOB_K_BAKING:
    {
        SetKind(new CBerserkMboss(this));
        m_tInfo.m_eKind = MOB_K_BAKING;
    }
        break;
    case MOB_K_TRUCK:
    {
        SetKind(new CTruck(this));
        m_tInfo.m_eKind = MOB_K_TRUCK;
    }
        break;
    }
}

void CMonster::     Init            ()
{
    
}

void CMonster::     Release         ()
{
}

void CMonster::     Render          (HDC hdc)
{
    /*HBRUSH brush    = CreateSolidBrush(RGB(255, 0, 0));
    HBRUSH oBrush   = (HBRUSH)SelectObject(hdc, brush);

    Rectangle(
        hdc
        , m_tInfo.rect.left
        , m_tInfo.rect.top
        , m_tInfo.rect.right
        , m_tInfo.rect.bottom
    );

    SelectObject(hdc, oBrush);
    DeleteObject(brush);*/

    if (nullptr == m_Kind)
        return;

    m_Kind->Render(hdc);
}

int CMonster::      Update          ()
{
    CObj::Update();

    return m_Kind->Update();

}

void CMonster::     IsCollisionLine ()
{
    float fy = m_tInfo.fY;

    if (CLineMgr::GetInstance()->CollisionLine(m_tInfo.fX, &fy))
    {
        if(!(m_tInfo.curState & OBJ_A_JUMP))
            m_tInfo.fY = fy - m_tInfo.fCY / 2;

        if (STATE_SAME(m_tInfo.curState, OBJ_A_JUMP))
        {
            if (m_tInfo.fY >= fy - m_tInfo.fCY / 2) // 점프 중에 라인에 도달하면 라인을 타고
            {
                m_tInfo.fY = fy - m_tInfo.fCY / 2;
                m_tInfo.fJumpAcc = 0.f;
                if (m_tInfo.curState & OBJ_A_ATTK)
                {
                    if (m_tInfo.curState & OBJ_A_MOVE)
                        m_tInfo.curState = OBJ_A_MOVE | OBJ_A_ATTK;
                    else
                        m_tInfo.curState = OBJ_A_STND | OBJ_A_ATTK;
                }
                else
                {
                    m_tInfo.curState = OBJ_A_STND;
                    //m_tInfo.curState = OBJ_A_STND;
                }
                //m_tInfo.curState = OBJ_A_STND;
            }
        }
    }
    else
    {
        m_tInfo.curState = OBJ_A_JUMP;
    }
}

float CMonster::    FollowLine      ()
{
    return CLineMgr::GetInstance()->FollowLine(&m_tInfo.fX, &m_tInfo.fY, &m_tInfo.fSpeed);
}

void CMonster::  InsertImage     (const TCHAR * key, vector<ObjImg*>* vImg)
{
    m_image.insert(pair<const TCHAR*, vector<ObjImg*>*>(key, vImg));
}