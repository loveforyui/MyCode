#pragma once
#include "StateManager.h"
class EriStJmpBody :
    public StateManager
{
public:
    EriStJmpBody();
    virtual ~EriStJmpBody();

    // StateManager을(를) 통해 상속됨
    virtual void handle(HDC) override;
};

