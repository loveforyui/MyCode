#pragma once
#include "StateManager.h"

class CSitdownMoveL
    : public CStateManager
{
public:
    CSitdownMoveL();
    virtual ~CSitdownMoveL();

public:
    // CStateManager��(��) ���� ��ӵ�
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
    virtual int  Update();
};