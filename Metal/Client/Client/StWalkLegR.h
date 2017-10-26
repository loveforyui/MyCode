#pragma once
#include "StateManager.h"

class CStWalkLegR
    : public CStateManager
{
public:
    CStWalkLegR();
    virtual ~CStWalkLegR();

public:
    // CStateManager을(를) 통해 상속됨
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
};
