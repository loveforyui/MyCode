#pragma once

class CObj;
class CStateContext
{
public:
    CStateContext();
    ~CStateContext();

public:
    void request(HDC hdc);

public:
    void AddState(const TCHAR* str, CStateManager* mgr);
    void SetState(const TCHAR* str);
    void SetState(const TCHAR * str, CStateManager * mgr);
    TCHAR* GetStateName() { return m_pChar; }
    CStateManager* GetState() { return m_pState; }

private:
    CStateManager*                      m_pState;
    TCHAR                               m_pChar[256];
    map<const TCHAR*, CStateManager*>   m_mState;
};