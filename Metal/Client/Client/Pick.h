#pragma once

#include "StateManager.h"

class CPick
    : public CStateManager
{
public:
    CPick();
    virtual ~CPick();

public:
    // CStateManager��(��) ���� ��ӵ�
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
};