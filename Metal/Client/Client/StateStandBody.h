#pragma once
#include "StateManager.h"

class CStateStandBody :
    public CStateManager
{
public:
    CStateStandBody();
    virtual ~CStateStandBody();

public:
    // CStateManager��(��) ���� ��ӵ�
    virtual void handle(HDC hdc) override;

private:
    // CStateManager��(��) ���� ��ӵ�
    virtual void initialize() override;
};