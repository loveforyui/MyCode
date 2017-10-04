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
    BOOL isDEBUG;
    
    StateManager* m_hState_leg;
    StateManager* m_hState_body;
};

