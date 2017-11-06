#include "stdafx.h"
#include "StHjmpBodyR.h"

CStHjmpBodyR::CStHjmpBodyR()
{
}

CStHjmpBodyR::~CStHjmpBodyR()
{
}

void CStHjmpBodyR::initialize()
{
}

void CStHjmpBodyR::handle(HDC hdc)
{
    if (m_vImage)
    {
        for (OBJITER obj = m_pObjLst->begin()
            ; obj != m_pObjLst->end(); ++obj)
        {
            IMG_DRAW_I(
                hdc
                , (*iter_begin)->image
                , (*obj)->GetInfo().fX - (*iter_begin)->image->GetWidth() / 2
                , -8 + (*obj)->GetInfo().fY - (*iter_begin)->image->GetHeight() / 2
                , FLOAT((*iter_begin)->image->GetWidth())
                , FLOAT((*iter_begin)->image->GetHeight())
            );
        }

        ++iter_begin;
        if (iter_begin == iter_end)
        {
            iter_begin = (m_vImage->end()) - 1;
        }
    }
}
int CStHjmpBodyR::Update()
{
    if (KEY_UP(VK_SPACE))
    {
        iter_begin = (m_vImage->begin());
    }
    return 0;
}