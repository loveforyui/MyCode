#pragma once
#include "StateManager.h"

class CStAtkBodyL
    : public CStateManager
{
public:
    CStAtkBodyL();
    virtual ~CStAtkBodyL();

public:
    // CStateManager��(��) ���� ��ӵ�
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
};