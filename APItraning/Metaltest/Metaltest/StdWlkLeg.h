#pragma once
#include "StateManager.h"
class StdWlkLeg :
    public StateManager
{
public:
    StdWlkLeg();
    ~StdWlkLeg();

    // StateManager을(를) 통해 상속됨
    virtual void handle(HDC) override;
    virtual void handlf(HDC) override;
};

