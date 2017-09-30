#pragma once
class StateManager;
class CObj;
class StateContext
{
public:
    StateContext();
    ~StateContext();
public:
    void SetObj(CObj*);
    void SetState(StateManager* state);
    void request();
private:
    StateManager*   m_pState;
    CObj*           m_pObj;
};

