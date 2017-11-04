#include "stdafx.h"
#include "SamBdoor.h"
#include "Monster.h"

CSamBdoor::CSamBdoor()
{
}

CSamBdoor::~CSamBdoor()
{
}

void CSamBdoor::Init()
{
    char buf[256] = "";
    sprintf_s(buf, "%s%s", IMG_PATH, "monster/sam/b_door/");
    IMG_LOAD(L"monster/sam/b_door/", buf);
    dynamic_cast<CMonster*>(m_pObj)->InsertImage(L"monster/sam/b_door/", IMG_GET_V(L"monster/sam/b_door/"));
    m_mImage    = &(m_pObj->GetImgv());

    iter_begin  = m_mImage->find(L"monster/sam/b_door/")->second->begin();
    iter_end    = m_mImage->find(L"monster/sam/b_door/")->second->end();

}

void CSamBdoor::Render(HDC hdc)
{
    if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_STND))
    {
        IMG_DRAW_I(hdc
                , (*iter_begin)->image
                , 10 + FLOAT(m_pObj->GetInfo().fX - (*iter_begin)->image->GetWidth() / 2.f)
                , -20 + FLOAT(m_pObj->GetInfo().fY - (*iter_begin)->image->GetHeight() / 2.f)
                , FLOAT((*iter_begin)->image->GetWidth() * multiple)//m_pObj->GetInfo().rect.right
                , FLOAT((*iter_begin)->image->GetHeight() * multiple)//m_pObj->GetInfo().rect.bottom
            );
        ++iter_begin;
        if (iter_begin == iter_end)
        {
            iter_begin = m_mImage->find(L"monster/sam/b_door/")->second->begin();
            ++end;
        }
    }
}

void CSamBdoor::Release()
{
}

int CSamBdoor::Update()
{
    if (4 <= end)
        return 1;
    else
    {
        POINT pt = CPattern::GetInstance()->AngleLine(m_pObj, m_pObj->GetInfo().fAngle);
        m_pObj->SetPos(float(pt.x), float(pt.y));
        multiple += 0.2f;
    }

    return 0;
}
