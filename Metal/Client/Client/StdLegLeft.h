#pragma once
#include "StateManager.h"

class CStdLegLeft
    : public CStateManager
{
public:
    CStdLegLeft();
    virtual ~CStdLegLeft();
public:
    // CStateManager��(��) ���� ��ӵ�
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
};