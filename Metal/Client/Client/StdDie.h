#pragma once

#include "StateManager.h"

class CStdDie
    : public CStateManager
{
public:
    CStdDie();
    virtual ~CStdDie();

public:
    // CStateManager��(��) ���� ��ӵ�
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
};