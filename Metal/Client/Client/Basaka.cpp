#include "stdafx.h"
#include "Basaka.h"
#include "Monster.h"

CBasaka::CBasaka()
{
}

CBasaka::~CBasaka()
{
}

void CBasaka::Init()
{
    char buf[256] = "";
    sprintf_s(buf, "%s%s", IMG_PATH, "monster/bsk/die/");
    IMG_LOAD(L"monster/bsk/die/", buf);
    dynamic_cast<CMonster*>(m_pObj)->InsertImage(L"monster/bsk/die/", IMG_GET_V(L"monster/bsk/die/"));
    m_mImage    = &(m_pObj->GetImgv());

    sprintf_s(buf, "%s%s", IMG_PATH, "monster/bsk/atk/");
    IMG_LOAD(L"monster/bsk/atk/", buf);
    dynamic_cast<CMonster*>(m_pObj)->InsertImage(L"monster/bsk/atk/", IMG_GET_V(L"monster/bsk/atk/"));
    m_mImage    = &(m_pObj->GetImgv());

    sprintf_s(buf, "%s%s", IMG_PATH, "monster/bsk/walk/");
    IMG_LOAD(L"monster/bsk/walk/", buf);
    dynamic_cast<CMonster*>(m_pObj)->InsertImage(L"monster/bsk/walk/", IMG_GET_V(L"monster/bsk/walk/"));
    m_mImage    = &(m_pObj->GetImgv());

    iter_begin  = m_mImage->find(L"monster/bsk/atk/")->second->begin();
    iter_end    = m_mImage->find(L"monster/bsk/atk/")->second->end();

    m_pObj->SetWH(FLOAT((*iter_begin)->image->GetWidth()), FLOAT((*iter_begin)->image->GetHeight()));
}

void CBasaka::Render(HDC hdc)
{
    if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_ATTK))
    {
        IMG_DRAW_I(hdc
                , (*iter_begin)->image
                , FLOAT(m_pObj->GetInfo().fX - (*iter_begin)->image->GetWidth() / 2.f)
                , -5 + FLOAT(m_pObj->GetInfo().fY - (*iter_begin)->image->GetHeight() / 2.f)
                , FLOAT((*iter_begin)->image->GetWidth())//m_pObj->GetInfo().rect.right
                , FLOAT((*iter_begin)->image->GetHeight())//m_pObj->GetInfo().rect.bottom
            );

        ++iter_begin;
        if (iter_begin == iter_end)
        {
            iter_begin  = m_mImage->find(L"monster/bsk/atk/")->second->begin();
        }
    }

    if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_DIE))
    {
        IMG_DRAW_I(hdc
                , (*iter_begin)->image
                , FLOAT(m_pObj->GetInfo().fX - (*iter_begin)->image->GetWidth() / 2.f)
                , -5 + FLOAT(m_pObj->GetInfo().fY - (*iter_begin)->image->GetHeight() / 2.f)
                , FLOAT((*iter_begin)->image->GetWidth())//m_pObj->GetInfo().rect.right
                , FLOAT((*iter_begin)->image->GetHeight())//m_pObj->GetInfo().rect.bottom
            );

        ++iter_begin;
        if (iter_begin == iter_end)
        {
            iter_begin  = m_mImage->find(L"monster/bsk/die/")->second->begin();
            end = 1;
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
            iter_begin = m_mImage->find(L"monster/bsk/walk/")->second->begin();
        }
    }
}

void CBasaka::Release()
{
}

int CBasaka::Update()
{
    if (1 == end)
        return 1;

    if (m_pObj->isDead())
    {
        if (!STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_DIE))
        {
            m_pObj->SetCurState(OBJ_A_DIE);
            iter_begin  = m_mImage->find(L"monster/bsk/die/")->second->begin();
            iter_end    = m_mImage->find(L"monster/bsk/die/")->second->end();
        }

        POINT pt = CPattern::GetInstance()->AngleLine(m_pObj, 0.f);
        m_pObj->SetPos(FLOAT(pt.x), FLOAT(pt.y));
        return 0;
    }

    CObj* player = CObjManager::GetInst()->GetObjlst(OBJ_PLAYER).back();

    float dist = _Distance<float>(
        player->GetInfo().fX
        , player->GetInfo().fY
        , m_pObj->GetInfo().fX
        , m_pObj->GetInfo().fY
    );

    if(dist <= 20.f)
    {
        if (!STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_ATTK))
        {
            m_pObj->SetCurState(OBJ_A_ATTK);
            iter_begin  = m_mImage->find(L"monster/bsk/atk/")->second->begin();
            iter_end    = m_mImage->find(L"monster/bsk/atk/")->second->end();
        }
    }
    else
    {
        if (!STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_MOVE))
        {
            m_pObj->SetCurState(OBJ_A_MOVE);
            iter_begin  = m_mImage->find(L"monster/bsk/walk/")->second->begin();
            iter_end    = m_mImage->find(L"monster/bsk/walk/")->second->end();
        }
    }

    if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_ATTK))
    {
        POINT pt = CPattern::GetInstance()->AngleLine(m_pObj, 180.f);
        m_pObj->SetPos(FLOAT(pt.x), FLOAT(pt.y));
    }

    if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_MOVE))
    {
        POINT pt = CPattern::GetInstance()->AngleLine(m_pObj, 180.f);
        m_pObj->SetPos(FLOAT(pt.x), FLOAT(pt.y));
    }
    
    return 0;
}
