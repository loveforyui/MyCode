#pragma once

#include "StateManager.h"

class CWlkHBodyL
    : public CStateManager
{
public:
    CWlkHBodyL();
    virtual ~CWlkHBodyL();

public:
    // CStateManager��(��) ���� ��ӵ�
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
};