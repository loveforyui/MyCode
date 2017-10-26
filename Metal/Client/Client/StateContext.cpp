#include "stdafx.h"
#include "StateContext.h"

CStateContext::CStateContext()
{
}

CStateContext::~CStateContext()
{
}

void CStateContext::request(HDC hdc)
{
    m_pState->handle(hdc);
}

void CStateContext::AddState(const TCHAR* str, CStateManager * mgr)
{
    m_mState.insert(pair<const TCHAR*, CStateManager*>(str, mgr));
}

void CStateContext::SetState(const TCHAR * str)
{
    CStateManager* tempState = m_mState.find(str)->second;

    if (!lstrcmp(m_pChar, str))
    {
        return;
    }
    else
    {
        m_pState = tempState;
        wcscpy_s(m_pChar, str);
    }   
}
void CStateContext::SetState(const TCHAR * str, CStateManager * mgr)
{
    CStateManager* tempState = m_mState.find(str)->second;

    if (!lstrcmp(m_pChar, str))
    {
        SafeDelete<CStateManager*>(tempState);
        m_mState.find(str)->second = mgr;

        m_pState = m_mState.find(str)->second;
        wcscpy_s(m_pChar, str);
    }
    else
    {
        m_pState = tempState;
        wcscpy_s(m_pChar, str);
    }   
}
