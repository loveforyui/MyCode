#pragma once
#include "StateManager.h"

class CSitdownHL
    : public CStateManager
{
public:
    CSitdownHL();
    virtual ~CSitdownHL();

public:
    // CStateManager��(��) ���� ��ӵ�
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
    virtual int  Update();
};