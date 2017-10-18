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
    m_pState = m_mState.find(str)->second;
}
