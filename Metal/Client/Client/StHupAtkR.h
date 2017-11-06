#pragma once
#include "StateManager.h"

class CStHupAtkR
    : public CStateManager
{
public:
    CStHupAtkR();
    virtual ~CStHupAtkR();

public:
    // CStateManager을(를) 통해 상속됨
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
    virtual int Update();
};