#pragma once

#include "StateManager.h"

class CBombBodyL
    : public CStateManager
{
public:
    CBombBodyL();
    virtual ~CBombBodyL();

public:
    // CStateManager��(��) ���� ��ӵ�
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
};