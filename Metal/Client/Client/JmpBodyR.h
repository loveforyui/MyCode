#pragma once
#include "StateManager.h"

class CJmpBodyR
    : public CStateManager
{
public:
    CJmpBodyR();
    virtual ~CJmpBodyR();

public:
    // CStateManager��(��) ���� ��ӵ�
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
};