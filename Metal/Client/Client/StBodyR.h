#pragma once
#include "StateManager.h"

class CStBodyR :
    public CStateManager
{
public:
    CStBodyR();
    virtual ~CStBodyR();

public:
    // CStateManager을(를) 통해 상속됨
    virtual void handle(HDC hdc) override;

private:
    // CStateManager을(를) 통해 상속됨
    virtual void initialize() override;
};