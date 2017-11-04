#pragma once
#include "StateManager.h"

class CSitdownAtk
    : public CStateManager
{
public:
    CSitdownAtk();
    virtual ~CSitdownAtk();

public:
    // CStateManager을(를) 통해 상속됨
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
    virtual int  Update();
};