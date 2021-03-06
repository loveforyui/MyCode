#pragma once

#include "StateManager.h"

class CStdDie
    : public CStateManager
{
public:
    CStdDie();
    virtual ~CStdDie();

public:
    // CStateManager을(를) 통해 상속됨
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
};