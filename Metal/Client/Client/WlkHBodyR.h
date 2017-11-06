#pragma once

#include "StateManager.h"

class CWlkHBodyR
    : public CStateManager
{
public:
    CWlkHBodyR();
    virtual ~CWlkHBodyR();

public:
    // CStateManager을(를) 통해 상속됨
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
};