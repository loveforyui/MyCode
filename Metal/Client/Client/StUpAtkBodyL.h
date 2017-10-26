#pragma once
#include "StateManager.h"

class CStUpAtkBodyL
    : public CStateManager
{
public:
    CStUpAtkBodyL();
    virtual ~CStUpAtkBodyL();
public:
    // CStateManager을(를) 통해 상속됨
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
};