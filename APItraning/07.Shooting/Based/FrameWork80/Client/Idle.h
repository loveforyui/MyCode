#pragma once
#include "StateManager.h"
class Idle :
    public StateManager
{
public:
    Idle();
    virtual ~Idle();

    // StateManager을(를) 통해 상속됨
    virtual void Handle() override;
};

