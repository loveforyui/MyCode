#include "stdafx.h"
#include "SamBody.h"
#include "Monster.h"
#include "SamL.h"
#include "SamR.h"
#include "SamC.h"

CSamBody::CSamBody()
{
}

CSamBody::~CSamBody()
{
}

void CSamBody::Init()
{
    m_left      = nullptr;
    m_right     = nullptr;
    m_center    = nullptr;

    char buf[256] = "";
    sprintf_s(buf, "%s%s", IMG_PATH, "monster/sam/body/");
    IMG_LOAD(L"monster/sam/body/", buf);
    dynamic_cast<CMonster*>(m_pObj)->InsertImage(L"monster/sam/body/", IMG_GET_V(L"monster/sam/body/"));
    m_mImage    = &(m_pObj->GetImgv());

    iter_begin  = m_mImage->find(L"monster/sam/body/")->second->begin();
    iter_end    = m_mImage->find(L"monster/sam/body/")->second->end();

    m_pObj->SetCurState(OBJ_A_STND);
    m_pObj->SetDead(true);
    m_pObj->SetPos(1870.f, 90.f);
    m_pObj->SetWH((*iter_begin)->image->GetWidth(), (*iter_begin)->image->GetHeight());
}

void CSamBody::Render(HDC hdc)
{
    if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_STND)
        || STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_MOVE))
    {
        IMG_DRAW_I(hdc
                , (*iter_begin)->image  
                , -20 + FLOAT(m_pObj->GetInfo().fX)
                , -40 + FLOAT(m_pObj->GetInfo().fY)
                , FLOAT((*iter_begin)->image->GetWidth())//m_pObj->GetInfo().rect.right
                , FLOAT((*iter_begin)->image->GetHeight())//m_pObj->GetInfo().rect.bottom
            );
    }

    if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_DIE))
    {
        IMG_DRAW_I(hdc
                , (*iter_begin)->image
                , -20 + FLOAT(m_pObj->GetInfo().fX)
                , -40 + FLOAT(m_pObj->GetInfo().fY)
                , FLOAT((*iter_begin)->image->GetWidth())//m_pObj->GetInfo().rect.right
                , FLOAT((*iter_begin)->image->GetHeight())//m_pObj->GetInfo().rect.bottom
            );
    }
}

void CSamBody::Release()
{
}

