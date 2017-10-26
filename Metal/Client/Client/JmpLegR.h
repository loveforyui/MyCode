#pragma once
#include "StateManager.h"

class CJmpLegR
    : public CStateManager
{
public:
    CJmpLegR();
    virtual ~CJmpLegR();

public:
    // CStateManager을(를) 통해 상속됨
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
};