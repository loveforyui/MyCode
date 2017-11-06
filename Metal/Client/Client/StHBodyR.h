#pragma once

#include "StateManager.h"

class CStHBodyR
    : public CStateManager
{
public:
    CStHBodyR();
    virtual ~CStHBodyR();

public:
    // CStateManager을(를) 통해 상속됨
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
};