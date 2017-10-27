#include "stdafx.h"
#include "Monster.h"

CMonster::CMonster()
{
    
}

CMonster::~CMonster()
{
    Release();
}

void CMonster::Init()
{
    
}

void CMonster::Release()
{
}

void CMonster::Render(HDC hdc)
{
    HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));
    HBRUSH oBrush = (HBRUSH)SelectObject(hdc, brush);

    Rectangle(hdc, m_tInfo.rect.left, m_tInfo.rect.top, m_tInfo.rect.right, m_tInfo.rect.bottom);

    SelectObject(hdc, oBrush);
    DeleteObject(brush);
}

int CMonster::Update()
{
    m_tInfo.fSpeed = 2.f;

    if (isDead())
        return 1;
    CObj::Update();
    FollowLine();
    IsCollisionLine();    

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
    return CLineMgr::GetInstance()->FollowLine(&m_tInfo.fX, &m_tInfo.fY, &m_tInfo.fSpeed);
}