#include "stdafx.h"
#include "StHupAtkR.h"

CStHupAtkR::CStHupAtkR()
{
}

CStHupAtkR::~CStHupAtkR()
{
}

void CStHupAtkR::initialize()
{
}

void CStHupAtkR::handle(HDC hdc)
{
    if (m_vImage)
    {
       for (OBJITER obj = m_pObjLst->begin()
            ; obj != m_pObjLst->end(); ++obj)
        {
            float fAngle = (*obj)->GetAngle();
            if (0 <= fAngle && fAngle <= 25)
            {
                iter_begin = (m_vImage->begin()) + 0;
            }
            else if (25 < fAngle && fAngle <= 50)
            {
                iter_begin = (m_vImage->begin()) + 1;
            }
            else if (50 < fAngle && fAngle <= 75)
            {
                iter_begin = (m_vImage->begin()) + 2;
            }
            else if (75 < fAngle && fAngle < 90)
            {
                iter_begin = (m_vImage->begin()) + 3;
            }
            IMG_DRAW_I(
                hdc
                , (*iter_begin)->image //(*iter_begin)->image
                , 12 + (*obj)->GetInfo().fX - (*iter_begin)->image->GetWidth() / 2
                , 3 + (*obj)->GetInfo().fY - (*iter_begin)->image->GetHeight()
                , FLOAT((*iter_begin)->image->GetWidth())
                , FLOAT((*iter_begin)->image->GetHeight())
            );
        }
    }
}

int CStHupAtkR::Update()
{
    if (KEY_UP(VK_LCONTROL))
    {
        int state = OBJ_MGR_GETLIST(OBJ_PLAYER).back()->GetInfo().preState;
        state ^= OBJ_A_ATTK;
        OBJ_MGR_GETLIST(OBJ_PLAYER).back()->SetPreState(state);
    }
    return 0;
}
