#pragma once

class CStateManager;

template <typename T>
class CAbstractState
{
public:
    static CStateManager* CreateState()
    {
        CStateManager* pState = new T;
        pState->initialize();

        return pState;
    }
    static CStateManager* CreateState(OBJID eId, vector<ObjImg*>* img)
    {
        CStateManager* pState = new T;
        pState->initialize();
        pState->SetObj(eId);
        pState->SetImage(img);

        return pState;
    }
};

#define MAKE_STATE(Eid, StateClass, vImg) CAbstractState<StateClass>::CreateState(Eid, vImg)