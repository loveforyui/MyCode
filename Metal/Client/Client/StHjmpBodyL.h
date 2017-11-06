#pragma once

#include "StateManager.h"

class CStHjmpBodyL
    : public CStateManager
{
public:
    CStHjmpBodyL();
    virtual ~CStHjmpBodyL();

public:
    // CStateManager을(를) 통해 상속됨
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
    virtual int  Update();
};