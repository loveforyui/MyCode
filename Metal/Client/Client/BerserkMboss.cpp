#include "stdafx.h"
#include "BerserkMboss.h"
#include "Obj.h"
#include "Monster.h"

CBerserkMboss::CBerserkMboss()
{
    Init();
}

CBerserkMboss::~CBerserkMboss()
{
}

void CBerserkMboss::Init()
{
    //m_dwOAtkDelay = GetTickCount();

    m_pObj->SetCurState(OBJ_A_STND);

    char buf[256] = "";
    // carmel
    sprintf_s(buf, "%s%s", IMG_PATH, "monster/carmel/walk/");
    IMG_LOAD(L"monster/carmel/walk/", buf);
    dynamic_cast<CMonster*>(m_pObj)->InsertImage(L"monster/carmel/walk/", IMG_GET_V(L"monster/carmel/walk/"));
    m_mImage    = &(m_pObj->GetImgv());

    sprintf_s(buf, "%s%s", IMG_PATH, "monster/carmel/idle/");
    IMG_LOAD(L"monster/carmel/idle/", buf);
    dynamic_cast<CMonster*>(m_pObj)->InsertImage(L"monster/carmel/idle/", IMG_GET_V(L"monster/carmel/idle/"));
    m_mImage    = &(m_pObj->GetImgv());

    sprintf_s(buf, "%s%s", IMG_PATH, "monster/carmel/sitdown/");
    IMG_LOAD(L"monster/carmel/sitdown/", buf);
    dynamic_cast<CMonster*>(m_pObj)->InsertImage(L"monster/carmel/sitdown/", IMG_GET_V(L"monster/carmel/sitdown/"));
    m_mImage    = &(m_pObj->GetImgv());

    // baba
    sprintf_s(buf, "%s%s", IMG_PATH, "monster/bmb/ent/");
    IMG_LOAD(L"monster/bmb/ent/", buf);
    dynamic_cast<CMonster*>(m_pObj)->InsertImage(L"monster/bmb/ent/", IMG_GET_V(L"monster/bmb/ent/"));
    m_mImage    = &(m_pObj->GetImgv());

    
    iter_begin  = m_mImage->find(L"monster/carmel/idle/")->second->begin();
    iter_end    = m_mImage->find(L"monster/carmel/idle/")->second->end();

    iter_b      = m_mImage->find(L"monster/bmb/ent/")->second->begin();
    iter_e      = m_mImage->find(L"monster/bmb/ent/")->second->end();
    //dynamic_cast<CMonster*>(m_pObj)->SetBulletImg(IMG_GET_V(L"monster/carmel"));
}

void CBerserkMboss::Render(HDC hdc)
{
    /*Rectangle(
            hdc
            , m_pObj->GetInfo().rect.left
            , m_pObj->GetInfo().rect.top
            , m_pObj->GetInfo().rect.right
            , m_pObj->GetInfo().rect.bottom
        );*/

    if (2 == m_fase)
    {
        if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_STND))
        {
            IMG_DRAW_I(hdc
                , (*iter_b)->image
                , m_pObj->GetInfo().rect.left
                , m_pObj->GetInfo().rect.top
                , (*iter_b)->image->GetWidth()//m_pObj->GetInfo().rect.right
                , (*iter_b)->image->GetHeight()//m_pObj->GetInfo().rect.bottom
            );

            ++iter_b;
            if (iter_b == iter_e)
            {
                iter_b = --(m_mImage->find(L"monster/bmb/ent/")->second->end());
                m_fase = 3;
            }
        }

        if (3 == m_fase)
        {
            m_pObj->SetCurState(OBJ_A_SITD);
            iter_begin = m_mImage->find(L"monster/carmel/sitdown/")->second->begin();
            iter_end = m_mImage->find(L"monster/carmel/sitdown/")->second->begin() + 2;
        }
    }
    else if (3 == m_fase)
    {

    }


    //carmel
    if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_MOVE))
    {
        IMG_DRAW_I(hdc
            , (*iter_begin)->image
            , m_pObj->GetInfo().fX - (*iter_begin)->image->GetWidth()/2.f
            , -10 + m_pObj->GetInfo().fY - (*iter_begin)->image->GetHeight()/2.f
            , (*iter_begin)->image->GetWidth()
            , (*iter_begin)->image->GetHeight()
        );

        ++iter_begin;
        if(iter_begin == iter_end)
            iter_begin = m_mImage->find(L"monster/carmel/walk/")->second->begin();
    }

    if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_STND))
    {
        IMG_DRAW_I(hdc
            , (*iter_begin)->image
            , m_pObj->GetInfo().fX - (*iter_begin)->image->GetWidth()/2.f
            , -10 + m_pObj->GetInfo().fY - (*iter_begin)->image->GetHeight()/2.f
            , (*iter_begin)->image->GetWidth()
            , (*iter_begin)->image->GetHeight()
        );

        ++iter_begin;
        if(iter_begin == iter_end)
            iter_begin = m_mImage->find(L"monster/carmel/idle/")->second->begin();
    }

    if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_SITD))
    {
        IMG_DRAW_I(hdc
            , (*iter_begin)->image
            , m_pObj->GetInfo().fX - (*iter_begin)->image->GetWidth()/2.f
            , -10 + m_pObj->GetInfo().fY - (*iter_begin)->image->GetHeight()/2.f
            , (*iter_begin)->image->GetWidth()
            , (*iter_begin)->image->GetHeight()
        );

        ++iter_begin;
       /* if(iter_begin == iter_end)
            iter_begin = m_mImage->find(L"monster/carmel/sitdown/")->second->begin() + 3;*/
    }
    

    /*wchar_t         pos[64];
    swprintf_s(pos, L"X:%.1f Y:%.1f d:%d", m_pObj->GetInfo().fX, m_pObj->GetInfo().fY, m_pObj->GetInfo().curState);
    SetTextAlign(hdc, TA_CENTER);
    SetBkMode(hdc, TRANSPARENT);
    TextOut(hdc, m_pObj->GetInfo().fX, m_pObj->GetInfo().fY - 30, pos, wcslen(pos));*/
}

