#pragma once
#include "StateManager.h"
class FioWrkBody :
    public StateManager
{
public:
    FioWrkBody();
    ~FioWrkBody();

    // StateManager을(를) 통해 상속됨
    virtual void handle(HDC) override;
    virtual void handlf(HDC) override;
};

