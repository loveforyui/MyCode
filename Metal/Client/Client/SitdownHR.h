#pragma once
#include "StateManager.h"

class CSitdownHR
    : public CStateManager
{
public:
    CSitdownHR();
    virtual ~CSitdownHR();

public:
    // CStateManager을(를) 통해 상속됨
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
    virtual int  Update();
};