void CBerserkMboss::Release()
{
}

int CBerserkMboss::Update()
{
    CObj* player = CObjManager::GetInst()->GetObjlst(OBJ_PLAYER).back();

    float dist = _Distance<float>(
        player->GetInfo().fX
        , player->GetInfo().fY
        , m_pObj->GetInfo().fX
        , m_pObj->GetInfo().fY
    );

    switch (m_fase)
    {
    case 1:
        PatternS();
        break;
    case 2:
        PatternA();
        break;
    case 3:
        PatternB();
        break;
    }
    CalcRect();
    IsCollisionLine();
    return 0;
}
void CBerserkMboss::CalcRect()
{
    if(m_pObj->GetInfo().fSpeed < 5.f)
        m_pObj->SetSpeed(m_pObj->GetInfo().fSpeed + m_pObj->GetInfo().fAcc);

    float cx = float((*iter_b)->image->GetWidth());
    float cy = float((*iter_b)->image->GetHeight());

    RECT rc = {
        LONG(m_pObj->GetInfo().fX) + 40 - cx
        , -20 + LONG(m_pObj->GetInfo().fY - cy)
        , LONG(m_pObj->GetInfo().fX + 40)
        , -20 + LONG(m_pObj->GetInfo().fY)
    };

    m_pObj->SetRect(rc);
}

void CBerserkMboss::PatternS()
{
    CObj* player = CObjManager::GetInst()->GetObjlst(OBJ_PLAYER).back();

    float dist = _Distance<float>(
        player->GetInfo().fX
        , player->GetInfo().fY
        , m_pObj->GetInfo().fX
        , m_pObj->GetInfo().fY
    );

    float x = m_pObj->GetInfo().fX;

    x -= m_pObj->GetInfo().fSpeed;

    if (1150.f < m_pObj->GetInfo().fX)
    {
        if (dist < 200.f)
        {
            CScrollMgr::GetInstance()->SetHold(true);
            m_fase = 2;
        }
    }
}

void CBerserkMboss::PatternA()
{
    float x = m_pObj->GetInfo().fX;

    x -= m_pObj->GetInfo().fSpeed;

    if (1150.f < m_pObj->GetInfo().fX)
    {
        if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_STND))
        {
            iter_begin  = m_mImage->find(L"monster/carmel/walk/")->second->begin();
            iter_end    = m_mImage->find(L"monster/carmel/walk/")->second->end();
        }
        m_pObj->SetCurState(OBJ_A_MOVE);
        m_pObj->SetPos(x, m_pObj->GetInfo().fY);
    }
    else
    {
        m_pObj->SetCurState(OBJ_A_STND);
        iter_begin  = m_mImage->find(L"monster/carmel/idle/")->second->begin();
        iter_end    = m_mImage->find(L"monster/carmel/idle/")->second->end();

        //iter_b      = m_mImage->find(L"monster/bmb/ent/")->second->begin();
        //iter_e      = m_mImage->find(L"monster/bmb/ent/")->second->end();
        
    }
}

void CBerserkMboss::PatternB()
{
    //m_pObj->SetCurState(OBJ_A_ATTK);
    if (iter_begin == iter_end)
    {
        iter_begin = m_mImage->find(L"monster/carmel/sitdown/")->second->begin() + 2;
        iter_end = m_mImage->find(L"monster/carmel/sitdown/")->second->end();
    }
}

void CBerserkMboss::     IsCollisionLine ()
{
    float fy = m_pObj->GetInfo().fY;

    if (CLineMgr::GetInstance()->CollisionLine(m_pObj->GetInfo().fX, &fy))
    {
        if(!(m_pObj->GetInfo().curState & OBJ_A_JUMP))
            m_pObj->SetPos(m_pObj->GetInfo().fX, fy - m_pObj->GetInfo().fCY / 2);

        if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_JUMP))
        {
            if (m_pObj->GetInfo().fY >= fy - m_pObj->GetInfo().fCY / 2) // 점프 중에 라인에 도달하면 라인을 타고
            {
                m_pObj->SetPos(m_pObj->GetInfo().fX, fy - m_pObj->GetInfo().fCY / 2);
                m_pObj->SetJAcc(0.f);
                if (m_pObj->GetInfo().curState & OBJ_A_ATTK)
                {
                    if (m_pObj->GetInfo().curState & OBJ_A_MOVE)
                        m_pObj->SetCurState(OBJ_A_MOVE | OBJ_A_ATTK);
                    else
                        m_pObj->SetCurState(OBJ_A_STND | OBJ_A_ATTK);
                }
                else
                {
                    m_pObj->SetCurState(OBJ_A_STND);
                    //m_tInfo.curState = OBJ_A_STND;
                }
                //m_tInfo.curState = OBJ_A_STND;
            }
        }
    }
    else
    {
        m_pObj->SetCurState(OBJ_A_JUMP);
    }
}