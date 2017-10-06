#pragma once
#include "Object.h"
class player :
    public Object
{
public:
    player();
    virtual ~player();

public:
    // Object��(��) ���� ��ӵ�
    virtual void    Initialize();
    virtual void    Initialize(OBJINFO&);
    virtual void    Render(HDC);
    virtual void    Release();
    virtual int     Update();

public:
    void SetLine(vector<INT>*);

private:
    BOOL isDEBUG;
    
    StateManager* m_hState_leg;
    StateManager* m_hState_body;

    vector<INT>* m_pLine;
};

