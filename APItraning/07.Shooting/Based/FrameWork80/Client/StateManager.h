#pragma once
class Cobj;
class StateManager
{
public:
    StateManager();
    virtual ~StateManager();
public:
    virtual void Handle() = 0;
    void SetObj(CObj* obj) { m_pObj = obj; }

protected:
    CObj*       m_pObj;
    OBJSTATES   m_eState;
};

