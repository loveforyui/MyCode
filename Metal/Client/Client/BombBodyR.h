#pragma once

#include "StateManager.h"

class CBombBodyR
    : public CStateManager
{
public:
    CBombBodyR();
    virtual ~CBombBodyR();

public:
    // CStateManager��(��) ���� ��ӵ�
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
};