#pragma once
#include "StateManager.h"

class CStBodyL
    : public CStateManager
{
public:
    CStBodyL();
    ~CStBodyL();
public:
    // CStateManager��(��) ���� ��ӵ�
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
};