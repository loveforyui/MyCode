#pragma once
#include "StateManager.h"
class Attack
    : public StateManager
{
public:
    Attack();
    ~Attack();

    // StateManager��(��) ���� ��ӵ�
    virtual void Handle() override;
};

