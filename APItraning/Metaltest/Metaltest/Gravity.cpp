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
        if (    PS_LEG_ST_JMP == (*iter)->GetStateLeg()
            ||  PS_BODY_ST_JMP == (*iter)->GetStateBody())
        {
            FLOAT x, y;
            x = (*iter)->GetInfo().fX;
            y = (*iter)->GetInfo().fY;
            
            y += m_GRAVITY;
            (*iter)->SetPos(x, y);
        }
    }
}