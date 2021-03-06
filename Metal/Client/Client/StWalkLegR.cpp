#include "stdafx.h"
#include "StWalkLegR.h"


CStWalkLegR::CStWalkLegR()
{
}

CStWalkLegR::~CStWalkLegR()
{
}

void CStWalkLegR::initialize()
{
}

void CStWalkLegR::handle(HDC hdc)
{
    if (m_vImage)
    {
        for (OBJITER obj = m_pObjLst->begin()
            ; obj != m_pObjLst->end(); ++obj)
        {
            IMG_DRAW_I(
                hdc
                , (*iter_begin)->image //(*iter_begin)->image
                , -8 + (*obj)->GetInfo().fX - (*iter_begin)->image->GetWidth() / 2
                , 7 + (*obj)->GetInfo().fY - (*iter_begin)->image->GetHeight() / 2
                , (*iter_begin)->image->GetWidth()  //(*iter_begin)->image->GetWidth()
                , (*iter_begin)->image->GetHeight() //(*iter_begin)->image->GetHeight()
            );
        }
    }
}
int CStWalkLegR::Update()
{
    if (KEY_PRESSING(VK_RIGHT))
    {
        ++iter_begin;
        if (iter_begin == iter_end)
            iter_begin = m_vImage->begin();
    }
    return 0;
}