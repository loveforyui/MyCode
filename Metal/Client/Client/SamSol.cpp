#include "stdafx.h"
#include "SamSol.h"
#include "Monster.h"
#include "Bullet.h"

CSamSol::CSamSol()
{
}

CSamSol::~CSamSol()
{
}

void CSamSol::Init()
{
    char buf[256] = "";
    sprintf_s(buf, "%s%s", IMG_PATH, "monster/sam/soldier/open/");
    IMG_LOAD(L"monster/sam/soldier/open/", buf);
    dynamic_cast<CMonster*>(m_pObj)->InsertImage(L"monster/sam/soldier/open/", IMG_GET_V(L"monster/sam/soldier/open/"));
    m_mImage    = &(m_pObj->GetImgv());

    sprintf_s(buf, "%s%s", IMG_PATH, "monster/sam/soldier/atk/");
    IMG_LOAD(L"monster/sam/soldier/atk/", buf);
    dynamic_cast<CMonster*>(m_pObj)->InsertImage(L"monster/sam/soldier/atk/", IMG_GET_V(L"monster/sam/soldier/atk/"));
    m_mImage    = &(m_pObj->GetImgv());

    sprintf_s(buf, "%s%s", IMG_PATH, "monster/sam/soldier/die/");
    IMG_LOAD(L"monster/sam/soldier/die/", buf);
    dynamic_cast<CMonster*>(m_pObj)->InsertImage(L"monster/sam/soldier/die/", IMG_GET_V(L"monster/sam/soldier/die/"));
    m_mImage    = &(m_pObj->GetImgv());

    sprintf_s(buf, "%s%s", IMG_PATH, "sfx/smoke/");
    IMG_LOAD(L"sfx/smoke/", buf);
    dynamic_cast<CMonster*>(m_pObj)->InsertImage(L"sfx/smoke/", IMG_GET_V(L"sfx/smoke/"));
    m_mImage    = &(m_pObj->GetImgv());

    sprintf_s(buf, "%s%s", IMG_PATH, "sfx/explosion/");
    IMG_LOAD(L"sfx/explosion/", buf);
    dynamic_cast<CMonster*>(m_pObj)->InsertImage(L"sfx/explosion/", IMG_GET_V(L"sfx/explosion/"));
    m_mImage    = &(m_pObj->GetImgv());

    sprintf_s(buf, "%s%s", IMG_PATH, "sfx/missle/");
    IMG_LOAD(L"sfx/missle/", buf);
    dynamic_cast<CMonster*>(m_pObj)->SetBulletImg(IMG_GET_V(L"sfx/missle/")); //InsertImage(L"sfx/missle/", IMG_GET_V(L"sfx/missle/"));

    iter_begin  = m_mImage->find(L"monster/sam/soldier/open/")->second->begin();
    iter_end    = m_mImage->find(L"monster/sam/soldier/open/")->second->end();

    smoke_begin  = m_mImage->find(L"sfx/smoke/")->second->begin();
    smoke_end    = m_mImage->find(L"sfx/smoke/")->second->end();

    m_pObj->SetCurState(OBJ_A_STND);
    m_pObj->SetSpeed(0.f);
    m_pObj->SetHp(5);
    m_pObj->SetDead(false);
    m_pObj->SetWH(FLOAT((*iter_begin)->image->GetWidth()), FLOAT((*iter_begin)->image->GetHeight()));
    m_pObj->SetAngle(0.f);
}

