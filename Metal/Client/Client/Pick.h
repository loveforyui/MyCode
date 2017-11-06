#pragma once

#include "StateManager.h"

class CPick
    : public CStateManager
{
public:
    CPick();
    virtual ~CPick();

public:
    // CStateManager을(를) 통해 상속됨
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
};