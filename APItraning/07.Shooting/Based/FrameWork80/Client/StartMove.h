#pragma once
#include "StateManager.h"
class StartMove :
    public StateManager
{
public:
    StartMove();
    virtual ~StartMove();

    // StateManager을(를) 통해 상속됨
    virtual void Handle() override;
};

