#pragma once
#include "StateManager.h"

class CJmpLegL
    : public CStateManager
{
public:
    CJmpLegL();
    virtual ~CJmpLegL();

public:
    // CStateManager을(를) 통해 상속됨
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
};
