#ifndef __object_h__
#define __object_h__

#include "StateContext.h"

class Object
{
public:
    Object();
    virtual ~Object();

public:
    BOOL operator&&(Object&);
    BOOL operator||(Object&);


public:
    virtual void    Initialize  () = 0;
    virtual void    Initialize  (OBJINFO&) = 0;
    virtual void    Render      (HDC) = 0;
    virtual void    Release     () = 0;
    virtual int     Update      ();

public:
    void SetPos(FLOAT, FLOAT);
    const OBJINFO& GetInfo();

    const INT GetStateLeg();
    const INT GetStateBody();

    void SetStateLeg(const INT&);
    void SetStateBody(const INT&);

    void SetStanding();

protected:
    OBJINFO m_objInfo;

    StateContext m_state_body;
    StateContext m_state_leg;

    INT m_iState_body;
    INT m_iState_leg;

    SHORT m_iDirection;

    BOOL isKeyInput;
    BOOL isJump;
};

#endif // !__object_h__