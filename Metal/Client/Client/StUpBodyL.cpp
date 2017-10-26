#include "stdafx.h"
#include "StUpBodyL.h"

CStUpBodyL::CStUpBodyL()
{
}

CStUpBodyL::~CStUpBodyL()
{
}

void CStUpBodyL::initialize()
{
}

void CStUpBodyL::handle(HDC hdc)
{if (m_vImage)
    {
        for (OBJITER obj = m_pObjLst->begin()
            ; obj != m_pObjLst->end(); ++obj)
        {
            float fAngle = (*obj)->GetAngle();
            if (165 < fAngle && fAngle <= 180)
            {
                iter_begin = (m_vImage->begin()) + 0;
            }
            else if (150 < fAngle && fAngle <= 165)
            {
                iter_begin = (m_vImage->begin()) + 1;
            }
            else if (135 < fAngle && fAngle <= 150)
            {
                iter_begin = (m_vImage->begin()) + 2;
            }
            else if (120 < fAngle && fAngle <= 135)
            {
                iter_begin = (m_vImage->begin()) + 3;
            }
            else if (105 < fAngle && fAngle <= 120)
            {
                iter_begin = (m_vImage->begin()) + 4;
            }
            else if (90 <= fAngle && fAngle <= 105)
            {
                iter_begin = (m_vImage->begin()) + 5;
            }
            IMG_DRAW_I(
                hdc
                , (*iter_begin)->image //(*iter_begin)->image
                , -13 + (*obj)->GetInfo().fX - (*iter_begin)->image->GetWidth() / 2
                , 3 + (*obj)->GetInfo().fY - (*iter_begin)->image->GetHeight()
                , FLOAT((*iter_begin)->image->GetWidth())
                , FLOAT((*iter_begin)->image->GetHeight())
            );
        }
    }
}
