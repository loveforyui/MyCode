#pragma once
#include "StateManager.h"
class FioWrkBody :
    public StateManager
{
public:
    FioWrkBody();
    ~FioWrkBody();

    // StateManager��(��) ���� ��ӵ�
    virtual void handle(HDC) override;
    virtual void handlf(HDC) override;
};

