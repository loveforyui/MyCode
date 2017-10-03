#pragma once
#include "StateManager.h"
class EriIdleLeg :
    public StateManager
{
public:
    EriIdleLeg();
    virtual ~EriIdleLeg();

    // StateManager을(를) 통해 상속됨
    virtual void handle(HDC) override;
};

