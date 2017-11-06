#include "stdafx.h"
#include "BossL.h"
#include "Monster.h"

CBossL::CBossL()
{
}

CBossL::~CBossL()
{
}

void CBossL::Init()
{
    char buf[256] = "";

    sprintf_s(buf, "%s%s", IMG_PATH, "monster/stage01/left/");
    IMG_LOAD(L"monster/stage01/left/", buf);
    dynamic_cast<CMonster*>(m_pObj)->InsertImage(L"monster/stage01/left/", IMG_GET_V(L"monster/stage01/left/"));
    m_mImage    = &(m_pObj->GetImgv());

    sprintf_s(buf, "%s%s", IMG_PATH, "monster/stage01/left_broken/");
    IMG_LOAD(L"monster/stage01/left_broken/", buf);
    dynamic_cast<CMonster*>(m_pObj)->InsertImage(L"monster/stage01/left_broken/", IMG_GET_V(L"monster/stage01/left_broken/"));
    m_mImage    = &(m_pObj->GetImgv());

    sprintf_s(buf, "%s%s", IMG_PATH, "monster/stage01/sfx/test/");
    IMG_LOAD(L"monster/stage01/sfx/test/", buf);
    dynamic_cast<CMonster*>(m_pObj)->InsertImage(L"monster/stage01/sfx/test/", IMG_GET_V(L"monster/stage01/sfx/test/"));
    m_mImage    = &(m_pObj->GetImgv());

    sprintf_s(buf, "%s%s", IMG_PATH, "monster/stage01/sfx/e_start/");
    IMG_LOAD(L"monster/stage01/sfx/e_start/", buf);
    dynamic_cast<CMonster*>(m_pObj)->InsertImage(L"monster/stage01/sfx/e_start/", IMG_GET_V(L"monster/stage01/sfx/e_start/"));
    m_mImage    = &(m_pObj->GetImgv());

    sprintf_s(buf, "%s%s", IMG_PATH, "monster/stage01/sfx/kemuri/");
    IMG_LOAD(L"monster/stage01/sfx/kemuri/", buf);
    dynamic_cast<CMonster*>(m_pObj)->InsertImage(L"monster/stage01/sfx/kemuri/", IMG_GET_V(L"monster/stage01/sfx/kemuri/"));
    m_mImage    = &(m_pObj->GetImgv());

    dynamic_cast<CMonster*>(m_pObj)->InsertImage(L"sfx/explosion/", IMG_GET_V(L"sfx/explosion/"));
    m_mImage    = &(m_pObj->GetImgv());

    iter_begin  = m_mImage->find(L"monster/stage01/left/")          ->second->begin();
    iter_end    = m_mImage->find(L"monster/stage01/left/")          ->second->end();

    eff_begin   = m_mImage->find(L"monster/stage01/left_broken/")   ->second->begin();
    eff_end     = m_mImage->find(L"monster/stage01/left_broken/")   ->second->end();

    atk_begin   = m_mImage->find(L"monster/stage01/sfx/test/")      ->second->begin();
    atk_end     = m_mImage->find(L"monster/stage01/sfx/test/")      ->second->end();

    e_begin     = m_mImage->find(L"monster/stage01/sfx/e_start/")   ->second->begin();
    e_end       = m_mImage->find(L"monster/stage01/sfx/e_start/")   ->second->end();

    m_pObj->SetHp(15);
}

