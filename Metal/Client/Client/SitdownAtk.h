#pragma once
#include "StateManager.h"

class CSitdownAtk
    : public CStateManager
{
public:
    CSitdownAtk();
    virtual ~CSitdownAtk();

public:
    // CStateManager��(��) ���� ��ӵ�
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
    virtual int  Update();
};