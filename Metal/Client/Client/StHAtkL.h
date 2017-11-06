#pragma once
#include "StateManager.h"

class CStHAtkL
    : public CStateManager
{
public:
    CStHAtkL();
    virtual ~CStHAtkL();

public:
    // CStateManager을(를) 통해 상속됨
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
    virtual int Update();
};