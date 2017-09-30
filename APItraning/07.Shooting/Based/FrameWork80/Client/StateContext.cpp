#include "stdafx.h"
#include "StateContext.h"
#include "StateManager.h"
#include "CObj.h"


StateContext::StateContext()
{
}

StateContext::~StateContext()
{
}

void StateContext::SetObj(CObj * obj)
{
    if (m_pObj)
        delete m_pObj;

    m_pObj = obj;
}

void StateContext::SetState(StateManager * state)
{
    if (m_pState)
        delete m_pState;

    m_pState = state;
    m_pState->SetObj(m_pObj);
}

void StateContext::request()
{
    m_pState->Handle();
}
