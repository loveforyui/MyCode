#include "stdafx.h"
#include "BombBodyR.h"

CBombBodyR::CBombBodyR()
{
}

CBombBodyR::~CBombBodyR()
{
}

void CBombBodyR::initialize()
{
}

void CBombBodyR::handle(HDC hdc)
{
    if (m_vImage)
    {
        for (OBJITER obj = m_pObjLst->begin()
            ; obj != m_pObjLst->end(); ++obj)
        {
            IMG_DRAW_I(
                hdc
                , (*iter_begin)->image
                , -1 + (*obj)->GetInfo().fX - (*iter_begin)->image->GetWidth() / 2
                , -4 + (*obj)->GetInfo().fY - (*iter_begin)->image->GetHeight() / 2
                , FLOAT((*iter_begin)->image->GetWidth())
                , FLOAT((*iter_begin)->image->GetHeight())
            );
        }

        ++iter_begin;
        if (iter_begin == iter_end)
        {
            iter_begin = m_vImage->begin();
            OBJ_MGR_GETLIST(OBJ_PLAYER).back()->SetPreState(OBJ_MGR_GETLIST(OBJ_PLAYER).back()->GetInfo().preState ^ OBJ_A_BOMB);
        }
    }
}
