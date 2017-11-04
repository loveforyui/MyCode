#pragma once
#include "StateManager.h"

class CSitdownMoveR
    : public CStateManager
{
public:
    CSitdownMoveR();
    virtual ~CSitdownMoveR();

public:
    // CStateManager을(를) 통해 상속됨
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
    virtual int  Update();
};