#ifndef __object_h__
#define __object_h__

#include "StateContext.h"

class Object
{
#pragma region Construct
public:
    Object();
    virtual ~Object();
#pragma endregion

#pragma region operator overload
public:
    BOOL            operator&&      (Object&);
    BOOL            operator||      (Object&);
#pragma endregion

#pragma region System Rutin
public:
    virtual void    Initialize      () = 0;
    virtual void    Initialize      (OBJINFO&) = 0;
    virtual void    Render          (HDC) = 0;
    virtual void    Release         () = 0;
    virtual int     Update          ();
#pragma endregion

#pragma region Getter & Setter
public:
    void            SetPos          (FLOAT, FLOAT);
    const OBJINFO&  GetInfo         ();

    const INT       GetStateLeg     ();
    const INT       GetStateBody    ();

    void            SetStateLeg     (const INT&);
    void            SetStateBody    (const INT&);

    void            SetStanding     ();

    SHORT           GetDirection    ();

    INT             GetCurrentState ();
    INT             GetPrevState    ();
#pragma endregion

#pragma region Member Var
protected:
    // 객체 정보
    OBJINFO         m_objInfo;
    // 상태정보(상체, 하체)
    StateContext    m_state_body;
    StateContext    m_state_leg;

    INT             m_iState_body;
    INT             m_iState_leg;

    INT             m_iPrevState;
    INT             m_iCurrState;

    SHORT           m_iDirection;

    BOOL            isKeyInput;
    BOOL            isJump;

#pragma endregion
};

#endif // !__object_h__