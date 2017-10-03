#pragma once
#include "Object.h"
class player :
    public Object
{
public:
    player();
    virtual ~player();

    // Object��(��) ���� ��ӵ�
    virtual void    Initialize();
    virtual void    Initialize(OBJINFO&);
    virtual void    Render(HDC);
    virtual void    Release();
    virtual int     Update();
private:
    INT m_iState_body;
    INT m_iState_leg;

    BOOL isDEBUG;
};

