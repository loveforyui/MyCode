#include "stdafx.h"
#include "StAtkBodyL.h"

CStAtkBodyL::CStAtkBodyL()
{
}

CStAtkBodyL::~CStAtkBodyL()
{
}

void CStAtkBodyL::initialize()
{
}

void CStAtkBodyL::handle(HDC hdc)
{
    if (m_vImage)
    {
        for (OBJITER obj = m_pObjLst->begin()
            ; obj != m_pObjLst->end(); ++obj)
        {
            IMG_DRAW_I(
                hdc
                , (*iter_begin)->image //(*iter_begin)->image
                , -24 + (*obj)->GetInfo().fX - (*iter_begin)->image->GetWidth() / 2
                , -1 + (*obj)->GetInfo().fY - (*iter_begin)->image->GetHeight() / 2
                , FLOAT((*iter_begin)->image->GetWidth())
                , FLOAT((*iter_begin)->image->GetHeight())
            );
        }

        ++iter_begin;
        if (iter_begin == iter_end)
            iter_begin = m_vImage->begin() - m_incre;
    }
}

int CStAtkBodyL::Update()
{
    if (KEY_PRESSING(VK_LCONTROL))
    {
        iter_begin = (m_vImage->begin()) + 5;
    }
    return 0;
}
