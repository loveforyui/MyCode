#pragma once
#include "StateManager.h"

class CStUpBodyL
    : public CStateManager
{
public:
    CStUpBodyL();
    virtual ~CStUpBodyL();

public:
    // CStateManager을(를) 통해 상속됨
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
};