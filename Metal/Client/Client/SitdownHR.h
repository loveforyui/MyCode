#pragma once
#include "StateManager.h"

class CSitdownHR
    : public CStateManager
{
public:
    CSitdownHR();
    virtual ~CSitdownHR();

public:
    // CStateManager��(��) ���� ��ӵ�
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
    virtual int  Update();
};