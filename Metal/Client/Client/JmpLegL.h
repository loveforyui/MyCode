#pragma once
#include "StateManager.h"

class CJmpLegL
    : public CStateManager
{
public:
    CJmpLegL();
    virtual ~CJmpLegL();

public:
    // CStateManager��(��) ���� ��ӵ�
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
};
