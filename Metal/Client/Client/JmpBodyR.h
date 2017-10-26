#pragma once
#include "StateManager.h"

class CJmpBodyR
    : public CStateManager
{
public:
    CJmpBodyR();
    virtual ~CJmpBodyR();

public:
    // CStateManager을(를) 통해 상속됨
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
};