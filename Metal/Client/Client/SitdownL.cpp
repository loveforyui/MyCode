#include "stdafx.h"
#include "SitdownL.h"

CSitdownL::CSitdownL()
{
}

CSitdownL::~CSitdownL()
{
}

void CSitdownL::initialize()
{
}

void CSitdownL::handle(HDC hdc)
{
    if (m_vImage)
    {
        for (OBJITER obj = m_pObjLst->begin()
            ; obj != m_pObjLst->end(); ++obj)
        {
            IMG_DRAW_I(
                hdc
                , (*iter_begin)->image //(*iter_begin)->image
                , -14 + (*obj)->GetInfo().fX - (*iter_begin)->image->GetWidth() / 2
                , -2 +(*obj)->GetInfo().fY - (*iter_begin)->image->GetHeight() / 2
                , FLOAT((*iter_begin)->image->GetWidth())
                , FLOAT((*iter_begin)->image->GetHeight())
            );
        }

        ++iter_begin;
        if (iter_begin == iter_end)
            iter_begin = m_vImage->end() - 1;
    }
}

int CSitdownL::Update()
{
    if (KEY_UP(VK_DOWN))
    {
        int state = m_pObjLst->back()->GetInfo().preState;
        if (STATE_SAME(m_pObjLst->back()->GetInfo().preState, OBJ_A_SITD))
            state ^= OBJ_A_SITD;

        m_pObjLst->back()->SetPreState(state);
        iter_begin = m_vImage->begin();
    }
    return 0;
}