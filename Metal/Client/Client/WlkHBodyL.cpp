#include "stdafx.h"
#include "WlkHBodyL.h"

CWlkHBodyL::CWlkHBodyL()
{
}

CWlkHBodyL::~CWlkHBodyL()
{
}

void CWlkHBodyL::initialize()
{
}

void CWlkHBodyL::handle(HDC hdc)
{
    if (m_vImage)
    {
        for (OBJITER obj = m_pObjLst->begin()
            ; obj != m_pObjLst->end(); ++obj)
        {
            IMG_DRAW_I(
                hdc
                , (*iter_begin)->image
                , -18 + (*obj)->GetInfo().fX - (*iter_begin)->image->GetWidth() / 2
                , -4 + (*obj)->GetInfo().fY - (*iter_begin)->image->GetHeight() / 2
                , FLOAT((*iter_begin)->image->GetWidth())
                , FLOAT((*iter_begin)->image->GetHeight())
            );
        }

        ++iter_begin;
        if (iter_begin == iter_end)
        {
            iter_begin = (m_vImage->begin());
        }
    }
}
