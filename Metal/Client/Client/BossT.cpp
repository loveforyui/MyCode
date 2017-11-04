#include "stdafx.h"
#include "BossT.h"
#include "Monster.h"

CBossT::CBossT()
{
}

CBossT::~CBossT()
{
}

void CBossT::Init()
{
    char buf[256] = "";

    sprintf_s(buf, "%s%s", IMG_PATH, "monster/stage01/top/");
    IMG_LOAD(L"monster/stage01/top/", buf);
    dynamic_cast<CMonster*>(m_pObj)->InsertImage(L"monster/stage01/top/", IMG_GET_V(L"monster/stage01/top/"));
    m_mImage    = &(m_pObj->GetImgv());

    iter_begin  = m_mImage->find(L"monster/stage01/top/")->second->begin();
    iter_end    = m_mImage->find(L"monster/stage01/top/")->second->end();
}

void CBossT::Render(HDC hdc)
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
            iter_begin = m_mImage->find(L"monster/stage01/top/")->second->end() - 1;
            m_dwCurt = GetTickCount();
            MakeSoldier();
        }
    }
}

void CBossT::Release()
{
}

int CBossT::Update()
{
    if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_DIE))
    {
        return 1;
    }
    return 0;
}

void CBossT::MakeSoldier()
{
    if (m_dwOldt + 3000 < m_dwCurt)
    {
        m_dwOldt = m_dwCurt;

        INFO info;
        info.fX = m_pObj->GetInfo().fX + 40;
        info.fY = m_pObj->GetInfo().fY - 40;
        info.curState = OBJ_A_JUMP;
        info.m_eKind = eKMOB::MOB_K_BABA;
        info.fSpeed = 5.f;
        info.fAcc = 0.f;
        info.fJumpAcc = 10.f;

        CObjManager::GetInst()->AddObj(CAbstractFactory<CMonster>::CreateObj(info), OBJ_SUBMON);
    }
}