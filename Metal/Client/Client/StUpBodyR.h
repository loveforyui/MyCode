#pragma once
#include "StateManager.h"

class CStUpBodyR
    : public CStateManager
{
public:
    CStUpBodyR();
    virtual ~CStUpBodyR();
public:
    // CStateManager��(��) ���� ��ӵ�
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
};