#pragma once
#include "StateManager.h"
class EriWrkBody :
    public StateManager
{
public:
    EriWrkBody();
    ~EriWrkBody();

    // StateManager��(��) ���� ��ӵ�
    virtual void handle(HDC) override;

    // StateManager��(��) ���� ��ӵ�
    virtual void handlf(HDC) override;
};

