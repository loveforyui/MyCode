#pragma once
#include "StateManager.h"
class StdLeg :
    public StateManager
{
public:
    StdLeg();
    ~StdLeg();

    // StateManager��(��) ���� ��ӵ�
    virtual void handle(HDC) override;
    virtual void handlf(HDC) override;
};

