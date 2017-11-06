#pragma once

#include "StateManager.h"

class CStHBodyL
    : public CStateManager
{
public:
    CStHBodyL();
    virtual ~CStHBodyL();

public:
    // CStateManager을(를) 통해 상속됨
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
};