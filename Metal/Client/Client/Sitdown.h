#pragma once
#include "StateManager.h"

class CSitdown
    : public CStateManager
{
public:
    CSitdown();
    virtual ~CSitdown();

public:
    // CStateManager��(��) ���� ��ӵ�
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
    virtual int  Update();
};