#pragma once
#include "StateManager.h"
class EriWrkLeg :
    public StateManager
{
public:
    EriWrkLeg();
    ~EriWrkLeg();

    // StateManager을(를) 통해 상속됨
    virtual void handle(HDC) override;

    // StateManager을(를) 통해 상속됨
    virtual void handlf(HDC) override;
};

