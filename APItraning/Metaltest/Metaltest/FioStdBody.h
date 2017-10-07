#pragma once
#include "StateManager.h"
class FioStdBody :
    public StateManager
{
public:
    FioStdBody();
    ~FioStdBody();

    // StateManager을(를) 통해 상속됨
    virtual void handle(HDC) override;
    virtual void handlf(HDC) override;
};

