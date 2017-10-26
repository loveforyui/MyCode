#include "stdafx.h"
#include "StUpAtkBodyR.h"

CStUpAtkBodyR::CStUpAtkBodyR()
{
}

CStUpAtkBodyR::~CStUpAtkBodyR()
{
}

void CStUpAtkBodyR::initialize()
{
}

void CStUpAtkBodyR::handle(HDC hdc)
{
    if (m_vImage)
    {
        for (OBJITER obj = m_pObjLst->begin()
            ; obj != m_pObjLst->end(); ++obj)
        {
            IMG_DRAW_I(
                hdc
                , (*iter_begin)->image //(*iter_begin)->image
                , -0 + (*obj)->GetInfo().fX - (*iter_begin)->image->GetWidth() / 2
                , -30 + (*obj)->GetInfo().fY - (*iter_begin)->image->GetHeight() / 2
                , (*iter_begin)->image->GetWidth()
                , (*iter_begin)->image->GetHeight()
            );
        }

        ++iter_begin;
        if (iter_begin == iter_end)
            iter_begin = m_vImage->begin();
    }
}
