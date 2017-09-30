#pragma once
#include "StateManager.h"
class Ellised :
    public StateManager
{
public:
    Ellised();
    ~Ellised();

    // StateManager을(를) 통해 상속됨
    virtual void Handle() override;
};

