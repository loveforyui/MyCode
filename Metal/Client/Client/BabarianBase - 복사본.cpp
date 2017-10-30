#include "stdafx.h"
#include "BabarianBase.h"
#include "Bullet.h"
#include "Monster.h"

CBabarian::CBabarian()
{
    Init();
}

CBabarian::~CBabarian()
{
}

void CBabarian::    Init            ()
{
    m_dwOAtkDelay = GetTickCount();

    m_pObj->SetHp(5);

    char buf[256] = "";
    //body
    sprintf_s(buf, "%s%s", IMG_PATH, "sfx/babarian/swrd/");
    IMG_LOAD(L"sfx/babarian/swrd/", buf);
    dynamic_cast<CMonster*>(m_pObj)->SetBulletImg(IMG_GET_V(L"sfx/babarian/swrd/"));

    sprintf_s(buf, "%s%s", IMG_PATH, "monster/arab/idle/");
    IMG_LOAD(L"monster/arab/idle/", buf);
    dynamic_cast<CMonster*>(m_pObj)->InsertImage(L"monster/arab/idle/", IMG_GET_V(L"monster/arab/idle/"));
    m_mImage    = &(m_pObj->GetImgv());

    sprintf_s(buf, "%s%s", IMG_PATH, "monster/arab/atk/");
    IMG_LOAD(L"monster/arab/atk/", buf);
    dynamic_cast<CMonster*>(m_pObj)->InsertImage(L"monster/arab/atk/", IMG_GET_V(L"monster/arab/atk/"));
    m_mImage    = &(m_pObj->GetImgv());

    sprintf_s(buf, "%s%s", IMG_PATH, "monster/arab/run/");
    IMG_LOAD(L"monster/arab/run/", buf);
    dynamic_cast<CMonster*>(m_pObj)->InsertImage(L"monster/arab/run/", IMG_GET_V(L"monster/arab/run/"));
    m_mImage    = &(m_pObj->GetImgv());

    sprintf_s(buf, "%s%s", IMG_PATH, "monster/arab/bjmp/");
    IMG_LOAD(L"monster/arab/bjmp/", buf);
    dynamic_cast<CMonster*>(m_pObj)->InsertImage(L"monster/arab/bjmp/", IMG_GET_V(L"monster/arab/bjmp/"));
    m_mImage    = &(m_pObj->GetImgv());


    iter_begin  = m_mImage->find(L"monster/arab/idle/")->second->begin();
    iter_end    = m_mImage->find(L"monster/arab/idle/")->second->end();
}

void CBabarian::    Render          (HDC hdc)
{
    if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_STND))
    {
        IMG_DRAW_I(hdc
                , (*iter_begin)->image
                , FLOAT(m_pObj->GetInfo().fX - (*iter_begin)->image->GetWidth() / 2.f)
                , FLOAT(m_pObj->GetInfo().fY - (*iter_begin)->image->GetHeight() / 2.f)
                , FLOAT((*iter_begin)->image->GetWidth())//m_pObj->GetInfo().rect.right
                , FLOAT((*iter_begin)->image->GetHeight())//m_pObj->GetInfo().rect.bottom
            );

        ++iter_begin;
        if (iter_begin == iter_end)
        {
            iter_begin = m_mImage->find(L"monster/arab/idle/")->second->begin();
        }
    }
    if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_MOVE))
    {
        IMG_DRAW_I(hdc
                , (*iter_begin)->image
                , FLOAT(m_pObj->GetInfo().fX - (*iter_begin)->image->GetWidth() / 2.f)
                , FLOAT(m_pObj->GetInfo().fY - (*iter_begin)->image->GetHeight() / 2.f)
                , FLOAT((*iter_begin)->image->GetWidth())//m_pObj->GetInfo().rect.right
                , FLOAT((*iter_begin)->image->GetHeight())//m_pObj->GetInfo().rect.bottom
            );

        ++iter_begin;
        if (iter_begin == iter_end)
        {
            iter_begin = m_mImage->find(L"monster/arab/run/")->second->begin();
        }
    }
    if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_JUMP))
    {
        IMG_DRAW_I(hdc
                , (*iter_begin)->image
                , FLOAT(m_pObj->GetInfo().fX - (*iter_begin)->image->GetWidth() / 2.f)
                , FLOAT(m_pObj->GetInfo().fY - (*iter_begin)->image->GetHeight() / 2.f)
                , FLOAT((*iter_begin)->image->GetWidth())//m_pObj->GetInfo().rect.right
                , FLOAT((*iter_begin)->image->GetHeight())//m_pObj->GetInfo().rect.bottom
            );

        ++iter_begin;
        if (iter_begin == iter_end)
        {
            iter_begin = m_mImage->find(L"monster/arab/bjmp/")->second->begin();
            m_pObj->SetCurState(OBJ_A_STND);

            iter_begin  = m_mImage->find(L"monster/arab/idle/")->second->begin();
            iter_end    = m_mImage->find(L"monster/arab/idle/")->second->end();
        }
    }

    if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_ATTK))
    {
        IMG_DRAW_I(hdc
                , (*iter_begin)->image
                , FLOAT(m_pObj->GetInfo().fX - (*iter_begin)->image->GetWidth() / 2.f)
                , FLOAT(m_pObj->GetInfo().fY - (*iter_begin)->image->GetHeight() / 2.f)
                , FLOAT((*iter_begin)->image->GetWidth())//m_pObj->GetInfo().rect.right
                , FLOAT((*iter_begin)->image->GetHeight())//m_pObj->GetInfo().rect.bottom
            );

        if (iter_begin == m_mImage->find(L"monster/arab/atk/")->second->begin() + 7)
        {
            CObjManager::GetInst()->AddObj(CreateBullet(dynamic_cast<CMonster*>(m_pObj)->GetBulletImg(), 90.f), OBJ_M_BULLET);
        }

        ++iter_begin;
        if (iter_begin == iter_end)
        {
            iter_begin = m_mImage->find(L"monster/arab/atk/")->second->begin();
            m_pObj->SetCurState(OBJ_A_STND);

            iter_begin  = m_mImage->find(L"monster/arab/idle/")->second->begin();
            iter_end    = m_mImage->find(L"monster/arab/idle/")->second->end();
        }
    }

    /*wchar_t         pos[64];
    swprintf_s(pos, L"X:%.1f Y:%.1f d:%d", m_pObj->GetInfo().fX, m_pObj->GetInfo().fY, m_pObj->GetInfo().curState);
    SetTextAlign(hdc, TA_CENTER);
    SetBkMode(hdc, TRANSPARENT);
    TextOut(hdc, m_pObj->GetInfo().fX, m_pObj->GetInfo().fY - 30, pos, wcslen(pos));*/
}

