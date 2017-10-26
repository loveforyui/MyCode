#pragma once
#include "StateManager.h"

class CStAtkBodyL
    : public CStateManager
{
public:
    CStAtkBodyL();
    virtual ~CStAtkBodyL();

public:
    // CStateManager을(를) 통해 상속됨
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
};