#pragma once

#include "StateManager.h"

class CWlkHBodyR
    : public CStateManager
{
public:
    CWlkHBodyR();
    virtual ~CWlkHBodyR();

public:
    // CStateManager��(��) ���� ��ӵ�
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
};