#pragma once
#include "StateManager.h"
class EriStJmpLeg :
    public StateManager
{
public:
    EriStJmpLeg();
    virtual ~EriStJmpLeg();

    // StateManager��(��) ���� ��ӵ�
    virtual void handle(HDC) override;

    // StateManager��(��) ���� ��ӵ�
    virtual void handlf(HDC) override;
};

