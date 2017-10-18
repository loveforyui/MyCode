#include "stdafx.h"
#include "StdLeg.h"
#include "Obj.h"

CStdLeg::CStdLeg()
{
}

CStdLeg::~CStdLeg()
{
}

void CStdLeg::handle(HDC hdc)
{
    if (m_vImage)
    {
        for (vector<ObjImg*>::iterator iter = m_vImage->begin()
            ; iter != m_vImage->end(); ++iter)
        {
            for (OBJITER obj = m_pObjLst->begin()
                ; obj != m_pObjLst->end() ; ++obj)
            {
                IMG_DRAW_I(
                    hdc
                    , (*iter)->image
                    , (*obj)->GetInfo().fX
                    , (*obj)->GetInfo().fY
                    , (*obj)->GetInfo().fCX
                    , (*obj)->GetInfo().fCY);
            }
        }
    }
}

void CStdLeg::initialize()
{
}
