#include "stdafx.h"
#include "StUpAtkBodyL.h"

CStUpAtkBodyL::CStUpAtkBodyL()
{
}

CStUpAtkBodyL::~CStUpAtkBodyL()
{
}

void CStUpAtkBodyL::initialize()
{
}

void CStUpAtkBodyL::handle(HDC hdc)
{
    if (m_vImage)
    {
        for (OBJITER obj = m_pObjLst->begin()
            ; obj != m_pObjLst->end(); ++obj)
        {
            IMG_DRAW_I(
                hdc
                , (*iter_begin)->image //(*iter_begin)->image
                , -13 + (*obj)->GetInfo().fX - (*iter_begin)->image->GetWidth() / 2
                , -30 + (*obj)->GetInfo().fY - (*iter_begin)->image->GetHeight() / 2
                , FLOAT((*iter_begin)->image->GetWidth())
                , FLOAT((*iter_begin)->image->GetHeight())
            );
        }
    }
}
int CStUpAtkBodyL::Update()
{
    if (KEY_PRESSING(VK_LCONTROL))
    {
        ++iter_begin;
        if (iter_begin == iter_end)
            iter_begin = (m_vImage->begin() + 1);
    }
    return 0;
}
