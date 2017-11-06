#pragma once

#include "StateManager.h"

class CWlkHBodyL
    : public CStateManager
{
public:
    CWlkHBodyL();
    virtual ~CWlkHBodyL();

public:
    // CStateManager을(를) 통해 상속됨
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
};