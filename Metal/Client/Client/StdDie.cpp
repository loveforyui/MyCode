#include "stdafx.h"
#include "StdDie.h"

CStdDie::CStdDie()
{
}

CStdDie::~CStdDie()
{
}

void CStdDie::initialize()
{
}

void CStdDie::handle(HDC hdc)
{
    if (m_vImage)
    {
        for (OBJITER obj = m_pObjLst->begin()
            ; obj != m_pObjLst->end(); ++obj)
        {
            IMG_DRAW_I(
                hdc
                , (*iter_begin)->image
                , -10 + (*obj)->GetInfo().fX - (*iter_begin)->image->GetWidth() / 2
                , -5 + (*obj)->GetInfo().fY - (*iter_begin)->image->GetHeight() / 2
                , FLOAT((*iter_begin)->image->GetWidth())
                , FLOAT((*iter_begin)->image->GetHeight())
            );
        }

        ++iter_begin;
        if (iter_begin == iter_end)
        {
            iter_begin = (m_vImage->begin());
            OBJ_MGR_GETLIST(OBJ_PLAYER).back()->SetDead(false);
            OBJ_MGR_GETLIST(OBJ_PLAYER).back()->SetPreState(OBJ_A_STND);
        }
    }
}
