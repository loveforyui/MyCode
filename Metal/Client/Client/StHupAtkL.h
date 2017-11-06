#pragma once
#include "StateManager.h"

class CStHupAtkL
    : public CStateManager
{
public:
    CStHupAtkL();
    virtual ~CStHupAtkL();

public:
    // CStateManager을(를) 통해 상속됨
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
    virtual int Update();
};