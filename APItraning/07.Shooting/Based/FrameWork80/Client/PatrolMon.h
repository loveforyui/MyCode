#pragma once
#include "CObj.h"
class PatrolMon :
    public CObj
{
public:
    PatrolMon();
    virtual ~PatrolMon();

    // CObj��(��) ���� ��ӵ�
    virtual void    Initialize  ();
    virtual void    Initialize  (INFO, FLOAT);
    virtual void    Render      (HDC);
    virtual void    Release     ();
    virtual int     Update      ();
};

