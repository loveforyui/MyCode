#pragma once
#include "StateManager.h"

class CSitdownL
    : public CStateManager
{
public:
    CSitdownL();
    virtual ~CSitdownL();

public:
    // CStateManager��(��) ���� ��ӵ�
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
    virtual int  Update();
};