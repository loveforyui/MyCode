#pragma once
#include "StateManager.h"
class Idle :
    public StateManager
{
public:
    Idle();
    virtual ~Idle();

    // StateManager��(��) ���� ��ӵ�
    virtual void Handle() override;
};

