#pragma once
#include "StateManager.h"

class CSitdownMoveR
    : public CStateManager
{
public:
    CSitdownMoveR();
    virtual ~CSitdownMoveR();

public:
    // CStateManager��(��) ���� ��ӵ�
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
    virtual int  Update();
};