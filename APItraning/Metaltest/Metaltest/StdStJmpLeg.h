#pragma once
#include "StateManager.h"
class StdStJmpLeg :
    public StateManager
{
public:
    StdStJmpLeg();
    ~StdStJmpLeg();

    // StateManager을(를) 통해 상속됨
    virtual void handle(HDC) override;
    virtual void handlf(HDC) override;
};

