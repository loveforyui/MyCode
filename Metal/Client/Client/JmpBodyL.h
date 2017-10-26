#pragma once
#include "StateManager.h"

class CJmpBodyL
    : public CStateManager
{
public:
    CJmpBodyL();
    virtual ~CJmpBodyL();

public:
    // CStateManager을(를) 통해 상속됨
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
};
