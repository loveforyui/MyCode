#include "stdafx.h"
#include "JmpLegL.h"

CJmpLegL::CJmpLegL()
{
}

CJmpLegL::~CJmpLegL()
{
}

void CJmpLegL::initialize()
{
}

void CJmpLegL::handle(HDC hdc)
{
    if (m_vImage)
    {
        for (OBJITER obj = m_pObjLst->begin()
            ; obj != m_pObjLst->end(); ++obj)
        {
            IMG_DRAW_I(
                hdc
                , (*iter_begin)->image //(*iter_begin)->image
                , -6 + (*obj)->GetInfo().fX - (*iter_begin)->image->GetWidth() / 2
                , 2 + (*obj)->GetInfo().fY - (*iter_begin)->image->GetHeight() / 2
                , (*obj)->GetInfo().fCX //(*iter_begin)->image->GetWidth()
                , (*obj)->GetInfo().fCY //(*iter_begin)->image->GetHeight()
            );
        }

        ++iter_begin;
        if (iter_begin == iter_end)
            iter_begin = m_vImage->begin();
    }
}