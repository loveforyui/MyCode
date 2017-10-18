#include "stdafx.h"
#include "Gravity.h"
#include "Object.h"
#include "player.h"


Gravity::Gravity()
{
}


Gravity::~Gravity()
{

}

void Gravity::addObject(Object * obj)
{
    m_vObjlst.push_back(obj);
}

void Gravity::Update()
{
    //점프 스테이터스인 애들 죄다 적용
    for (vector<Object*>::iterator iter = m_vObjlst.begin();
        iter != m_vObjlst.end(); ++iter)
    {
        if (OBJ_A_JMP & (*iter)->GetPrevState())
        {
            FLOAT x, y, bot;
            x = (*iter)->GetInfo().fX;
            y = (*iter)->GetInfo().fY;
            bot = (*iter)->GetInfo().rect.bottom;

            bot += (*iter)->GetInfo().vSpeed + y;
            y   += (*iter)->GetInfo().vSpeed + 0.5f*m_GRAVITY;

            //if ((*m_pLine)[INT(x)] <= bot)
            //{
            //    if (bot <= ((*m_pLine)[INT(x)] + m_GRAVITY))
            //    {
            //        FLOAT tempY = (*iter)->GetInfo().fY + (*m_pLine)[INT(x)] - (*iter)->GetInfo().rect.bottom;
            //        (*iter)->SetPos(x, tempY);
            //        (*iter)->SetStanding();
            //    }
            //}
            //else
            //{
            //    //(*iter)->SetPos(x, y);
            //    //(*iter)->Set
            //}
        }

        /*FLOAT x, y;
        x = (*iter)->GetInfo().fX;
        y = (*iter)->GetInfo().fY;

        y += m_GRAVITY;
        (*iter)->SetPos(x, y);*/
    }
}

void Gravity::SetLine(vector<INT>* ptr)
{
    m_pLine = ptr;
}
