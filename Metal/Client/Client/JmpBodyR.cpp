#include "stdafx.h"
#include "JmpBodyR.h"

CJmpBodyR::CJmpBodyR()
{
}

CJmpBodyR::~CJmpBodyR()
{
}

void CJmpBodyR::initialize()
{
}

void CJmpBodyR::handle(HDC hdc)
{
    if (m_vImage)
    {
        for (OBJITER obj = m_pObjLst->begin()
            ; obj != m_pObjLst->end(); ++obj)
        {
            IMG_DRAW_I(
                hdc
                , (*iter_begin)->image //(*iter_begin)->image
                , -5 + (*obj)->GetInfo().fX - (*iter_begin)->image->GetWidth() / 2
                , -10 + (*obj)->GetInfo().fY - (*iter_begin)->image->GetHeight() / 2
                , (*obj)->GetInfo().fCX //(*iter_begin)->image->GetWidth()
                , (*obj)->GetInfo().fCY //(*iter_begin)->image->GetHeight()
            );
        }

        ++iter_begin;
        if (iter_begin == iter_end)
            iter_begin = --m_vImage->end();
    }
}