void CSamSol::Render(HDC hdc)
{
    if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_STND))
    {
        IMG_DRAW_I(hdc
                , m_mImage->find(L"monster/sam/soldier/open/")->second->front()->image
                , FLOAT(m_pObj->GetInfo().fX)
                , FLOAT(m_pObj->GetInfo().fY)
                , FLOAT((*iter_begin)->image->GetWidth())//m_pObj->GetInfo().rect.right
                , FLOAT((*iter_begin)->image->GetHeight())//m_pObj->GetInfo().rect.bottom
            );
    }
    if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_MOVE))
    {
        IMG_DRAW_I(hdc
                , (*iter_begin)->image  
                , FLOAT(m_pObj->GetInfo().fX)
                , FLOAT(m_pObj->GetInfo().fY)
                , FLOAT((*iter_begin)->image->GetWidth())//m_pObj->GetInfo().rect.right
                , FLOAT((*iter_begin)->image->GetHeight())//m_pObj->GetInfo().rect.bottom
            );

        ++iter_begin;
        if (iter_begin == iter_end)
        {
            iter_begin  = --m_mImage->find(L"monster/sam/soldier/open/")->second->end();
            m_pObj->SetCurState(OBJ_A_ATTK);
            iter_begin  = m_mImage->find(L"monster/sam/soldier/atk/")->second->begin();
            iter_end    = m_mImage->find(L"monster/sam/soldier/atk/")->second->end();

            m_dwOt = GetTickCount();
        }
    }
    if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_ATTK))
    {
        IMG_DRAW_I(hdc
                , (*iter_begin)->image  
                , FLOAT(m_pObj->GetInfo().fX)
                , FLOAT(m_pObj->GetInfo().fY)
                , FLOAT((*iter_begin)->image->GetWidth())//m_pObj->GetInfo().rect.right
                , FLOAT((*iter_begin)->image->GetHeight())//m_pObj->GetInfo().rect.bottom
            );

        if (iter_begin == m_mImage->find(L"monster/sam/soldier/atk/")->second->begin() + 7)
        {
            /*CObj* player = CObjManager::GetInst()->GetObjlst(OBJ_PLAYER).back();

            float dist = _Distance<float>(
                player
                ->GetInfo().fX
                , player->GetInfo().fY
                , m_pObj->GetInfo().fX
                , m_pObj->GetInfo().fY
                );

            oAngle = acosf(m_pObj->GetInfo().fX / player->GetInfo().fX);
            
            minAngle = (cAngle - 90.f);
            maxAngle = (cAngle + 90.f);
            cAngle = minAngle;*/
            
            CObjManager::GetInst()->AddObj(CreateBullet(dynamic_cast<CMonster*>(m_pObj)->GetBulletImg(), 270.f + rand()%180 - 90), OBJ_M_BULLET);
            isShoot = true;
            smoke_begin = m_mImage->find(L"sfx/smoke/")->second->begin();
        }

        ++iter_begin;
        if (iter_begin == iter_end)
        {
            m_dwCt = GetTickCount();
            
            if (m_dwOt + 5000 + rand() % 10000 < m_dwCt)
            {
                m_dwOt = m_dwCt;
                iter_begin = m_mImage->find(L"monster/sam/soldier/atk/")->second->begin();
            }
            else
            {
                iter_begin = --m_mImage->find(L"monster/sam/soldier/atk/")->second->end();
            }
        }
    }

    if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_DIE))
    {
        IMG_DRAW_I(hdc
                , (*smoke_begin)->image  
                , FLOAT(m_pObj->GetInfo().fX - 10)
                , FLOAT(m_pObj->GetInfo().fY - 20)
                , FLOAT((*smoke_begin)->image->GetWidth())//m_pObj->GetInfo().rect.right
                , FLOAT((*smoke_begin)->image->GetHeight())//m_pObj->GetInfo().rect.bottom
            );

        ++smoke_begin;
        if (smoke_begin == smoke_end)
        {
            smoke_begin = m_mImage->find(L"sfx/explosion/")->second->begin();
            end = 1;
        }
    }

    if (isShoot)
    {
        if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_ATTK))
        {
            IMG_DRAW_I(hdc
                , (*smoke_begin)->image
                , FLOAT(m_pObj->GetInfo().fX - 20)
                , FLOAT(m_pObj->GetInfo().fY - 5)
                , FLOAT((*smoke_begin)->image->GetWidth())//m_pObj->GetInfo().rect.right
                , FLOAT((*smoke_begin)->image->GetHeight())//m_pObj->GetInfo().rect.bottom
            );

            ++smoke_begin;
            if (smoke_begin == smoke_end)
            {
                smoke_begin = m_mImage->find(L"sfx/smoke/")->second->begin();
                isShoot = false;
            }
        }
    }
    //Rectangle(hdc, m_pObj->GetInfo().rect.left, m_pObj->GetInfo().rect.top, m_pObj->GetInfo().rect.right, m_pObj->GetInfo().rect.bottom);
}

void CSamSol::Release()
{
}

int CSamSol::Update()
{
    RECT rc = { m_pObj->GetInfo().fX, m_pObj->GetInfo().fY, m_pObj->GetInfo().fX + m_pObj->GetInfo().fCX, m_pObj->GetInfo().fY + m_pObj->GetInfo().fCY };
    m_pObj->SetRect(rc);
    if (m_pObj->isDead())
    {
        if (!STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_DIE))
        {
            m_pObj->SetCurState(OBJ_A_DIE);

            smoke_begin = m_mImage->find(L"sfx/explosion/")->second->begin();
            smoke_end = m_mImage->find(L"sfx/explosion/")->second->end();

            iter_begin = m_mImage->find(L"monster/sam/soldier/die/")->second->begin();
            iter_end = m_mImage->find(L"monster/sam/soldier/die/")->second->end();
        }
        return end;
    }
    else
    {
        /*if (minAngle <= cAngle && cAngle < oAngle)
        {
            cAngle += opp;
            if (oAngle <= cAngle)
                cAngle = maxAngle;
        }
        if (oAngle <= cAngle && cAngle < maxAngle)
        {
            cAngle -= opp;
            if (cAngle <= oAngle)
                cAngle = minAngle;
        }*/
    }
    return 0;
}

CObj* CSamSol::    CreateBullet       (vector<ObjImg*>* img, float fAngle)
{
    CObj* pObj = CAbstractFactory<CBullet>::CreateObj(img, m_pObj->GetInfo().fX, m_pObj->GetInfo().fY + 50, fAngle);
    dynamic_cast<CBullet*>(pObj)->SetBullPettern(CBullet::UDO);
    return pObj;
}