void CBossL::Render(HDC hdc)
{
    if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_STND)
        || STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_ATTK))
    {
        IMG_DRAW_I(hdc
            , (*iter_begin)->image
            , FLOAT(m_pObj->GetInfo().fX - (*iter_begin)->image->GetWidth() / 2.f)
            , FLOAT(m_pObj->GetInfo().fY - (*iter_begin)->image->GetHeight() / 2.f)
            , FLOAT((*iter_begin)->image->GetWidth())//m_pObj->GetInfo().rect.right
            , FLOAT((*iter_begin)->image->GetHeight())//m_pObj->GetInfo().rect.bottom
        );
    }

    Broken(hdc);

    if (eff_cnt < 1)
    {
        if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_STND))
        {
            IMG_DRAW_I(hdc
                , (*e_begin)->image
                , FLOAT(m_pObj->GetInfo().rect.left + 3)
                , FLOAT(m_pObj->GetInfo().rect.top + 37)
                , FLOAT((*e_begin)->image->GetWidth()) //m_pObj->GetInfo().rect.right
                , FLOAT((*e_begin)->image->GetHeight()) //m_pObj->GetInfo().rect.bottom
            );

            ++e_begin;

            if (e_begin == e_end)
            {
                e_begin = m_mImage->find(L"monster/stage01/sfx/e_start/")->second->begin() + 1;
            }
        }
    }
    
    if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_ATTK))
    {
        if (0 < m_pObj->GetInfo().iHP)
        {
            IMG_DRAW_I(hdc
                , (*atk_begin)->image
                , FLOAT(m_pObj->GetInfo().rect.left)
                , FLOAT(m_pObj->GetInfo().rect.top + 40)
                , FLOAT((*atk_begin)->image->GetWidth())//m_pObj->GetInfo().rect.right
                , FLOAT((*atk_begin)->image->GetHeight())//m_pObj->GetInfo().rect.bottom
            );

            ++atk_begin;
            if (atk_begin == m_mImage->find(L"monster/stage01/sfx/test/")->second->begin() + 33)
            {
                atk_begin = m_mImage->find(L"monster/stage01/sfx/test/")->second->begin() + 28;
            }
        }
    }
    //Rectangle(hdc, m_pObj->GetInfo().rect.left, m_pObj->GetInfo().rect.top, m_pObj->GetInfo().rect.right, m_pObj->GetInfo().rect.bottom);
}

void CBossL::Release()
{
}

int CBossL::Update()
{
    if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_DIE))
    {
        return 1;
    }
    rectMake();
    PatternA();
    return 0;
}

void CBossL::rectMake()
{
    if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_ATTK))
    {
        RECT rc = { 
            LONG(m_pObj->GetInfo().fX - 112)
            , LONG(m_pObj->GetInfo().fY)
            , LONG(m_pObj->GetInfo().fX - 112 + (*atk_begin)->image->GetWidth())
            , LONG(m_pObj->GetInfo().fY + 45 + (*atk_begin)->image->GetHeight())
        };
        m_pObj->SetRect(rc);
    }
    else
    {
        RECT rc = { LONG(m_pObj->GetInfo().fX - 112), LONG(m_pObj->GetInfo().fY), LONG(m_pObj->GetInfo().fX - 68), LONG(m_pObj->GetInfo().fY + 45) };
        m_pObj->SetRect(rc);
    }
}

void CBossL::PatternA()
{
    if (FLOAT(m_pObj->GetInfo().iMaxHp * 0.4f) < FLOAT(m_pObj->GetInfo().iHP) && FLOAT(m_pObj->GetInfo().iHP) <= FLOAT(m_pObj->GetInfo().iMaxHp * 0.7f))
    {
        iter_begin = m_mImage->find(L"monster/stage01/left/")->second->begin() + 1;
    }
    if (FLOAT(m_pObj->GetInfo().iMaxHp * 0.0f) < FLOAT(m_pObj->GetInfo().iHP) && FLOAT(m_pObj->GetInfo().iHP) <= FLOAT(m_pObj->GetInfo().iMaxHp * 0.4f))
    {
        iter_begin = m_mImage->find(L"monster/stage01/left/")->second->begin() + 2;
    }
}

void CBossL::Broken(HDC hdc)
{
    if (m_pObj->GetInfo().iHP <= 0)
    {
        if (eff_cnt < 1)
        {
            IMG_DRAW_I(hdc
                , (*eff_begin)->image
                , FLOAT(m_pObj->GetInfo().fX - (*eff_begin)->image->GetWidth() / 2.f) // + (m_pObj->GetInfo().rect.right - m_pObj->GetInfo().rect.left) / 2.f
                , FLOAT(m_pObj->GetInfo().fY - (*eff_begin)->image->GetHeight() / 2.f)//  + (m_pObj->GetInfo().rect.bottom - m_pObj->GetInfo().rect.top) / 2.f
                , FLOAT((*eff_begin)->image->GetWidth())//m_pObj->GetInfo().rect.right
                , FLOAT((*eff_begin)->image->GetHeight())//m_pObj->GetInfo().rect.bottom
            );

            ++eff_begin;
            if (eff_begin == eff_end)
            {
                ++eff_cnt;
                eff_begin = m_mImage->find(L"monster/stage01/left_broken/")->second->begin();
            }
        }
    }
}