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
    virtual void handlf(HDC) = 0;
    void SetObj(Object* obj) { m_pObj = obj; }
    BOOL isD() { return isDone; }

protected:
    // DC
    HDC             m_hdc;
    //
    Object*         m_pObj;
    INT             m_iState;
    //
    vector<Image*>   m_vImage;
    vector<Image*>::iterator iter;
    
    vector<Image*>  m_vImagf;
    vector<Image*>::iterator itef;

    BOOL            isRev;
    BOOL            isRevf;
    //
    BOOL            isDone;
    //
    TCHAR*          m_path;
};

#endif // !__statemanager_h__