#include "stdafx.h"
#include "Monster.h"
#include "BabarianBase.h"
#include "BerserkMboss.h"

CMonster::CMonster()
{
    
}

CMonster::CMonster(INFO& info)
    : CObj(info)
{
    SetKind(m_tInfo.m_eKind);
}

CMonster::~CMonster()
{
    Release();
}

void CMonster::SetKind(CMonsterKind * kind)
{
    if (nullptr == m_Kind)
        m_Kind = kind;
}

void CMonster::SetKind(eKMOB ekmb)
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
        break;
    }
}

void CMonster::Init()
{
    
}

void CMonster::Release()
{
}

void CMonster::Render(HDC hdc)
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

int CMonster::Update()
{
    CObj::Update();
    if (isDead())
        return 1;
    /*m_tInfo.fSpeed = 2.f;

    if (isDead())
        return 1;
    
    FollowLine();
    IsCollisionLine();*/    

    return 0;
}

void CMonster::IsCollisionLine()
{
    float fy = m_tInfo.fY;

    if (CLineMgr::GetInstance()->CollisionLine(m_tInfo.fX, &fy))
    {
        if(!(m_tInfo.preState & OBJ_A_JUMP))
            m_tInfo.fY = fy - m_tInfo.fCY / 2;

        if (m_tInfo.fY >= fy - m_tInfo.fCY / 2) // 점프 중에 라인에 도달하면 라인을 타고
		{
			m_tInfo.fY = fy - m_tInfo.fCY / 2;
			m_tInfo.fJumpAcc = 0.f;
            if (m_tInfo.preState & OBJ_A_ATTK)
            {
                if (m_tInfo.preState & OBJ_A_MOVE)
                    m_tInfo.preState = OBJ_A_MOVE | OBJ_A_ATTK;
                else
                    m_tInfo.preState = OBJ_A_STND | OBJ_A_ATTK;
            }
            else
                m_tInfo.preState = OBJ_A_STND;
		}
    }
}

float CMonster::FollowLine()
{
    //return CLineMgr::GetInstance()->FollowLine(&m_tInfo.fX, &m_tInfo.fY, &m_tInfo.fSpeed);
    return 0.f;
}

//#include "stdafx.h"
//#include "Monster.h"
//
//CMonster::CMonster()
//{
//}
//
//CMonster::~CMonster()
//{
//    Release();
//}
//
//void CMonster::Init()
//{
//}
//
//void CMonster::Release()
//{
//}
//
//void CMonster::Render(HDC hdc)
//{
//    HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));
//    HBRUSH oBrush = (HBRUSH)SelectObject(hdc, brush);
//
//    Rectangle(hdc, m_tInfo.rect.left, m_tInfo.rect.top, m_tInfo.rect.right, m_tInfo.rect.bottom);
//
//    SelectObject(hdc, oBrush);
//    DeleteObject(brush);
//}
//
//int CMonster::Update()
//{
//    if (isDead())
//        return 1;
//    CObj::Update();
//    return 0;
//}
