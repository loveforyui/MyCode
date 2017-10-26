#pragma once

#include "StateManager.h"
class CStWalkBodyL
    : public CStateManager
{
public:
    CStWalkBodyL();
    virtual ~CStWalkBodyL();

public:
    // CStateManager을(를) 통해 상속됨
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
};