int CSamBody::Update()
{
    if (m_pObj->isDead())
    {
        if (!STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_DIE))
        {
            m_pObj->SetCurState(OBJ_A_DIE);
            iter_begin = --m_mImage->find(L"monster/sam/body/")->second->end();

            INFO info;
            info.fX         = m_pObj->GetInfo().fX + 70.f;
            info.fY         = m_pObj->GetInfo().fY - 40.f;
            info.curState   = OBJ_A_STND;
            info.m_eKind    = eKMOB::MOB_K_S_BDOOR;
            info.fSpeed     = 10.f;
            info.fAngle     = 110.f;
            // tower
            m_vEffect.push_back(CAbstractFactory<CMonster>::CreateObj(info));
            CObjManager::GetInst()->AddObj(m_vEffect.back(), OBJ_MONSTER);

            info.fX         = m_pObj->GetInfo().fX + 120.f;
            info.fY         = m_pObj->GetInfo().fY - 40.f;
            info.fAngle     = 45.f;
            m_vEffect.push_back(CAbstractFactory<CMonster>::CreateObj(info));
            CObjManager::GetInst()->AddObj(m_vEffect.back(), OBJ_MONSTER);

            CScrollMgr::GetInstance()->SetHold(false);
            CObj* player = CObjManager::GetInst()->GetObjlst(OBJ_PLAYER).back();
            float d = player->GetInfo().fX + (CScrollMgr::GetInstance()->GetScrollX() - CScrollMgr::GetInstance()->GetOffset());
            CScrollMgr::GetInstance()->SetScrollX(CScrollMgr::GetInstance()->GetScrollX() - d);

            INFO infoh;
            infoh.fX         = 3600.f;
            infoh.fY         = 60.f;
            infoh.curState   = OBJ_A_IDLE;
            infoh.m_eKind    = eKMOB::MOB_K_HELL;
            infoh.fSpeed     = 20.f;

            // tower
            CObj* helli = CAbstractFactory<CMonster>::CreateObj(infoh);
            CObjManager::GetInst()->AddObj(helli, OBJ_MONSTER);
        }
    }
    else
    {
        CObj* player = CObjManager::GetInst()->GetObjlst(OBJ_PLAYER).back();

        float dist = _Distance<float>(
            player->GetInfo().fX
            , player->GetInfo().fY
            , m_pObj->GetInfo().fX
            , m_pObj->GetInfo().fY
            );

        if (nullptr == m_left)
        {
            INFO info;
            info.fX         = m_pObj->GetInfo().fX + 70.f;
            info.fY         = m_pObj->GetInfo().fY - 115.f;
            info.curState   = OBJ_A_STND;
            info.m_eKind    = eKMOB::MOB_K_S_LEFT;
            info.fSpeed     = 0.f;

            // tower
            m_left = CAbstractFactory<CMonster>::CreateObj(info);
            CObjManager::GetInst()->AddObj(m_left, OBJ_SUBMON);

            info.fX         = m_pObj->GetInfo().fX + 160.f;
            info.fY         = m_pObj->GetInfo().fY - 115.f;
            info.m_eKind    = eKMOB::MOB_K_S_CENT;
            m_center = CAbstractFactory<CMonster>::CreateObj(info);
            CObjManager::GetInst()->AddObj(m_center, OBJ_SUBMON);

            info.fX         = m_pObj->GetInfo().fX + 255.f;
            info.fY         = m_pObj->GetInfo().fY - 115.f;
            info.m_eKind    = eKMOB::MOB_K_S_RIGHT;
            m_right = CAbstractFactory<CMonster>::CreateObj(info);
            CObjManager::GetInst()->AddObj(m_right, OBJ_SUBMON);

            // Soldier
            info.fX = m_pObj->GetInfo().fX + 99.f;
            info.fY = m_pObj->GetInfo().fY - 92.f;
            info.m_eKind = eKMOB::MOB_K_S_SOLD;
            m_vSol.push_back(CAbstractFactory<CMonster>::CreateObj(info));
            CObjManager::GetInst()->AddObj(m_vSol.back(), OBJ_MONSTER);

            info.fX = m_pObj->GetInfo().fX + 189.f;
            info.fY = m_pObj->GetInfo().fY - 92.f;
            info.m_eKind = eKMOB::MOB_K_S_SOLD;
            m_vSol.push_back(CAbstractFactory<CMonster>::CreateObj(info));
            CObjManager::GetInst()->AddObj(m_vSol.back(), OBJ_MONSTER);

            info.fX = m_pObj->GetInfo().fX + 284.f;
            info.fY = m_pObj->GetInfo().fY - 92.f;
            info.m_eKind = eKMOB::MOB_K_S_SOLD;
            m_vSol.push_back(CAbstractFactory<CMonster>::CreateObj(info));
            CObjManager::GetInst()->AddObj(m_vSol.back(), OBJ_MONSTER);

            // door
            info.m_eKind = eKMOB::MOB_K_S_DOOR;
            info.fX = m_pObj->GetInfo().fX + 74.f;
            info.fY = m_pObj->GetInfo().fY - 105.f;
            m_vDoor.push_back(CAbstractFactory<CMonster>::CreateObj(info));
            CObjManager::GetInst()->AddObj(m_vDoor.back(), OBJ_MONSTER);

            info.m_eKind = eKMOB::MOB_K_S_DOOR;
            info.fX = m_pObj->GetInfo().fX + 164.f;
            info.fY = m_pObj->GetInfo().fY - 105.f;
            m_vDoor.push_back(CAbstractFactory<CMonster>::CreateObj(info));
            CObjManager::GetInst()->AddObj(m_vDoor.back(), OBJ_MONSTER);

            info.m_eKind = eKMOB::MOB_K_S_DOOR;
            info.fX = m_pObj->GetInfo().fX + 254.f;
            info.fY = m_pObj->GetInfo().fY - 105.f;
            m_vDoor.push_back(CAbstractFactory<CMonster>::CreateObj(info));
            CObjManager::GetInst()->AddObj(m_vDoor.back(), OBJ_MONSTER);
        }

        if ((m_pObj->GetInfo().fX + 190.f) <= player->GetInfo().fX)
        {
            CScrollMgr::GetInstance()->SetHold(true);
            m_pObj->SetCurState(OBJ_A_MOVE);
            //m_left->SetCurState(OBJ_A_MOVE);

            //door open
            for (vector<CObj*>::iterator iter = m_vDoor.begin()
                ; iter != m_vDoor.end(); ++iter)
            {
                (*iter)->SetCurState(OBJ_A_MOVE);
            }
        }
        // process die
        // follen soldier
        if (m_vSol.at(0)->isDead())
        {
            m_vDoor.at(0)->SetDead(true);
            m_left->SetDead(true);

        }
        if (m_vSol.at(1)->isDead())
        {
            m_vDoor.at(1)->SetDead(true);
            m_center->SetDead(true);

        }
        if (m_vSol.at(2)->isDead())
        {
            m_vDoor.at(2)->SetDead(true);
            m_right->SetDead(true);

        }
        if (m_vSol.at(0)->isDead() && m_vSol.at(1)->isDead() && m_vSol.at(2)->isDead())
        {
            // 모두 죽었을때 처리
            m_pObj->SetDead(true);
        }


        //left enter soldier
        if (m_vDoor.size() == 3)
        {
            if (!m_vDoor.at(0)->isDead())
            {
                if (dynamic_cast<CMonster*>(m_vDoor.at(0))->GetKind()->GetBegin() == --dynamic_cast<CMonster*>(m_vDoor.at(0))->GetKind()->GetImgVector()->find(L"monster/sam/door/")->second->end())
                {
                    m_left->SetCurState(OBJ_A_MOVE);

                }

                if (STATE_SAME(m_left->GetInfo().curState, OBJ_A_MOVE))
                {
                    //left solider move
                    if (dynamic_cast<CSamL*>(dynamic_cast<CMonster*>(m_left)->GetKind())->GetMoveBegin() == dynamic_cast<CMonster*>(m_left)->GetKind()->GetImgVector()->find(L"monster/sam/left/open/")->second->begin() + 7)
                    {
                        m_vSol.at(0)->SetCurState(OBJ_A_MOVE);
                    }
                }
            }

            if (!m_vDoor.at(1)->isDead())
            {
                // center
                if (dynamic_cast<CMonster*>(m_vDoor.at(1))->GetKind()->GetBegin() == --dynamic_cast<CMonster*>(m_vDoor.at(1))->GetKind()->GetImgVector()->find(L"monster/sam/door/")->second->end())
                {
                    m_center->SetCurState(OBJ_A_MOVE);

                }

                if (STATE_SAME(m_center->GetInfo().curState, OBJ_A_MOVE))
                {
                    //left solider move
                    if (dynamic_cast<CSamC*>(dynamic_cast<CMonster*>(m_center)->GetKind())->GetMoveBegin() == dynamic_cast<CMonster*>(m_center)->GetKind()->GetImgVector()->find(L"monster/sam/center/open/")->second->begin() + 7)
                    {
                        m_vSol.at(1)->SetCurState(OBJ_A_MOVE);
                    }
                }
            }

            if (!m_vDoor.at(2)->isDead())
            {
                // right
                if (dynamic_cast<CMonster*>(m_vDoor.at(2))->GetKind()->GetBegin() == --dynamic_cast<CMonster*>(m_vDoor.at(2))->GetKind()->GetImgVector()->find(L"monster/sam/door/")->second->end())
                {
                    m_right->SetCurState(OBJ_A_MOVE);

                }

                if (STATE_SAME(m_right->GetInfo().curState, OBJ_A_MOVE))
                {
                    //left solider move
                    if (dynamic_cast<CSamR*>(dynamic_cast<CMonster*>(m_right)->GetKind())->GetMoveBegin() == dynamic_cast<CMonster*>(m_right)->GetKind()->GetImgVector()->find(L"monster/sam/right/open/")->second->begin() + 7)
                    {
                        m_vSol.at(2)->SetCurState(OBJ_A_MOVE);
                    }
                }
            }
        }
    }
    return 0;
}
