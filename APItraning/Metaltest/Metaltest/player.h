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
    // �ѱ� ����
    FLOAT           m_fRadian;
    // ���ΰ� �̸�
    SHORT           m_iName;
    // ����� ���
    BOOL            isDEBUG;
    // �̹��� ����
    StateManager*   m_hState_leg;
    StateManager*   m_hState_body;
    // ���浹
    vector<INT>*    m_pLine;
    //
};

