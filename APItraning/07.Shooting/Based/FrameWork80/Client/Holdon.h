#pragma once
#include "CObj.h"
class Holdon :
    public CObj
{
public:
    Holdon();
    ~Holdon();

    // CObj��(��) ���� ��ӵ�
    virtual void    Initialize();
    virtual void    Initialize(INFO, FLOAT);
    virtual void    Render(HDC);
    virtual void    Release();
    virtual int     Update();
};

