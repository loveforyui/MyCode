#pragma once
#include "StateManager.h"
class FioStJmpBody :
    public StateManager
{
public:
    FioStJmpBody();
    ~FioStJmpBody();

    // StateManager을(를) 통해 상속됨
    virtual void handle(HDC) override;
    virtual void handlf(HDC) override;
};

