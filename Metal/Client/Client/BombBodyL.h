#pragma once

#include "StateManager.h"

class CBombBodyL
    : public CStateManager
{
public:
    CBombBodyL();
    virtual ~CBombBodyL();

public:
    // CStateManager을(를) 통해 상속됨
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
};