#pragma once
#include "StateManager.h"
class StdStJmpLeg :
    public StateManager
{
public:
    StdStJmpLeg();
    ~StdStJmpLeg();

    // StateManager��(��) ���� ��ӵ�
    virtual void handle(HDC) override;
    virtual void handlf(HDC) override;
};

