#pragma once
#include "StateManager.h"

class CJmpLegR
    : public CStateManager
{
public:
    CJmpLegR();
    virtual ~CJmpLegR();

public:
    // CStateManager��(��) ���� ��ӵ�
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
};