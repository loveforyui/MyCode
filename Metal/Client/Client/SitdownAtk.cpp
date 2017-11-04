#include "stdafx.h"
#include "SitdownAtk.h"

CSitdownAtk::CSitdownAtk()
{
}

CSitdownAtk::~CSitdownAtk()
{
}

void CSitdownAtk::initialize()
{
}

void CSitdownAtk::handle(HDC hdc)
{
    if (m_vImage)
    {
        for (OBJITER obj = m_pObjLst->begin()
            ; obj != m_pObjLst->end(); ++obj)
        {
            IMG_DRAW_I(
                hdc
                , (*iter_begin)->image //(*iter_begin)->image
                , 10 + (*obj)->GetInfo().fX - (*iter_begin)->image->GetWidth() / 2
                , 3 + (*obj)->GetInfo().fY - (*iter_begin)->image->GetHeight() / 2
                , FLOAT((*iter_begin)->image->GetWidth())
                , FLOAT((*iter_begin)->image->GetHeight())
            );
        }

        ++iter_begin;
        if (iter_begin == iter_end)
            iter_begin = m_vImage->begin() - m_incre;
    }
}

int CSitdownAtk::Update()
{
    return 0;
}
