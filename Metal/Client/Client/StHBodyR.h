#pragma once

#include "StateManager.h"

class CStHBodyR
    : public CStateManager
{
public:
    CStHBodyR();
    virtual ~CStHBodyR();

public:
    // CStateManager��(��) ���� ��ӵ�
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
};