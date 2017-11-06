#include "stdafx.h"
#include "SamC.h"
#include "Monster.h"

CSamC::CSamC()
{
}

CSamC::~CSamC()
{
}

void CSamC::Init()
{
    char buf[256] = "";
    sprintf_s(buf, "%s%s", IMG_PATH, "monster/sam/center/idle/");
    IMG_LOAD(L"monster/sam/center/idle/", buf);
    dynamic_cast<CMonster*>(m_pObj)->InsertImage(L"monster/sam/center/idle/", IMG_GET_V(L"monster/sam/center/idle/"));
    m_mImage    = &(m_pObj->GetImgv());

    sprintf_s(buf, "%s%s", IMG_PATH, "monster/sam/center/open/");
    IMG_LOAD(L"monster/sam/center/open/", buf);
    dynamic_cast<CMonster*>(m_pObj)->InsertImage(L"monster/sam/center/open/", IMG_GET_V(L"monster/sam/center/open/"));
    m_mImage    = &(m_pObj->GetImgv());

    iter_begin  = m_mImage->find(L"monster/sam/center/idle/")->second->begin();
    iter_end    = m_mImage->find(L"monster/sam/center/idle/")->second->end();

    Move_begin  = m_mImage->find(L"monster/sam/center/open/")->second->begin();
    Move_end    = m_mImage->find(L"monster/sam/center/open/")->second->end() - 2;

    m_pObj->SetCurState(OBJ_A_STND);
    m_pObj->SetSpeed(1.f);
}

void CSamC::Render(HDC hdc)
{
    if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_STND))
    {
        IMG_DRAW_I(hdc
                , (*iter_begin)->image  
                , FLOAT(m_pObj->GetInfo().fX)
                , FLOAT(m_pObj->GetInfo().fY)
                , FLOAT((*iter_begin)->image->GetWidth())//m_pObj->GetInfo().rect.center
                , FLOAT((*iter_begin)->image->GetHeight())//m_pObj->GetInfo().rect.bottom
            );

        ++iter_begin;
        if (iter_begin == iter_end)
        {
            iter_begin = ++m_mImage->find(L"monster/sam/center/idle/")->second->begin();
        }
    }
    if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_MOVE))
    {
        IMG_DRAW_I(hdc
                , (*Move_begin)->image  
                , FLOAT(m_pObj->GetInfo().fX)
                , FLOAT(m_pObj->GetInfo().fY)
                , FLOAT((*iter_begin)->image->GetWidth())//m_pObj->GetInfo().rect.center
                , FLOAT((*iter_begin)->image->GetHeight())//m_pObj->GetInfo().rect.bottom
            );

        if (Move_begin == Move_end)
        {
            Move_begin = Move_end;
        }
        else
        {
            ++Move_begin;
        }
    }

    if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_DIE))
    {
        Image* img = m_mImage->find(L"monster/sam/center/open/")->second->back()->image;
        IMG_DRAW_I(hdc
                , img
                , FLOAT(m_pObj->GetInfo().fX)
                , FLOAT(m_pObj->GetInfo().fY)
                , FLOAT(img->GetWidth())//m_pObj->GetInfo().rect.center
                , FLOAT(img->GetHeight())//m_pObj->GetInfo().rect.bottom
            );
    }
}

void CSamC::Release()
{
}

int CSamC::Update()
{
    if (m_pObj->isDead())
    {
        if(!STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_DIE))
            CSoundMgr::GetInstance()->PlaySound(L"second_c.wav", CSoundMgr::CHANNEL_EFFECT);
        m_pObj->SetCurState(OBJ_A_DIE);
    }
    else
    {
        
    }
    return 0;
}
