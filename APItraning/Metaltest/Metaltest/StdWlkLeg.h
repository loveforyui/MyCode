#pragma once
#include "StateManager.h"
class StdWlkLeg :
    public StateManager
{
public:
    StdWlkLeg();
    ~StdWlkLeg();

    // StateManager��(��) ���� ��ӵ�
    virtual void handle(HDC) override;
    virtual void handlf(HDC) override;
};

