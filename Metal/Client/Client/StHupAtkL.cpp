#include "stdafx.h"
#include "StHupAtkL.h"

CStHupAtkL::CStHupAtkL()
{
}

CStHupAtkL::~CStHupAtkL()
{
}

void CStHupAtkL::initialize()
{
}

void CStHupAtkL::handle(HDC hdc)
{
    if (m_vImage)
    {
        for (OBJITER obj = m_pObjLst->begin()
            ; obj != m_pObjLst->end(); ++obj)
        {
            float fAngle = (*obj)->GetAngle();
            if (155 < fAngle && fAngle <= 180)
            {
                iter_begin = (m_vImage->begin()) + 0;
            }
            else if (130 < fAngle && fAngle <= 155)
            {
                iter_begin = (m_vImage->begin()) + 1;
            }
            else if (105 < fAngle && fAngle <= 130)
            {
                iter_begin = (m_vImage->begin()) + 2;
            }
            else if (90 < fAngle && fAngle <= 105)
            {
                iter_begin = (m_vImage->begin()) + 3;
            }
            IMG_DRAW_I(
                hdc
                , (*iter_begin)->image //(*iter_begin)->image
                , -24 + (*obj)->GetInfo().fX - (*iter_begin)->image->GetWidth() / 2
                , 3 + (*obj)->GetInfo().fY - (*iter_begin)->image->GetHeight()
                , FLOAT((*iter_begin)->image->GetWidth())
                , FLOAT((*iter_begin)->image->GetHeight())
            );
        }
    }
}

int CStHupAtkL::Update()
{
    if (KEY_UP(VK_LCONTROL))
    {
        int state = OBJ_MGR_GETLIST(OBJ_PLAYER).back()->GetInfo().preState;
        state ^= OBJ_A_ATTK;
        OBJ_MGR_GETLIST(OBJ_PLAYER).back()->SetPreState(state);
    }
    return 0;
}
