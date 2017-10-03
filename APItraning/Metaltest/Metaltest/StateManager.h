#ifndef __statemanager_h__
#define __statemanager_h__

class Object;
class StateManager
{
public:
    StateManager();
    virtual ~StateManager();

public:
    virtual void handle(HDC) = 0;
    void SetObj(Object* obj) { m_pObj = obj; }

protected:
    // DC
    HDC             m_hdc;
    //
    Object*         m_pObj;
    INT             m_iState;
    //
    vector<Image*>   m_vImage;
    vector<Image*>::iterator iter;
    BOOL            isRev;

    TCHAR*          m_path;
};

#endif // !__statemanager_h__