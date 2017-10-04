#include "stdafx.h"
#include "StateContext.h"
#include "StateManager.h"
#include "Object.h"


StateContext::StateContext()
{
}


StateContext::~StateContext()
{
}

void StateContext::SetObj(Object * obj)
{
    if (m_pObj)
    {
        delete m_pObj;
    }
    m_pObj = obj;
}

void StateContext::SetState(StateManager * state)
{
    if (m_pState)
    {
        if (m_pState->isD())
        {
            delete m_pState;
            m_pState = state;
            m_pState->SetObj(m_pObj);
        }            
        else
        {
            delete state;
        }
    }
    else
    {
        m_pState = state;
        m_pState->SetObj(m_pObj);
    }
}

void StateContext::request(HDC hdc)
{
    m_pState->handle(hdc);
}
