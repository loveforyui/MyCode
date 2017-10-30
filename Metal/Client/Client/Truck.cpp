#include "stdafx.h"
#include "Truck.h"
#include "Monster.h"

CTruck::CTruck()
{
}

CTruck::~CTruck()
{
}

void CTruck::Init()
{
    char buf[256] = "";
    //body
    //sprintf_s(buf, "%s%s", IMG_PATH, "monster/arab/idle/");
    //IMG_LOAD(L"monster/arab/idle/", buf);
    //dynamic_cast<CMonster*>(m_pObj)->SetBulletImg(IMG_GET_V(L"monster/arab/idle/"));

    sprintf_s(buf, "%s%s", IMG_PATH, "monster/truck/idle/");
    IMG_LOAD(L"monster/truck/idle/", buf);
    dynamic_cast<CMonster*>(m_pObj)->InsertImage(L"monster/truck/idle/", IMG_GET_V(L"monster/truck/idle/"));
    m_mImage    = &(m_pObj->GetImgv());

    sprintf_s(buf, "%s%s", IMG_PATH, "monster/truck/open/");
    IMG_LOAD(L"monster/truck/open/", buf);
    dynamic_cast<CMonster*>(m_pObj)->InsertImage(L"monster/truck/open/", IMG_GET_V(L"monster/truck/open/"));
    m_mImage    = &(m_pObj->GetImgv());

    sprintf_s(buf, "%s%s", IMG_PATH, "monster/truck/dest/");
    IMG_LOAD(L"monster/truck/dest/", buf);
    dynamic_cast<CMonster*>(m_pObj)->InsertImage(L"monster/truck/dest/", IMG_GET_V(L"monster/truck/dest/"));
    m_mImage    = &(m_pObj->GetImgv());

    iter_begin  = m_mImage->find(L"monster/truck/idle/")->second->begin();
    iter_end    = m_mImage->find(L"monster/truck/idle/")->second->end();

    m_pObj->SetCurState(OBJ_A_STND);
    m_pObj->SetHp(100);
    m_pObj->SetPos(1550.f, 160.f);
    m_pObj->SetWH(FLOAT((*iter_begin)->image->GetWidth()), FLOAT((*iter_begin)->image->GetHeight()));
}

void CTruck::Render(HDC hdc)
{
    if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_STND))
    {
        IMG_DRAW_I(hdc
                , (*iter_begin)->image
                , FLOAT(m_pObj->GetInfo().fX - (*iter_begin)->image->GetWidth() / 2.f)
                , -10 + FLOAT(m_pObj->GetInfo().fY - (*iter_begin)->image->GetHeight() / 2.f)
                , FLOAT((*iter_begin)->image->GetWidth())//m_pObj->GetInfo().rect.right
                , FLOAT((*iter_begin)->image->GetHeight())//m_pObj->GetInfo().rect.bottom
            );
    }

    if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_JUMP))
    {
        IMG_DRAW_I(hdc
                , (*iter_begin)->image
                , FLOAT(m_pObj->GetInfo().fX - (*iter_begin)->image->GetWidth() / 2.f)
                , -10 + FLOAT(m_pObj->GetInfo().fY - (*iter_begin)->image->GetHeight() / 2.f)
                , FLOAT((*iter_begin)->image->GetWidth())//m_pObj->GetInfo().rect.right
                , FLOAT((*iter_begin)->image->GetHeight())//m_pObj->GetInfo().rect.bottom
            );

        ++iter_begin;
        if (iter_begin == iter_end)
        {
            iter_begin = --m_mImage->find(L"monster/truck/open/")->second->end();
        }
    }
    if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_DIE))
    {
        IMG_DRAW_I(hdc
                , (*iter_begin)->image
                , FLOAT(m_pObj->GetInfo().fX - (*iter_begin)->image->GetWidth() / 2.f)
                , -10 + FLOAT(m_pObj->GetInfo().fY - (*iter_begin)->image->GetHeight() / 2.f)
                , FLOAT((*iter_begin)->image->GetWidth())//m_pObj->GetInfo().rect.right
                , FLOAT((*iter_begin)->image->GetHeight())//m_pObj->GetInfo().rect.bottom
            );

        ++iter_begin;
        if (iter_begin == iter_end)
        {
            iter_begin = m_mImage->find(L"monster/truck/dest/")->second->begin();
        }
    }
}

void CTruck::Release()
{
}

void CTruck::IsCollisionLine()
{
    float fy = m_pObj->GetInfo().fY;

    if (CLineMgr::GetInstance()->CollisionLine(m_pObj->GetInfo().fX, &fy))
    {
        if((m_pObj->GetInfo().curState & OBJ_A_JUMP))
            m_pObj->SetPos(m_pObj->GetInfo().fX, fy - m_pObj->GetInfo().fCY / 2);

        //if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_JUMP))
        //{
        //    if (m_pObj->GetInfo().fY >= fy - m_pObj->GetInfo().fCY / 2) // 점프 중에 라인에 도달하면 라인을 타고
        //    {
        //        m_pObj->SetPos(m_pObj->GetInfo().fX, fy - m_pObj->GetInfo().fCY / 2);
        //        m_pObj->SetJAcc(0.f);
        //        if (!STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_STND))
        //        {
        //            if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_IDLE))
        //            {
        //                m_pObj->SetCurState(OBJ_A_IDLE);
        //                iter_begin  = m_mImage->find(L"monster/truck/idle/")->second->begin();
        //                iter_end    = m_mImage->find(L"monster/truck/idle/")->second->end();
        //            }
        //            else
        //            {
        //                m_pObj->SetCurState(OBJ_A_STND);
        //                iter_begin  = m_mImage->find(L"monster/truck/open/")->second->begin();
        //                iter_end    = m_mImage->find(L"monster/truck/oepn/")->second->end();
        //            }
        //        }
        //    }
        //}
    }
    else
    {
        //m_pObj->SetCurState(OBJ_A_JUMP);
        //iter_begin  = m_mImage->find(L"monster/arab/bjmp/")->second->begin();
        //iter_end    = m_mImage->find(L"monster/arab/bjmp/")->second->end();
    }
}

int CTruck::Update()
{
    if (m_pObj->isDead())
    {
        if (!STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_DIE))
        {
            m_pObj->SetCurState(OBJ_A_DIE);
            iter_begin  = m_mImage->find(L"monster/truck/dest/")->second->begin();
            iter_end    = m_mImage->find(L"monster/truck/dest/")->second->end();
        }
        return 0;
    }

    PatternA();

    return 0;
}

void CTruck::PatternA()
{
    CObj* player = CObjManager::GetInst()->GetObjlst(OBJ_PLAYER).back();

    float dist = _Distance<float>(
        player->GetInfo().fX
        , player->GetInfo().fY
        , m_pObj->GetInfo().fX
        , m_pObj->GetInfo().fY
    );

    if (dist <= 100.f)
    {
        CScrollMgr::GetInstance()->SetHold(true);
        if (!STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_JUMP))
        {
            m_pObj->SetCurState(OBJ_A_JUMP);
            iter_begin  = m_mImage->find(L"monster/truck/open/")->second->begin();
            iter_end    = m_mImage->find(L"monster/truck/open/")->second->end();
        }
    }
}