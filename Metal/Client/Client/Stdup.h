#pragma once

#include "StateManager.h"

class CStdup
    : public CStateManager
{
public:
    CStdup();
    virtual ~CStdup();

public:
    // CStateManager��(��) ���� ��ӵ�
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
};