#include "stdafx.h"
#include "StUpBodyR.h"

CStUpBodyR::CStUpBodyR()
{
}

CStUpBodyR::~CStUpBodyR()
{
}

void CStUpBodyR::initialize()
{
}

void CStUpBodyR::handle(HDC hdc)
{
    if (m_vImage)
    {
        for (OBJITER obj = m_pObjLst->begin()
            ; obj != m_pObjLst->end(); ++obj)
        {
            float fAngle = (*obj)->GetAngle();
            if (0 <= fAngle && fAngle <= 15)
            {
                iter_begin = (m_vImage->begin()) + 0;
            }
            else if (15 < fAngle && fAngle <= 30)
            {
                iter_begin = (m_vImage->begin()) + 1;
            }
            else if (30 < fAngle && fAngle <= 45)
            {
                iter_begin = (m_vImage->begin()) + 2;
            }
            else if (45 < fAngle && fAngle <= 60)
            {
                iter_begin = (m_vImage->begin()) + 3;
            }
            else if (60 < fAngle && fAngle <= 75)
            {
                iter_begin = (m_vImage->begin()) + 4;
            }
            else if (75 < fAngle && fAngle <= 90)
            {
                iter_begin = (m_vImage->begin()) + 5;
            }
            IMG_DRAW_I(
                hdc
                , (*iter_begin)->image //(*iter_begin)->image
                , -0 + (*obj)->GetInfo().fX - (*iter_begin)->image->GetWidth() / 2
                , 3 + (*obj)->GetInfo().fY - (*iter_begin)->image->GetHeight()
                , FLOAT((*iter_begin)->image->GetWidth())
                , FLOAT((*iter_begin)->image->GetHeight())
            );
        }
    }
}
