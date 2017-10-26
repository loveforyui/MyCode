#pragma once
#include "StateManager.h"

class CStdLegLeft
    : public CStateManager
{
public:
    CStdLegLeft();
    virtual ~CStdLegLeft();
public:
    // CStateManager을(를) 통해 상속됨
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
};