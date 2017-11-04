#pragma once

#include "StateManager.h"

class CBombBodyR
    : public CStateManager
{
public:
    CBombBodyR();
    virtual ~CBombBodyR();

public:
    // CStateManager을(를) 통해 상속됨
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
};