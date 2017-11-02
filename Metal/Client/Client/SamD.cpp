#include "stdafx.h"
#include "SamD.h"
#include "Monster.h"

CSamD::CSamD()
{
}

CSamD::~CSamD()
{
}

void CSamD::Init()
{
    char buf[256] = "";
    sprintf_s(buf, "%s%s", IMG_PATH, "monster/sam/door/");
    IMG_LOAD(L"monster/sam/door/", buf);
    dynamic_cast<CMonster*>(m_pObj)->InsertImage(L"monster/sam/door/", IMG_GET_V(L"monster/sam/door/"));
    m_mImage    = &(m_pObj->GetImgv());

    iter_begin  = m_mImage->find(L"monster/sam/door/")->second->begin();
    iter_end    = m_mImage->find(L"monster/sam/door/")->second->end();

    m_pObj->SetCurState(OBJ_A_STND);
    m_pObj->SetSpeed(0.f);
}

void CSamD::Render(HDC hdc)
{
    if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_STND))
    {
        IMG_DRAW_I(hdc
                , m_mImage->find(L"monster/sam/door/")->second->front()->image  
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
            iter_begin = --m_mImage->find(L"monster/sam/door/")->second->end();
        }
    }
}

void CSamD::Release()
{
}

int CSamD::Update()
{
    if (m_pObj->isDead())
        return 1;

    return 0;
}
