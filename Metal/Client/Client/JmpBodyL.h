#pragma once
#include "StateManager.h"

class CJmpBodyL
    : public CStateManager
{
public:
    CJmpBodyL();
    virtual ~CJmpBodyL();

public:
    // CStateManager��(��) ���� ��ӵ�
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
};
