#pragma once
#include "StateManager.h"

class CStWalkLegL
    : public CStateManager
{
public:
    CStWalkLegL();
    virtual ~CStWalkLegL();

public:
    // CStateManager을(를) 통해 상속됨
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
};