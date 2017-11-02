#include "stdafx.h"
#include "Hell.h"
#include "Monster.h"

CHell::CHell()
{
}

CHell::~CHell()
{
}

void CHell::Init()
{
    char buf[256] = "";
    sprintf_s(buf, "%s%s", IMG_PATH, "monster/helli/");
    IMG_LOAD(L"monster/helli/", buf);
    dynamic_cast<CMonster*>(m_pObj)->InsertImage(L"monster/helli/", IMG_GET_V(L"monster/helli/"));
    m_mImage    = &(m_pObj->GetImgv());

    iter_begin  = m_mImage->find(L"monster/helli/")->second->end() - 6;
    iter_end    = m_mImage->find(L"monster/helli/")->second->end();

    m_pObj->SetCurState(OBJ_A_STND);
    m_pObj->SetDirect(OBJ_D_LEFT);
    m_pObj->SetHp(5);
}

void CHell::Render(HDC hdc)
{
    if (m_pObj->GetDirection() == OBJ_D_RIGH)
    {
        if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_MOVE))
        {
            (*iter_begin)->image->RotateFlip(Rotate180FlipY);
            IMG_DRAW_I(hdc
                , (*iter_begin)->image
                , FLOAT(m_pObj->GetInfo().fX - (*iter_begin)->image->GetWidth() / 2.f)
                , FLOAT(m_pObj->GetInfo().fY - (*iter_begin)->image->GetHeight() / 2.f)
                , FLOAT((*iter_begin)->image->GetWidth())//m_pObj->GetInfo().rect.right
                , FLOAT((*iter_begin)->image->GetHeight())//m_pObj->GetInfo().rect.bottom
            );
        }
    }
    else
    {
        if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_MOVE))
        {
            IMG_DRAW_I(hdc
                , (*iter_begin)->image
                , FLOAT(m_pObj->GetInfo().fX - (*iter_begin)->image->GetWidth() / 2.f)
                , FLOAT(m_pObj->GetInfo().fY - (*iter_begin)->image->GetHeight() / 2.f)
                , FLOAT((*iter_begin)->image->GetWidth())//m_pObj->GetInfo().rect.right
                , FLOAT((*iter_begin)->image->GetHeight())//m_pObj->GetInfo().rect.bottom
            );
        }
        if (m_pObj->isDead())
        {
            // 죽은 이펙트 출력
        }
    }
}

void CHell::Release()
{
}

int CHell::Update()
{
    if (1 == end)
        return 1;

    if (m_pObj->isDead())
    {
        // 아래로 떨어짐
        iter_begin = m_mImage->find(L"monster/helli/")->second->end() - 2;
        IsJump();
        IsCollisionLine();
    }

    m_pObj->SetSpeed(7.f);

    CObj* player = CObjManager::GetInst()->GetObjlst(OBJ_PLAYER).back();

    float dist = _Distance<float>(
        player->GetInfo().fX
        , player->GetInfo().fY
        , m_pObj->GetInfo().fX
        , m_pObj->GetInfo().fY
        );

    if (3400.f <= player->GetInfo().fX)
    {
        CScrollMgr::GetInstance()->SetHold(true);
    }

    switch (fase)
    {
    case CHell::WAIT:
    {
        if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_STND))
        {
            if (3400.f <= player->GetInfo().fX)
            {
                iter_begin = m_mImage->find(L"monster/helli/")->second->begin();
                m_pObj->SetCurState(OBJ_A_MOVE);
                fase = PATROLL;
            }
        }
    }
        break;
    case CHell::PATROLL:
    {
        if (m_pObj->GetDirection() == OBJ_D_LEFT)
        {
            patAngle = 180.f;
            POINT pt = CPattern::GetInstance()->AngleLine(m_pObj, patAngle);
            m_pObj->SetPos(float(pt.x), float(pt.y));
        }
        if (m_pObj->GetDirection() == OBJ_D_RIGH)
        {
            patAngle = 0.f;
            POINT pt = CPattern::GetInstance()->AngleLine(m_pObj, patAngle);
            m_pObj->SetPos(float(pt.x), float(pt.y));
        }
        if (m_pObj->GetDirection() == OBJ_D_TOPP)
        {
            patAngle -= 30.f;
            if (patAngle <= 0)
            {
                m_pObj->SetDirect(OBJ_D_RIGH);
            }
            POINT pt = CPattern::GetInstance()->AngleLine(m_pObj, patAngle);
            m_pObj->SetPos(float(pt.x), float(pt.y));
        }
        if (m_pObj->GetDirection() == OBJ_D_BOTT)
        {
            patAngle -= 30.f;
            if (patAngle <= -180.f)
            {
                m_pObj->SetDirect(OBJ_D_LEFT);
            }
            POINT pt = CPattern::GetInstance()->AngleLine(m_pObj, 360.f + patAngle);
            m_pObj->SetPos(float(pt.x), float(pt.y));
        }

        ++iter_begin;
        if (iter_begin == iter_end)
        {
            if (m_pObj->GetDirection() == OBJ_D_LEFT)
            {
                m_pObj->SetDirect(OBJ_D_TOPP);
            }

            if (m_pObj->GetDirection() == OBJ_D_RIGH)
            {
                m_pObj->SetDirect(OBJ_D_BOTT);
            }

            iter_begin = m_mImage->find(L"monster/helli/")->second->begin();
        }
    }
        break;
    }

    
    return 0;
}

void CHell::  IsJump          ()
{
    //m_tInfo.fJumpAcc += 0.3f;
    //m_tInfo.fY -= m_tInfo.fJumpPow * m_tInfo.fJumpAcc - GRAVITY * m_tInfo.fJumpAcc * m_tInfo.fJumpAcc * 0.5f;

    //FLOAT y = m_tInfo.fY;
    float jacc = m_pObj->GetInfo().fJumpAcc;
    jacc -= 0.1592f*GRAVITY;
    m_pObj->SetJumpacc(jacc);

    float y = m_pObj->GetInfo().fY;
    float x = m_pObj->GetInfo().fX;

    y -= m_pObj->GetInfo().fJumpAcc;
    m_pObj->SetPos(x, y);
}

void CHell::IsCollisionLine()
{
    float fy = m_pObj->GetInfo().fY;

    if (CLineMgr::GetInstance()->CollisionLine(m_pObj->GetInfo().fX, &fy))
    {
        if (!(m_pObj->GetInfo().curState & OBJ_A_JUMP))
            m_pObj->SetPos(m_pObj->GetInfo().fX, fy - m_pObj->GetInfo().fCY / 2);

        if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_JUMP))
        {
            if (m_pObj->GetInfo().fY >= fy - m_pObj->GetInfo().fCY / 2) // 점프 중에 라인에 도달하면 라인을 타고
            {
                m_pObj->SetPos(m_pObj->GetInfo().fX, fy - m_pObj->GetInfo().fCY / 2);
                m_pObj->SetJAcc(0.f);
            }
        }
    }
}