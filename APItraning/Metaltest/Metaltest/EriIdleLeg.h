#pragma once
#include "StateManager.h"
class EriIdleLeg :
    public StateManager
{
public:
    EriIdleLeg();
    virtual ~EriIdleLeg();

    // StateManager��(��) ���� ��ӵ�
    virtual void handle(HDC) override;

    // StateManager��(��) ���� ��ӵ�
    virtual void handlf(HDC) override;
};
