#pragma once
#include "StateManager.h"
class Attack
    : public StateManager
{
public:
    Attack();
    ~Attack();

    // StateManager을(를) 통해 상속됨
    virtual void Handle() override;
};

