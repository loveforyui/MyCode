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

private:
    CStateManager* m_pState;
    map<const TCHAR*, CStateManager*> m_mState;
};