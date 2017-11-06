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
            float fAngle = (*obj)->GetAngle();

            if (150 < fAngle && fAngle <= 180)
            {
                iter_begin = (m_vImage->begin()) + 0;
            }
            else if (120 < fAngle && fAngle <= 150)
            {
                iter_begin = (m_vImage->begin()) + 1;
            }


            else if (90 < fAngle && fAngle <= 120)
            {
                iter_begin = (m_vImage->begin()) + 2;
            }
            else if (85 <= fAngle && fAngle <= 120)
            {
                iter_begin = (m_vImage->begin()) + 3;
            }

            IMG_DRAW_I(
                hdc
                , (*iter_begin)->image //(*iter_begin)->image
                , -14 + (*obj)->GetInfo().fX - (*iter_begin)->image->GetWidth() / 2
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