void CBabarian::    Release         ()
{
}

int CBabarian::     Update          ()
{
    if (m_pObj->isDead())
        return 1;

    RECT rc = {
        LONG(m_pObj->GetInfo().fX - m_pObj->GetInfo().fCX / 2)
        , LONG(m_pObj->GetInfo().fY - m_pObj->GetInfo().fCY / 2)
        , LONG(m_pObj->GetInfo().fX + m_pObj->GetInfo().fCX / 2)
        , LONG(m_pObj->GetInfo().fY + m_pObj->GetInfo().fCY / 2)
    };

    m_pObj->SetRect(rc);

    PatternA();
    IsJump();
    PrecessState();
    IsCollisionLine();

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
    if ((dist < 60.f))
    {
        if (!((m_pObj->GetInfo().curState & OBJ_A_JUMP) == OBJ_A_JUMP))
        {
            //이미 방향은 그대로 점프 뛴다.
            m_pObj->SetJAcc(GRAVITY * 1.8f);
            m_pObj->SetCurState(OBJ_A_JUMP);

            iter_begin  = m_mImage->find(L"monster/arab/bjmp/")->second->begin();
            iter_end    = m_mImage->find(L"monster/arab/bjmp/")->second->end();
        }
    }
    if ((m_pObj->GetInfo().curState & OBJ_A_STND) == OBJ_A_STND)
    {
        if (100.f <= dist && dist <= 200.f)
        {
            if (!STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_MOVE))
            {
                m_pObj->SetCurState(OBJ_A_MOVE);
                iter_begin = m_mImage->find(L"monster/arab/run/")->second->begin();
                iter_end = m_mImage->find(L"monster/arab/run/")->second->end();
            }
            

            POINT pt    = CPattern::GetInstance()->AngleLine(m_pObj, 180.f);
            m_pObj->SetPos(float(pt.x), float(pt.y));
        }
        if ((dist < 100.f))
        {
            if (!STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_ATTK))
            {
                m_dwOAtkDelay = GetTickCount();
                int cur = m_pObj->GetInfo().curState;
                cur = OBJ_A_ATTK;
                m_pObj->SetCurState(cur);

                iter_begin  = m_mImage->find(L"monster/arab/atk/")->second->begin();
                iter_end    = m_mImage->find(L"monster/arab/atk/")->second->end();
            }
        }
    }
    if ((m_pObj->GetInfo().curState & OBJ_A_ATTK) == OBJ_A_ATTK)
    {
        m_dwCAtkDelay = GetTickCount();
    }
}

void CBabarian::    IsJump          ()
{
    if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_JUMP))
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

void CBabarian::    PrecessState    ()
{
    if (m_dwOAtkDelay + 1140 < m_dwCAtkDelay)
    {
        // Attack Motion
        int cur = m_pObj->GetInfo().curState;
        if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_ATTK))
        {
            cur ^= OBJ_A_ATTK;
            iter_begin  = m_mImage->find(L"monster/arab/idle/")->second->begin();
            iter_end    = m_mImage->find(L"monster/arab/idle/")->second->end();
            m_pObj->SetCurState(cur);

            m_dwOAtkDelay = GetTickCount();
        }
    }
}

CObj* CBabarian::   CreateBullet    (vector<ObjImg*>* img, float fAngle)
{
    CObj* pObj = CAbstractFactory<CBullet>::CreateObj(img, m_pObj->GetInfo().fX, m_pObj->GetInfo().fY, fAngle);
    dynamic_cast<CBullet*>(pObj)->SetBullPettern(CBullet::CONIC);
    return pObj;
}
//
void CBabarian::    IsCollisionLine ()
{
    float fy = m_pObj->GetInfo().fY;

    if (CLineMgr::GetInstance()->CollisionLine(m_pObj->GetInfo().fX, &fy))
    {
        if(!(m_pObj->GetInfo().curState & OBJ_A_JUMP))
            m_pObj->SetPos(m_pObj->GetInfo().fX, fy - m_pObj->GetInfo().fCY / 2);

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

                iter_begin  = m_mImage->find(L"monster/arab/idle/")->second->begin();
                iter_end    = m_mImage->find(L"monster/arab/idle/")->second->end();
                //m_tInfo.curState = OBJ_A_STND;
            }
            //m_tInfo.curState = OBJ_A_STND;
        }
    }
    else
    {
        m_pObj->SetCurState(OBJ_A_JUMP);
        iter_begin  = m_mImage->find(L"monster/arab/bjmp/")->second->begin();
        iter_end    = m_mImage->find(L"monster/arab/bjmp/")->second->end();
    }
}