#pragma once
#include "StateManager.h"

class CSitdownAtkL
    : public CStateManager
{
public:
    CSitdownAtkL();
    virtual ~CSitdownAtkL();

public:
    // CStateManager��(��) ���� ��ӵ�
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
    virtual int  Update();
};