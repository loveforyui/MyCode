#pragma once

#include "StateManager.h"

class CStHBodyL
    : public CStateManager
{
public:
    CStHBodyL();
    virtual ~CStHBodyL();

public:
    // CStateManager��(��) ���� ��ӵ�
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
};