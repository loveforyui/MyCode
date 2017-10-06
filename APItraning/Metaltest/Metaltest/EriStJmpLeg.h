#pragma once
#include "StateManager.h"
class EriStJmpLeg :
    public StateManager
{
public:
    EriStJmpLeg();
    virtual ~EriStJmpLeg();

    // StateManager을(를) 통해 상속됨
    virtual void handle(HDC) override;

    // StateManager을(를) 통해 상속됨
    virtual void handlf(HDC) override;
};

