#ifndef __statecontext_h__
#define __statecontext_h__

class StateManager;
class Object;
class StateContext
{
public:
    StateContext();
    ~StateContext();

public:
    void SetObj(Object*);
    void SetState(StateManager*);
    void request(HDC);
    StateManager* SetState(string);

private:
    StateManager*   m_pState;
    Object*         m_pObj;

public:
    map<string, StateManager*> m_mState;
};

#endif // !__statecontext_h__