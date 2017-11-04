#pragma once
#include "StateManager.h"

class CSitdown
    : public CStateManager
{
public:
    CSitdown();
    virtual ~CSitdown();

public:
    // CStateManager을(를) 통해 상속됨
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
    virtual int  Update();
};