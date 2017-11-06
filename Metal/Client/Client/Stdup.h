#pragma once

#include "StateManager.h"

class CStdup
    : public CStateManager
{
public:
    CStdup();
    virtual ~CStdup();

public:
    // CStateManager을(를) 통해 상속됨
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
};