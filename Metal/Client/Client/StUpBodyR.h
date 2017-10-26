#pragma once
#include "StateManager.h"

class CStUpBodyR
    : public CStateManager
{
public:
    CStUpBodyR();
    virtual ~CStUpBodyR();
public:
    // CStateManager을(를) 통해 상속됨
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
};