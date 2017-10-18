#pragma once
#include "StateManager.h"

class CStdLeg :
    public CStateManager
{
public:
    CStdLeg();
    virtual ~CStdLeg();

public:
    // CStateManager을(를) 통해 상속됨
    virtual void handle(HDC hdc) override;

    // CStateManager을(를) 통해 상속됨
    virtual void initialize() override;
};