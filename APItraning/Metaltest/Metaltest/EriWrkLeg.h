#pragma once
#include "StateManager.h"
class EriWrkLeg :
    public StateManager
{
public:
    EriWrkLeg();
    ~EriWrkLeg();

    // StateManager��(��) ���� ��ӵ�
    virtual void handle(HDC) override;
};

