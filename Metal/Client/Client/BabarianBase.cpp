#include "stdafx.h"
#include "BabarianBase.h"

CBabarian::CBabarian()
{
}

CBabarian::~CBabarian()
{
}

void CBabarian::    Init            ()
{
}

void CBabarian::    Render          (HDC hdc)
{
    //Image* img      = m_curImg->image;

    HBRUSH hBrush   = CreateSolidBrush(RGB(255, 0, 0));
    HBRUSH hOldsh   = (HBRUSH)SelectObject(hdc, hBrush);

    Rectangle(
        hdc
        , m_pObj->GetInfo().rect.left
        , m_pObj->GetInfo().rect.top
        , m_pObj->GetInfo().rect.right
        , m_pObj->GetInfo().rect.bottom
    );

    SelectObject(hdc, hOldsh);
    DeleteObject(hBrush);
}

void CBabarian::    Release         ()
{
}

int CBabarian::     Update          ()
{
    PatternA();
    IsJump();
    return 0;
}

void CBabarian::    PatternA        ()
{
    CObj* player = CObjManager::GetInst()->GetObjlst(OBJ_PLAYER).back();

    float dist = _Distance<float>(
        player->GetInfo().fX
        , player->GetInfo().fY
        , m_pObj->GetInfo().fX
        , m_pObj->GetInfo().fY
        );
    // 일정 거리가 되면 뒤로 점프해서 도망감
    if ((dist < 80.f))
    {
        if (!((m_pObj->GetInfo().curState & OBJ_A_JUMP) == OBJ_A_JUMP))
        {
            //이미 방향은 그대로 점프 뛴다.
            m_pObj->SetJAcc(GRAVITY * 2.5f);
            m_pObj->SetCurState(OBJ_A_JUMP);
        }
    }
    if((m_pObj->GetInfo().curState & OBJ_A_STND) == OBJ_A_STND)
    {
        POINT pt = CPattern::GetInstance()->AngleLine(m_pObj, 180.f);
        m_pObj->SetPos(float(pt.x), float(pt.y));
        //m_pObj->SetCurState(OBJ_A_STND);
        //m_pObj->SetJAcc(0.f);
    } 
}

void CBabarian::    IsJump          ()
{
    if (m_pObj->GetInfo().curState & OBJ_A_JUMP)
    {
        //m_tInfo.fJumpAcc += 0.3f;
        //m_tInfo.fY -= m_tInfo.fJumpPow * m_tInfo.fJumpAcc - GRAVITY * m_tInfo.fJumpAcc * m_tInfo.fJumpAcc * 0.5f;

        //FLOAT y = m_tInfo.fY;
        float acc = m_pObj->GetInfo().fJumpAcc;
        float fy = m_pObj->GetInfo().fY;
        acc -= 0.5*GRAVITY;
        fy -= m_pObj->GetInfo().fJumpAcc;

        m_pObj->SetJAcc(acc);
        m_pObj->SetPos(m_pObj->GetInfo().fX + 10.f, fy);
    }
}