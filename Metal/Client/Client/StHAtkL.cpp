#include "stdafx.h"
#include "StHAtkL.h"

CStHAtkL::CStHAtkL()
{
}

CStHAtkL::~CStHAtkL()
{
}

void CStHAtkL::initialize()
{
}

void CStHAtkL::handle(HDC hdc)
{
    if (m_vImage)
    {
        for (OBJITER obj = m_pObjLst->begin()
            ; obj != m_pObjLst->end(); ++obj)
        {
            IMG_DRAW_I(
                hdc
                , (*iter_begin)->image //(*iter_begin)->image
                , -28 + (*obj)->GetInfo().fX - (*iter_begin)->image->GetWidth() / 2
                , -5 + (*obj)->GetInfo().fY - (*iter_begin)->image->GetHeight() / 2
                , FLOAT((*iter_begin)->image->GetWidth())
                , FLOAT((*iter_begin)->image->GetHeight())
            );
        }

        ++iter_begin;
        if (iter_begin == iter_end)
            iter_begin = m_vImage->begin();
    }
}

int CStHAtkL::Update()
{
    if (KEY_PRESSING(VK_LCONTROL))
    {
        //iter_begin = (m_vImage->begin()) + 5;
    }
    return 0;
}
