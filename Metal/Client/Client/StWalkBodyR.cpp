#include "stdafx.h"
#include "StWalkBodyR.h"

CStWalkBodyR::CStWalkBodyR()
{
}

CStWalkBodyR::~CStWalkBodyR()
{
}

void CStWalkBodyR::initialize()
{
}

void CStWalkBodyR::handle(HDC hdc)
{
    if (m_vImage)
    {
        for (OBJITER obj = m_pObjLst->begin()
            ; obj != m_pObjLst->end(); ++obj)
        {

            IMG_DRAW_I(
                hdc
                , (*iter_begin)->image //(*(m_vImage->back())).image //(*iter_begin)->image
                , 0 + (*obj)->GetInfo().fX - (*iter_begin)->image->GetWidth() / 2
                , 0 + (*obj)->GetInfo().fY - (*iter_begin)->image->GetHeight() / 2
                , (*iter_begin)->image->GetWidth()  //(*iter_begin)->image->GetWidth()
                , (*iter_begin)->image->GetHeight() //(*iter_begin)->image->GetHeight()
            );

        }

        ++iter_begin;
        if (iter_begin == iter_end)
            iter_begin = m_vImage->begin();
    }
}
