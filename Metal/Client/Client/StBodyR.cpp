#include "stdafx.h"
#include "StBodyR.h"
#include "Obj.h"

CStBodyR::CStBodyR()
{
}

CStBodyR::~CStBodyR()
{
}

void CStBodyR::handle(HDC hdc)
{
    if (m_vImage)
    {
        for (OBJITER obj = m_pObjLst->begin()
            ; obj != m_pObjLst->end(); ++obj)
        {
            //wchar_t         pos[64];
            //swprintf_s(pos, L"X:%.2f Y:%.2f"
            //    , (*obj)->GetInfo().fX   - (*iter_begin)->image->GetWidth()/2
            //    , (*obj)->GetInfo().fY   - (*iter_begin)->image->GetHeight()/2);
            ////wsprintf();
            //SetTextAlign(hdc, TA_CENTER);
            //SetBkMode(hdc, TRANSPARENT);
            //TextOut(hdc
            //    , (*obj)->GetInfo().fX   - (*iter_begin)->image->GetWidth()/2
            //    , (*obj)->GetInfo().fY   - (*iter_begin)->image->GetHeight()/2 - 30
            //    , pos, wcslen(pos)
            //);

            /*Rectangle(
                hdc
                , (*obj)->GetInfo().fX - (*iter_begin)->image->GetWidth()/2
                , (*obj)->GetInfo().fY - (*iter_begin)->image->GetHeight()/2
                , (*obj)->GetInfo().fX + (*iter_begin)->image->GetWidth()/2
                , (*obj)->GetInfo().fY + (*iter_begin)->image->GetHeight()/2
            );*/

            IMG_DRAW_I(
                    hdc
                    , (*iter_begin)->image
                    , (*obj)->GetInfo().fX - (*iter_begin)->image->GetWidth()/2
                    , (*obj)->GetInfo().fY - (*iter_begin)->image->GetHeight()/2
                    , (*iter_begin)->image->GetWidth() //(*iter_begin)->image->GetWidth()
                    , (*iter_begin)->image->GetHeight() //(*iter_begin)->image->GetHeight()
            );
        }

        ++iter_begin;
        if (iter_begin == iter_end)
            iter_begin = m_vImage->begin();
            
        /*for (vector<ObjImg*>::iterator iter = m_vImage->begin()
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
        }*/
    }
}

void CStBodyR::initialize()
{

}
