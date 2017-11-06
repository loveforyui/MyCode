#pragma once

#include "StateManager.h"

class CStHjmpBodyR
    : public CStateManager
{
public:
    CStHjmpBodyR();
    virtual ~CStHjmpBodyR();

public:
    // CStateManager을(를) 통해 상속됨
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
    virtual int  Update();
};